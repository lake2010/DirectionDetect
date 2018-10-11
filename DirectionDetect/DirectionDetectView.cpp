
// DirectionDetectView.cpp : CDirectionDetectView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DirectionDetect.h"
#endif

#include "DirectionDetectDoc.h"
#include "DirectionDetectView.h"
#include "StudyDlg.h"
#include "MfcHalcon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDirectionDetectView

IMPLEMENT_DYNCREATE(CDirectionDetectView, CView)

BEGIN_MESSAGE_MAP(CDirectionDetectView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_CMD_START, &CDirectionDetectView::OnCmdStart)
	ON_COMMAND(ID_CMD_STOP, &CDirectionDetectView::OnCmdStop)
	ON_COMMAND(ID_EDIT_STUDY, &CDirectionDetectView::OnEditStudy)
END_MESSAGE_MAP()

// CDirectionDetectView 构造/析构

CDirectionDetectView::CDirectionDetectView()
{
	// TODO: 在此处添加构造代码

}

CDirectionDetectView::~CDirectionDetectView()
{
}

BOOL CDirectionDetectView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式


	return CView::PreCreateWindow(cs);
}

// CDirectionDetectView 绘制

void CDirectionDetectView::OnDraw(CDC* /*pDC*/)
{
	CDirectionDetectDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
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


// CDirectionDetectView 诊断

#ifdef _DEBUG
void CDirectionDetectView::AssertValid() const
{
	CView::AssertValid();
}

void CDirectionDetectView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDirectionDetectDoc* CDirectionDetectView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDirectionDetectDoc)));
	return (CDirectionDetectDoc*)m_pDocument;
}
#endif //_DEBUG


// CDirectionDetectView 消息处理程序


void CDirectionDetectView::OnCmdStart()
{
	// TODO: 在此添加命令处理程序代码
	/*
	初始化
	创建工作线程
	*/
	HANDLE handle;
	//handle = (HANDLE)_beginthreadex(NULL, 0, gWorkThreadFun, NULL, 0, NULL);

	return;
}


void CDirectionDetectView::OnCmdStop()
{
	// TODO: 在此添加命令处理程序代码
}


void CDirectionDetectView::OnEditStudy()
{
	// TODO: 在此添加命令处理程序代码
	CStudyDlg studyDlg;
	studyDlg.DoModal();
}
