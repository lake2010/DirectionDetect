
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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDirectionDetectView

IMPLEMENT_DYNCREATE(CDirectionDetectView, CView)

BEGIN_MESSAGE_MAP(CDirectionDetectView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDirectionDetectView ����/����

CDirectionDetectView::CDirectionDetectView()
{
	// TODO: �ڴ˴���ӹ������

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


// CDirectionDetectView ��Ϣ�������
