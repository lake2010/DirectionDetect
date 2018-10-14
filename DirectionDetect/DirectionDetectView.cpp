
// DirectionDetectView.cpp : CDirectionDetectView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "DirectionDetect.h"
#endif

#include "DirectionDetectDoc.h"
#include "DirectionDetectView.h"
#include "StudyDlg1.h"
#include "MfcHalcon.h"
#include "logger\StaticLogger.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


extern CStaticLogger g_logger;
IMPLEMENT_DYNCREATE(CDirectionDetectView, CView)

BEGIN_MESSAGE_MAP(CDirectionDetectView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_CMD_START, &CDirectionDetectView::OnCmdStart)
	ON_COMMAND(ID_CMD_STOP, &CDirectionDetectView::OnCmdStop)
	ON_COMMAND(ID_EDIT_STUDY, &CDirectionDetectView::OnEditStudy)
	ON_WM_TIMER()
	ON_WM_SIZE()
	//ON_UPDATE_COMMAND_UI(ID_CMD_START, &CDirectionDetectView::OnUpdateCmdStart)
	//ON_UPDATE_COMMAND_UI(ID_CMD_STOP, &CDirectionDetectView::OnUpdateCmdStop)
	//ON_UPDATE_COMMAND_UI(ID_EDIT_STUDY, &CDirectionDetectView::OnUpdateEditStudy)
	//ON_UPDATE_COMMAND_UI(ID_APP_EXIT, &CDirectionDetectView::OnUpdateAppExit)
	ON_COMMAND(ID_FILE_OPEN, &CDirectionDetectView::OnFileOpen)
END_MESSAGE_MAP()

// CDirectionDetectView ����/����

CDirectionDetectView::CDirectionDetectView()
{
	// TODO: �ڴ˴���ӹ������
	m_hMainViewWindowID = 0;

}

CDirectionDetectView::~CDirectionDetectView()
{
}

BOOL CDirectionDetectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	
	return CView::PreCreateWindow(cs);
}

// CDirectionDetectView ����

void CDirectionDetectView::OnDraw(CDC* /*pDC*/)
{
	CDirectionDetectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CDirectionDetectView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDirectionDetectView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDirectionDetectView ���

#ifdef _DEBUG
void CDirectionDetectView::AssertValid() const
{
	CView::AssertValid();
}

void CDirectionDetectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDirectionDetectDoc* CDirectionDetectView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDirectionDetectDoc)));
	return (CDirectionDetectDoc*)m_pDocument;
}
#endif //_DEBUG



void CDirectionDetectView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//��ʼ��סview����  halcon����
	setHaloconWindRect();
	m_hMainViewWindowID = MFC_HALCON::MH_OpenWindow(m_hWnd, m_rect);

	KillTimer(m_lTimer);
	CView::OnTimer(nIDEvent);
}


void CDirectionDetectView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	// TODO: �ڴ˴������Ϣ����������
	//����halcon���ڴ�С
	if (0 != m_hMainViewWindowID)
	{
		//HalconCpp::CloseWindow(m_hMainViewWindowID);
		//m_hMainViewWindowID = MFC_HALCON::MH_OpenWindow(m_hWnd, m_rect);
		setHaloconWindRect();
		HalconCpp::SetWindowExtents(m_hMainViewWindowID, m_rect.top, m_rect.left, m_rect.Width(), m_rect.Height());
	}
}


void CDirectionDetectView::setHaloconWindRect()
{
	GetClientRect(m_rect);
	m_rect.top += 10;
	m_rect.left += 10;
	m_rect.right = m_rect.right * 6 / 10;
	m_rect.bottom = m_rect.bottom;
}




// CDirectionDetectView ��Ϣ�������
WorkThreadFunParameters g_WorkThreadFunParameter;

void CDirectionDetectView::OnCmdStart()
{
	/*
	�ؼ���������
	��ʼ��
	���������߳�
	*/
	((CMainFrame*)::AfxGetMainWnd())->enableMenu(1, ID_CMD_STOP);
	((CMainFrame*)::AfxGetMainWnd())->disableMenu(4, ID_CMD_START, ID_APP_EXIT, ID_FILE_OPEN, ID_EDIT_STUDY);
	HANDLE handle;
	g_WorkThreadFunParameter.m_lHalconWindId = m_hMainViewWindowID;
	handle = (HANDLE)_beginthreadex(NULL, 0, gWorkThreadFun, &g_WorkThreadFunParameter, 0, NULL);
	return;
}


void CDirectionDetectView::OnCmdStop()
{
	((CMainFrame*)::AfxGetMainWnd())->enableMenu(4, ID_CMD_START, ID_APP_EXIT, ID_FILE_OPEN, ID_EDIT_STUDY);
	((CMainFrame*)::AfxGetMainWnd())->disableMenu(1, ID_CMD_STOP);

}


void CDirectionDetectView::OnEditStudy()
{
	// TODO: �ڴ���������������
	CStudyDlg1 studyDlg;
	studyDlg.DoModal();
}




void CDirectionDetectView::OnFileOpen()
{
	// TODO: �ڴ���������������
}
