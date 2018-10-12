
// DirectionDetect.h : DirectionDetect 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


#pragma warning(disable:4819) 

// CDirectionDetectApp:
// 有关此类的实现，请参阅 DirectionDetect.cpp
//

class CDirectionDetectApp : public CWinAppEx
{
public:
	CDirectionDetectApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

	////菜单栏、工具栏事件响应函数
	//afx_msg void OnFileOpen();
	////开始检测
	//afx_msg void OnCmdStart();					
	////停止检测
	//afx_msg void OnCmdStop();					
	////打开学习对话框
	//afx_msg void OnEditStudy();					
};

extern CDirectionDetectApp theApp;
