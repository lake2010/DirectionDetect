#pragma once


// CStudyDlgTabPage2 �Ի���

class CStudyDlgTabPage2 : public CDialogEx
{
	DECLARE_DYNAMIC(CStudyDlgTabPage2)

public:
	CStudyDlgTabPage2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStudyDlgTabPage2();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDY1_P2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
