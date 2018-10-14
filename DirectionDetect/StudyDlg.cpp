// StudyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DirectionDetect.h"
#include "StudyDlg.h"
#include "afxdialogex.h"
#include "MfcHalcon.h"

// CStudyDlg 对话框

IMPLEMENT_DYNAMIC(CStudyDlg, CDialogEx)

CStudyDlg::CStudyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_STUDY, pParent)
{

}

CStudyDlg::~CStudyDlg()
{
}

void CStudyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStudyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_OPEN_PIC, &CStudyDlg::OnClickedOpenPic)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CStudyDlg 消息处理程序

BOOL CStudyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//ShowWindow(SW_MAXIMIZE);//对话框默认最大化弹出


	//初始化halcon窗口
	CRect rect;
	GetClientRect(&rect);
	rect.right = rect.right*6/10;
	rect.bottom = rect.bottom - 120;
	m_hStudyDlgWindowID =  MFC_HALCON::MH_OpenWindow(m_hWnd, rect);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void CStudyDlg::OnClickedOpenPic()
{
	// TODO: 在此添加控件通知处理程序代码
	CString m_path;
	CFileDialog hFileDlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY,
		TEXT("支持的图像文件 (*.jpg;*.gif;*.bmp;...)|*.jpg;*.gif;*.bmp|专用Tiff图像文件(*.tiff;*.tif)|*.tiff;*.tif|所有文件(*.*)|*.*||"), NULL);
	hFileDlg.m_ofn.nFilterIndex = 1;
	hFileDlg.m_ofn.hwndOwner = m_hWnd;
	hFileDlg.m_ofn.lStructSize = sizeof(OPENFILENAME);
	hFileDlg.m_ofn.lpstrTitle = TEXT("打开图像文件...\0");
	hFileDlg.m_ofn.nMaxFile = MAX_PATH;
	if (hFileDlg.DoModal() == IDOK)
	{
		m_path = hFileDlg.GetPathName();
		HObject Image;
		CRect rect;
		MFC_HALCON::MH_ReadImage(m_path, Image);
		MFC_HALCON::MH_DispImage(Image, m_hStudyDlgWindowID);
	}
}




void CStudyDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
}


void CStudyDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialogEx::OnOK();
}
