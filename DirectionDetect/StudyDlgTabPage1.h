#pragma once


// CStudyDlgTabPage1 对话框

class CStudyDlgTabPage1 : public CDialogEx
{
	DECLARE_DYNAMIC(CStudyDlgTabPage1)

public:
	CStudyDlgTabPage1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStudyDlgTabPage1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDY1_P1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
