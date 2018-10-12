/******************************************************************************
Module:  Logger.h

Purpose: 记录程序日志。
		1. 把日志信息输出到指定文件
		2. 对于 GUI 程序，可以把日志信息发送到指定窗口
		3. 对于Console应用程序，可以把日志信息发往标准输出 (std::cout)

Desc:
		1、功能：
		--------------------------------------------------------------------------------------
		a) 把日志信息输出到指定文件
		b) 每日生成一个日志文件
		c) 对于 GUI 程序，可以把日志信息发送到指定窗口
		d) 对于Console应用程序，可以把日志信息发往标准输出 (std::cout)
		e) 支持 MBCS / UNICODE，Console / GUI，win32 / x64 程序
		f) 支持动态加载和静态加载日志组件 DLL
		g) 支持 DEBUG/TRACE/INFO/WARN/ERROR/FATAL 等多个日志级别
		
		2、可用性：
		--------------------------------------------------------------------------------------
		a) 简单纯净：不依赖任何程序库或框架
		b) 使用接口简单，不需复杂的配置或设置工作
		c) 提供 CStaticLogger 和 CDynamicLogger 包装类用于静态或动态加载以及操作日志组件，用户无需关注加载细节
		d) 程序如果要记录多个日志文件只需为每个日志文件创建相应的 CStaticLogger 或 CDynamicLogger 对象
		e) 只需调用 Log()/Debug()/Trace()/Info()/Warn()/Error()/Fatal() 等方法记录日志
		f) 日志记录方法支持可变参数
		g) 日志输出格式：<时间> <线程ID> <日志级别> <日志内容>
		
		3、性能：
		--------------------------------------------------------------------------------------
		a) 支持多线程同时发送写日志请求
		b) 使用单独线程在后台写日志，不影响工作线程的正常执行
		c) 采用批处理方式批量记录日志

Usage:
		方法一：（静态加载 Logger DLL）
		--------------------------------------------------------------------------------------
		0. 应用程序包含 StaticLogger.h 头文件
		1. 创建 CStaticLogger 对象（通常为全局对象）
		2. 调用 CStaticLogger->Init(...) 初始化日志组件
		3. 使用 CStaticLogger->Log()/Debug()/Trace()/Info()/Warn()/Error()/Fatal() 等方法写日志
		4. 调用 CStaticLogger->UnInit(...) 清理日志组件（CStaticLogger 对象析构时也会自动清理日志组件）

		方法二：（动态加载 Logger DLL）
		--------------------------------------------------------------------------------------
		0. 应用程序包含 DynamicLogger.h 头文件
		1. 创建 CDynamicLogger 对象（通常为全局对象）
		2. 调用 CDynamicLogger->Init(...) 初始化日志组件
		3. 使用 CDynamicLogger->Log()/Debug()/Trace()/Info()/Warn()/Error()/Fatal() 等方法写日志
		4. 调用 CDynamicLogger->UnInit(...) 清理日志组件（CDynamicLogger 对象析构时也会自动清理日志组件）

		方法三：（直接用导出函数加载 Logger DLL）
		--------------------------------------------------------------------------------------
		0. 应用程序包含 Logger.h 头文件
		1. 手工调用 ILoger_Create() 和 ILoger_Create() 导出函数创建和销毁 ILogger 对象 
		（注：如果是动态加载，需手工调用 ::LoadLibrary()/::FreeLibrary() 系列 API 函数加载和卸载 Logger DLL）
		
		[
			***** 对于希望通过窗口接收日志信息的 GUI 程序 *****

			A. 日志组件初始化成功后调用 SetGUIWindow(HWND) 设置收日志的窗口
			B. 窗口须响应处理 LOG_MESSAGE 消息
			C. 处理完 LOG_MESSAGE 消息后，调用 ILogger::FreeLogMsg() 销毁接收到的 TLogMsg 
		]

Environment:
		1. Windows 2000 or later (_WIN32_WINNT >= 0x0500)
		2. VC++ 2010 or later

Release:
		1. Logger_C.dll		- Console/MBCS/Release
		2. Logger_CD.dll	- Console/MBCS/Debug	//经过2018/9/26测试，此库64位情况下出现应用程序无法正常启动（0xc000007b)
		3. Logger_CU.dll	- Console/Unicode/Release
		4. Logger_CUD.dll	- Console/Unicode/Debug
		5. Logger.dll		- GUI/MBCS/Release
		6. Logger_D.dll		- GUI/MBCS/Debug
		7. Logger_U.dll		- GUI/Unicode/Release
		8. Logger_UD.dll	- GUI/Unicode/Debug

Examples:
		1. TestGUILogger		- GUI 版测试程序		（静态加载）
		2. TestDynamicLogger	- GUI 版测试程序		（动态加载）
		3. TestConsoleLogger	- Console 版测试程序	（静态加载）

******************************************************************************/

#pragma once

/**************************************************/
/********** imports / exports Logger.dll **********/

#ifdef LOGGER_EXPORTS
	#define LOGGER_API __declspec(dllexport)
	//#define TRY_INLINE	inline
#else
	#define LOGGER_API __declspec(dllimport)
	//#define TRY_INLINE
#endif

/**************************************************/
/****************** 日志组件接口 *******************/

class LOGGER_API ILogger
{
public:
	/***** 日志级别 *****/
	enum LogLevel
	{
		LL_NONE		= 0XFF,
		LL_DEBUG	= 1,
		LL_TRACE	= 2,
		LL_INFO		= 3,
		LL_WARN		= 4,
		LL_ERROR	= 5,
		LL_FATAL	= 6
	};

	/***** 操作错误码 *****/
	enum ErrorCode
	{
		// 无错误
		EC_OK	= NO_ERROR,
		// 文件操作相关的错误
		EC_FILE_GENERIC,
		EC_FILE_FILENOTFOUND,
		EC_FILE_BADPATH,
		EC_FILE_TOMANYOPERFILES,
		EC_FILE_ACCESSDENIED,
		EC_FILE_INVALIDFILE,
		EC_FILE_REMOVECURRENTDIR,
		EC_FILE_DIRECTORYFULL,
		EC_FILE_BADSEEK,
		EC_FILE_HARDIO,
		EC_FILE_SHARINGVIOLATION,
		EC_FILE_LOCKVIOLATION,
		EC_FILE_DISKFULL,
		EC_FILE_ENDOFFILE,
		// 其他错误
		EC_INVALID_STATE,
		EC_INIT_LOGLEVEL,
		EC_INIT_PRINTFLAG,
		EC_INIT_CREATE_LOG_THREAD_FAIL
	};

	/******************************************
					日志信息结构
	*******************************************/
	struct TLogMsg
	{
		DWORD		m_dwSize;		// 结构大小 - 跟据消息长度动态变化
		LogLevel	m_logLevel;		// 日志级别
		UINT		m_uiThreadID;	// 线程ID
		SYSTEMTIME	m_stMsgTime;	// 记录时间
		TCHAR		m_psMsg[1];		// 消息内容
	};

public:
	ILogger(void);
	virtual ~ILogger(void);
private:
	ILogger(const ILogger&);
	ILogger& operator = (const ILogger&);

public:
	// 日志组件初始化方法
	virtual BOOL Init(
						LPCTSTR logFile	= NULL					// 日志文件. 默认: {AppPath}/logs/{AppName}-YYYYMMDD.log
					  , LogLevel ll		= DEFAULT_LOG_LEVEL		// 日志级别. 默认: [Debug -> LL_DEBUG] / [Release -> LL_INFO]
					  , int printFlag	= DEFAULT_PRINT_FLAG	// 输出掩码. 是否输出到文件和(或)屏幕. 默认: 只输出到文件
					 )		= 0;
	// 日志组件清理方法
	virtual BOOL UnInit()	= 0;

public:
	// 写日志方法：传入日志内容字符串（对于不需要格式化的日志文本，用本方法效率最高）
	virtual void Log_0	(LogLevel ll, LPCTSTR msg) = 0;
	virtual void Debug_0(LPCTSTR msg);
	virtual void Trace_0(LPCTSTR msg);
	virtual void Info_0	(LPCTSTR msg);
	virtual void Warn_0	(LPCTSTR msg);
	virtual void Error_0(LPCTSTR msg);
	virtual void Fatal_0(LPCTSTR msg);

	// 写日志方法：传入格式化字符串和参数栈指针（通常只在组件内部使用）
	virtual void LogV	(LogLevel ll, LPCTSTR format, va_list arg_ptr);

	// 写日志方法：传入格式化字符串和可变参数（非常灵活简便）
	virtual void Log	(LogLevel ll, LPCTSTR format, ...);
	virtual void Debug	(LPCTSTR format, ...);
	virtual void Trace	(LPCTSTR format, ...);
	virtual void Info	(LPCTSTR format, ...);
	virtual void Warn	(LPCTSTR format, ...);
	virtual void Error	(LPCTSTR format, ...);
	virtual void Fatal	(LPCTSTR format, ...);

	// 写日志方法：传入格式化字符串和可变参数（与上一组方法类似，但在进行任何操作前会检查日志级别）
	virtual void TryLog		(LogLevel ll, LPCTSTR format, ...);
	virtual void TryDebug	(LPCTSTR format, ...);
	virtual void TryTrace	(LPCTSTR format, ...);
	virtual void TryInfo	(LPCTSTR format, ...);
	virtual void TryWarn	(LPCTSTR format, ...);
	virtual void TryError	(LPCTSTR format, ...);
	virtual void TryFatal	(LPCTSTR format, ...);

	// 通用辅助方法
	virtual BOOL HasInited			()		const	= 0;		// 是否已经初始化							
	virtual BOOL IsPrint2File		()		const	= 0;		// 是否把日志输出到文件	
	virtual BOOL IsPrint2Screen		()		const	= 0;		// 是否把日志输出到屏幕窗口	
	virtual int	GetPrintFlag		()		const	= 0;		// 打印标志					
	virtual LogLevel	GetLogLevel	()		const	= 0;		// 日志级别		
	virtual LPCTSTR		GetLogFile	()		const	= 0;		// 日志文件
	virtual ErrorCode	GetLastError()		const	= 0;		// 当前操作错误码

/****************************** GUI ******************************/
#ifdef _WINDOWS
	public:
		// 设置接收日志信息的窗口, hWndGUI == NULL 则取消接收
		virtual void SetGUIWindow(HWND hWndGUI)	= 0;
		// 获取接收日志信息的窗口
		virtual HWND GetGUIWindow()				= 0;

		// 销毁在发送 LOG_MESSAGE 消息时动态创建的 TLogMsg 对象
		virtual void FreeLogMsg(const TLogMsg* pLogMsg);

		// 虚拟窗口句柄标掩码：用于向 GUI 窗口发送 LOG_MESSAGE 消息时作为发送源标识
		static const int LOGGER_FAKE_WINDOW_BASE = 0X80001111;
		// 自定义日志消息：通过本消息向 GUI 窗口发送日志
		// 其中：WPARAM -> ILogger 对象指针，LPARAM -> TLogMsg 结构体指针
		static const int LOG_MESSAGE = WM_USER | (0x7FFF & LOGGER_FAKE_WINDOW_BASE);
#endif

public:
	static const int PRINT_FLAG_FILE			= 0x00000001;			// 打印到文件
	static const int PRINT_FLAG_SCREEN			= 0x00000002;			// 打印到屏幕
	static const int DEFAULT_PRINT_FLAG			= PRINT_FLAG_FILE;		// 默认日志掩码
	static const LogLevel DEFAULT_LOG_LEVEL		= 
#ifdef _DEBUG
				LL_DEBUG
#else
				LL_INFO
#endif
				;
};

/**************************************************/
/************** Logger DLL 导出函数 ***************/

// 创建 ILogger 对象
EXTERN_C LOGGER_API ILogger* ILogger_Create();
// 销毁 ILogger 对象
EXTERN_C LOGGER_API void ILogger_Destroy(ILogger* p);

// 获取各日志级别的文字描述
EXTERN_C LOGGER_API LPCTSTR	ILogger_GetLogLevelDesc	(ILogger::LogLevel ll);
// 获取各操作错误码的文字描述
EXTERN_C LOGGER_API LPCTSTR	ILogger_GetErrorDesc	(ILogger::ErrorCode ec);
