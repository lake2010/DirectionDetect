
// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include<map>//不会前置申明
class CMainFrame : public CFrameWndEx
{
// 操作
public:
	void enableMenu(unsigned int prametersNum, ...);//指定启用菜单项
	void disableMenu(unsigned int prametersNum, ...);//指定禁用菜单项
private:
	void changeMenuUiStatus(CCmdUI *pCmdUI, unsigned int menuIndex);

protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

private:
	//菜单栏、工具栏按钮状态标记  启用1 禁用0  
	//图下标对应按钮ID
	//不能用按钮下标作标记，CCmdUI->m_index 不完全准确
	std::map <long,bool>m_MenuUiStatusMap;


// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CMFCMenuBar       m_wndMenuBar;
	CMFCToolBar       m_wndToolBar;
	CMFCStatusBar     m_wndStatusBar;
	CMFCToolBarImages m_UserImages;
	////装载工具栏上资源图片 
	//CImageList m_ImgList;
	////创建新的工具栏
	//CToolBar m_newToolBar;

// 生成的消息映射函数
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


