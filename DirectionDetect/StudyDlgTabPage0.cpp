// StudyDlgTabPage0.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DirectionDetect.h"
#include "StudyDlgTabPage0.h"
#include "afxdialogex.h"


// CStudyDlgTabPage0 �Ի���

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


// CStudyDlgTabPage0 ��Ϣ�������




BOOL CStudyDlgTabPage0::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_CameraAcquisitionMode.AddString(_T("ͬ���ɼ�"));
	m_CameraAcquisitionMode.AddString(_T("�첽�ɼ�"));
	m_CameraAcquisitionMode.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
