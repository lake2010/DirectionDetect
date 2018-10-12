/*
//*************************************************
//-----------------LZH添加备忘录--------------------
//----------------日志系统添加流程--------------------
//------------（静态加载 Logger DLL）---------------
//		下载log system dll-lib-h		github链接：
//		应用程序包含 StaticLogger.h 头文件,属性添加附加包含目录
//		添加动态库导出文件lib（动态加载无需此文件）   ①常规中-添加附加库目录  ②输入中-添加附加依赖项 Logger_CU.lib 或者 #pragma comment(lib, "path//Logger_CU.lib")
//		指定与lib文件同名动态库Logger_CU.dll路径方法
//			①移动动态库到执行文件相同目录下
//			②移动动态库到系统目录下
//			③项目属性中设置工作目录or环境变量
//
//		创建 CStaticLogger 对象（通常为全局对象）
//		调用 CStaticLogger->Init(...) 初始化日志组件
//		使用 CStaticLogger->Log() / Debug() / Trace() / Info() / Warn() / Error() / Fatal() 等方法写日志
//		调用 CStaticLogger->UnInit(...) 清理日志组件（CStaticLogger 对象析构时也会自动清理日志组件）
//
//		Logger.h中内容细看
//*************************************************
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

/************************************************/
/********** ILogger 包装器（智能指针） ***********/
/*********** 用于静态加载 Logger DLL ************/

class LOGGER_API CStaticLogger
{
public:
	// 构造函数：如果 bCreate 为 TRUE，则在构建 CStaticLogger 实例的同时创建 ILogger 对象
	CStaticLogger(BOOL bCreate = TRUE);
	// 析构函数
	~CStaticLogger();
private:
	CStaticLogger(const CStaticLogger&);
	CStaticLogger& operator = (const CStaticLogger&);

public:
	inline void Reset			(ILogger* pLogger);	// 重设其封装的 ILogger 指针
	inline BOOL IsValid			()	const;			// 判断其封装的 ILogger 指针是否非空
	inline ILogger* Get			()	const;			// 获取 ILogger 指针
	inline ILogger& operator *	()	const;			// 获取 ILogger 引用
	inline ILogger* operator ->	()	const;			// 获取 ILogger 指针
	inline operator ILogger*	()	const;			// 转换为 ILogger 指针

private:
	ILogger* m_pLogger;
};
