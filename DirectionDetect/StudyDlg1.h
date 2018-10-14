#pragma once
#include "afxcmn.h"
#include "StudyDlgTabPage0.h"
#include "StudyDlgTabPage1.h"
#include "StudyDlgTabPage2.h"
#include "StudyDlgTabPage3.h"
#include "StudyDlgTabPage4.h"
// CStudyDlg1 对话框

class CStudyDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CStudyDlg1)

public:
	CStudyDlg1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStudyDlg1();




public:
	CTabCtrl m_studyTab;
	CStudyDlgTabPage0 m_tabPage0;
	CStudyDlgTabPage1 m_tabPage1;
	CStudyDlgTabPage2 m_tabPage2;
	CStudyDlgTabPage3 m_tabPage3;
	CStudyDlgTabPage4 m_tabPage4;
	
private:
	LONG64 m_hStudyDlgWindowID;								//学习界面halcon window ID



// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDY1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeStudyTab(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOpenPic();
};
