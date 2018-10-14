
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once
#include<map>//����ǰ������
class CMainFrame : public CFrameWndEx
{
// ����
public:
	void enableMenu(unsigned int prametersNum, ...);//ָ�����ò˵���
	void disableMenu(unsigned int prametersNum, ...);//ָ�����ò˵���
private:
	void changeMenuUiStatus(CCmdUI *pCmdUI, unsigned int menuIndex);

protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

private:
	//�˵�������������ť״̬���  ����1 ����0  
	//ͼ�±��Ӧ��ťID
	//�����ð�ť�±�����ǣ�CCmdUI->m_index ����ȫ׼ȷ
	std::map <long,bool>m_MenuUiStatusMap;


// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBar       m_wndToolBar;
	CMFCStatusBar     m_wndStatusBar;
	CMFCToolBarImages m_UserImages;
	////װ�ع���������ԴͼƬ 
	//CImageList m_ImgList;
	////�����µĹ�����
	//CToolBar m_newToolBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnUpdateCmdStart(CCmdUI *pCmdUI);
	afx_msg void OnUpdateCmdStop(CCmdUI *pCmdUI);
	afx_msg void OnUpdateEditStudy(CCmdUI *pCmdUI);
	afx_msg void OnUpdateAppExit(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFileOpen(CCmdUI *pCmdUI);
};


