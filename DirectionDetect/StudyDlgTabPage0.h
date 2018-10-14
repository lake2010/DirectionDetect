#pragma once
#include "afxwin.h"


// CStudyDlgTabPage0 对话框

class CStudyDlgTabPage0 : public CDialogEx
{
	DECLARE_DYNAMIC(CStudyDlgTabPage0)

public:
	CStudyDlgTabPage0(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStudyDlgTabPage0();


public:
	CComboBox m_CameraAcquisitionMode;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDY1_P0 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
