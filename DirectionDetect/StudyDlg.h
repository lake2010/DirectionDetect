#pragma once


// CStudyDlg �Ի���

class CStudyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStudyDlg)

public:
	CStudyDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStudyDlg();
private:
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	
	LONG64 m_hStudyDlgWindowID;								//ѧϰ����halcon window ID


	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedOpenPic();
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnOK();
};
