#pragma once


// CStudyDlgTabPage3 对话框

class CStudyDlgTabPage3 : public CDialogEx
{
	DECLARE_DYNAMIC(CStudyDlgTabPage3)

public:
	CStudyDlgTabPage3(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStudyDlgTabPage3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDY1_P3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
