
// DirectionDetect.h : DirectionDetect Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CDirectionDetectApp:
// �йش����ʵ�֣������ DirectionDetect.cpp
//

class CDirectionDetectApp : public CWinAppEx
{
public:
	CDirectionDetectApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

	//�˵������������¼���Ӧ����
	afx_msg void OnFileOpen();
	afx_msg void OnCmdStart();					//��ʼ���
	afx_msg void OnCmdStop();					//ֹͣ���
	afx_msg void OnEditStudy();					//��ѧϰ�Ի���
};

extern CDirectionDetectApp theApp;
