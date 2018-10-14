#pragma once


// CStudyDlgTabPage2 对话框

class CStudyDlgTabPage2 : public CDialogEx
{
	DECLARE_DYNAMIC(CStudyDlgTabPage2)

public:
	CStudyDlgTabPage2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStudyDlgTabPage2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDY1_P2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
