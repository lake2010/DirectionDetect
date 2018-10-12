/*
 * Copyright Bruce Liang (ldcsaa@gmail.com)
 *
 * Version	: 2.0.3
 * Author	: Bruce Liang
 * Website	: http://www.jessma.org
 * Project	: https://github.com/ldcsaa
 * Blog		: http://www.cnblogs.com/ldcsaa
 * WeiBo	: http://weibo.com/u/1402935851
 * QQ Group	: 75375912
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "Logger.h"

/**************************************************/
/************* Logger DLL 默认文件名 ***************/

#ifdef _DEBUG
	#ifdef _UNICODE
		#ifdef _WINDOWS
			#define DEF_LOGGER_DLL_FILE_PATH	_T("Logger_UD.dll")
		#else
			#define DEF_LOGGER_DLL_FILE_PATH	_T("Logger_CUD.dll")
		#endif
	#else
		#ifdef _WINDOWS
			#define DEF_LOGGER_DLL_FILE_PATH	_T("Logger_D.dll")
		#else
			#define DEF_LOGGER_DLL_FILE_PATH	_T("Logger_CD.dll")
		#endif
	#endif
#else
	#ifdef _UNICODE
		#ifdef _WINDOWS
		#define DEF_LOGGER_DLL_FILE_PATH	_T("Logger_U.dll")
		#else
			#define DEF_LOGGER_DLL_FILE_PATH	_T("Logger_CU.dll")
		#endif
	#else
		#ifdef _WINDOWS
			#define DEF_LOGGER_DLL_FILE_PATH	_T("Logger.dll")
		#else
			#define DEF_LOGGER_DLL_FILE_PATH	_T("Logger_C.dll")
		#endif
	#endif
#endif

/**************************************************/
/*************** Logger DLL 导出函数 ***************/

// 创建 ILogger 对象
typedef ILogger*			(*FN_ILogger_Create)			();
// 销毁 ILogger 对象
typedef void				(*FN_ILogger_Destroy)			(ILogger* p);
// 获取各日志级别的文字描述
typedef LPCTSTR				(*FN_ILogger_GetLogLevelDesc)	(ILogger::LogLevel ll);
// 获取各操作错误码的文字描述
typedef LPCTSTR				(*FN_ILogger_GetErrorDesc)		(ILogger::ErrorCode ec);

/*************************************************/
/********** ILogger 包装器（智能指针） ***********/
/************ 用于动态加载 Logger DLL ************/

class CDynamicLogger
{
public:
	// 构造函数：如果 bLoad 为 TRUE，则在构建 CDynamicLogger 示例的同时创建 ILogger 对象
	CDynamicLogger(BOOL bLoad = TRUE, LPCTSTR lpszFilePath = DEF_LOGGER_DLL_FILE_PATH)
	{
		Reset();

		if(bLoad)
			Load(lpszFilePath);
	}

	// 析构函数
	~CDynamicLogger()
	{
		Free();
	}

private:
	CDynamicLogger(const CDynamicLogger&);
	CDynamicLogger& operator = (const CDynamicLogger&);

public:
	// 创建 ILogger 对象
	ILogger* ILogger_Create()
		{return m_fnILoggerCreate();}
	// 销毁 ILogger 对象
	void ILogger_Destroy(ILogger* p)
		{m_fnILoggerDestroy(p);}
	// 获取各日志级别的文字描述
	LPCTSTR	ILogger_GetLogLevelDesc(ILogger::LogLevel ll)
		{return m_fnILoggerGetLogLevelDesc(ll);}
	// 获取各操作错误码的文字描述
	LPCTSTR	ILogger_GetErrorDesc(ILogger::ErrorCode ec)
		{return m_fnILoggerGetErrorDesc(ec);}

	// 加载 Logger DLL
	BOOL Load(LPCTSTR lpszFilePath = DEF_LOGGER_DLL_FILE_PATH)
	{
		if(IsValid())
			return FALSE;

		BOOL isOK = FALSE;
		m_hLogger = ::LoadLibrary(lpszFilePath);

		if(m_hLogger)
		{
			m_fnILoggerCreate			= (FN_ILogger_Create)			::GetProcAddress(m_hLogger, "ILogger_Create");
			m_fnILoggerDestroy			= (FN_ILogger_Destroy)			::GetProcAddress(m_hLogger, "ILogger_Destroy");
			m_fnILoggerGetLogLevelDesc	= (FN_ILogger_GetLogLevelDesc)	::GetProcAddress(m_hLogger, "ILogger_GetLogLevelDesc");
			m_fnILoggerGetErrorDesc		= (FN_ILogger_GetErrorDesc)		::GetProcAddress(m_hLogger, "ILogger_GetErrorDesc");

			if(m_fnILoggerCreate && m_fnILoggerDestroy)
			{
				m_pLogger	= ILogger_Create();
				isOK		= (m_pLogger != NULL);
			}
		}

		if(!isOK)
			Free();

		return isOK;
	}

	// 卸载 Logger DLL
	BOOL Free()
	{
		if(!IsValid())
			return TRUE;

		BOOL isOK = TRUE;

		if(m_pLogger)	ILogger_Destroy(m_pLogger);
		if(m_hLogger)	isOK = ::FreeLibrary(m_hLogger);

		Reset();

		return isOK;
	}

	BOOL IsValid			()	const	{return m_pLogger != NULL;}	// 判断其封装的 ILogger 指针是否非空
	ILogger* Get			()	const	{return m_pLogger;}			// 获取 ILogger 指针
	ILogger& operator *		()	const	{return *m_pLogger;}		// 获取 ILogger 引用
	ILogger* operator ->	()	const	{return m_pLogger;}			// 获取 ILogger 指针
	operator ILogger*		()	const	{return m_pLogger;}			// 转换为 ILogger 指针

private:
	void Reset()
	{
		m_hLogger					= NULL;
		m_pLogger					= NULL;
		m_fnILoggerCreate			= NULL;
		m_fnILoggerDestroy			= NULL;
		m_fnILoggerGetLogLevelDesc	= NULL;
		m_fnILoggerGetErrorDesc		= NULL;
	}

private:
	HMODULE			m_hLogger;
	ILogger*		m_pLogger;

	FN_ILogger_Create			m_fnILoggerCreate;
	FN_ILogger_Destroy			m_fnILoggerDestroy;
	FN_ILogger_GetLogLevelDesc	m_fnILoggerGetLogLevelDesc;
	FN_ILogger_GetErrorDesc		m_fnILoggerGetErrorDesc;
};
