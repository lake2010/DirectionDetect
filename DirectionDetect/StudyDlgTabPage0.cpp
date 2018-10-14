// StudyDlgTabPage0.cpp : 实现文件
//

#include "stdafx.h"
#include "DirectionDetect.h"
#include "StudyDlgTabPage0.h"
#include "afxdialogex.h"


// CStudyDlgTabPage0 对话框

IMPLEMENT_DYNAMIC(CStudyDlgTabPage0, CDialogEx)

CStudyDlgTabPage0::CStudyDlgTabPage0(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_STUDY1_P0, pParent)
{

}

CStudyDlgTabPage0::~CStudyDlgTabPage0()
{
}

void CStudyDlgTabPage0::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_CameraAcquisitionMode);
}


BEGIN_MESSAGE_MAP(CStudyDlgTabPage0, CDialogEx)
END_MESSAGE_MAP()


// CStudyDlgTabPage0 消息处理程序




BOOL CStudyDlgTabPage0::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_CameraAcquisitionMode.AddString(_T("同步采集"));
	m_CameraAcquisitionMode.AddString(_T("异步采集"));
	m_CameraAcquisitionMode.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
