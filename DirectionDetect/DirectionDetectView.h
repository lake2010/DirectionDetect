
// DirectionDetectView.h : CDirectionDetectView ��Ľӿ�
//

#pragma once


class CDirectionDetectView : public CView
{
protected: // �������л�����
	CDirectionDetectView();
	DECLARE_DYNCREATE(CDirectionDetectView)
// ����
public:
	void setHaloconWindRect();
private:

// ����
public:
	CDirectionDetectDoc* GetDocument() const;
	UINT_PTR m_lTimer;
	LONG64 m_hMainViewWindowID;							//������halcon window ID
	CRect m_rect;
private:
	

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	
// ʵ��
public:
	virtual ~CDirectionDetectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public://�˵������������¼���Ӧ����
	//��ʼ���
	afx_msg void OnCmdStart();
	//ֹͣ���
	afx_msg void OnCmdStop();
	//��ѧϰ�Ի���
	afx_msg void OnEditStudy();
	//��ʱ���ʼ���������
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // DirectionDetectView.cpp �еĵ��԰汾
inline CDirectionDetectDoc* CDirectionDetectView::GetDocument() const
   { return reinterpret_cast<CDirectionDetectDoc*>(m_pDocument); }
#endif

