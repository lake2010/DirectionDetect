
// DirectionDetectView.h : CDirectionDetectView 类的接口
//

#pragma once


class CDirectionDetectView : public CView
{
protected: // 仅从序列化创建
	CDirectionDetectView();
	DECLARE_DYNCREATE(CDirectionDetectView)

// 特性
public:
	CDirectionDetectDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CDirectionDetectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
public:
	LONG64 m_hMainViewWindowID;							//主界面halcon window ID

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public://菜单栏、工具栏事件响应函数
	//开始检测
	afx_msg void OnCmdStart();
	//停止检测
	afx_msg void OnCmdStop();
	//打开学习对话框
	afx_msg void OnEditStudy();
};

#ifndef _DEBUG  // DirectionDetectView.cpp 中的调试版本
inline CDirectionDetectDoc* CDirectionDetectView::GetDocument() const
   { return reinterpret_cast<CDirectionDetectDoc*>(m_pDocument); }
#endif

