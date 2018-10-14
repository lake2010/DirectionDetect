#pragma once


// CStudyDlg 对话框

class CStudyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStudyDlg)

public:
	CStudyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStudyDlg();
private:
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	LONG64 m_hStudyDlgWindowID;								//学习界面halcon window ID


	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedOpenPic();
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnOK();
};
