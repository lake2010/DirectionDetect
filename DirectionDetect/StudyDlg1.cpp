// StudyDlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "DirectionDetect.h"
#include "StudyDlg1.h"
#include "afxdialogex.h"
#include "MfcHalcon.h"

// CStudyDlg1 对话框

IMPLEMENT_DYNAMIC(CStudyDlg1, CDialogEx)

CStudyDlg1::CStudyDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_STUDY1, pParent)
{

}

CStudyDlg1::~CStudyDlg1()
{
}

void CStudyDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STUDY_TAB, m_studyTab);
}


BEGIN_MESSAGE_MAP(CStudyDlg1, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_STUDY_TAB, &CStudyDlg1::OnTcnSelchangeStudyTab)
	ON_BN_CLICKED(IDC_OPEN_PIC, &CStudyDlg1::OnBnClickedOpenPic)
END_MESSAGE_MAP()


// CStudyDlg1 消息处理程序


BOOL CStudyDlg1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//添加选项卡
	m_studyTab.InsertItem(0, _T("相机设置"));
	m_studyTab.InsertItem(1, _T("光源设置"));
	m_studyTab.InsertItem(2, _T("串口通信设置"));
	m_studyTab.InsertItem(3, _T("图像处理设置"));
	m_studyTab.InsertItem(4, _T("其他"));
	//创建画面
	m_tabPage0.Create(IDD_STUDY1_P0, &m_studyTab);
	m_tabPage1.Create(IDD_STUDY1_P1, &m_studyTab);
	m_tabPage2.Create(IDD_STUDY1_P2, &m_studyTab);
	m_tabPage3.Create(IDD_STUDY1_P3, &m_studyTab);
	m_tabPage4.Create(IDD_STUDY1_P4, &m_studyTab);
	//获得m_studyTab客户区大小
	CRect rs;
	m_studyTab.GetClientRect(&rs);
	//调整子对话框在父窗口中的位置，可以改动数值，使子窗体的大小合适；
	rs.top += 25;
	rs.bottom -= 3;
	rs.left += 2;
	rs.right -= 2;
	//设置子对话框尺寸并移动到指定位置
	m_tabPage0.MoveWindow(&rs);
	m_tabPage1.MoveWindow(&rs);
	m_tabPage2.MoveWindow(&rs);
	m_tabPage3.MoveWindow(&rs);
	m_tabPage4.MoveWindow(&rs);
	//分别设置隐藏和显示
	m_tabPage0.ShowWindow(true);
	m_tabPage1.ShowWindow(false);
	m_tabPage2.ShowWindow(false);
	m_tabPage3.ShowWindow(false);
	m_tabPage4.ShowWindow(false);
	//设置默认的选项卡
	m_studyTab.SetCurSel(0);


	//初始化halcon窗口
	CRect rect;
	GetClientRect(&rect);
	rect.right = rect.right * 6 / 10;
	rect.bottom = rect.bottom - 120;
	m_hStudyDlgWindowID = MFC_HALCON::MH_OpenWindow(m_hWnd, rect);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CStudyDlg1::OnTcnSelchangeStudyTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	m_tabPage0.ShowWindow(false);
	m_tabPage1.ShowWindow(false);
	m_tabPage2.ShowWindow(false);
	m_tabPage3.ShowWindow(false);
	m_tabPage4.ShowWindow(false);
	int CurSel = m_studyTab.GetCurSel();
	switch (CurSel)
	{
	case 0:
		m_tabPage0.ShowWindow(true);
		break;
	case 1:
		m_tabPage1.ShowWindow(true);
		break;
	case 2:
		m_tabPage2.ShowWindow(true);
		break;
	case 3:
		m_tabPage3.ShowWindow(true);
		break;
	case 4:
		m_tabPage4.ShowWindow(true);
		break;
	}
	*pResult = 0;
}


void CStudyDlg1::OnBnClickedOpenPic()
{
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
