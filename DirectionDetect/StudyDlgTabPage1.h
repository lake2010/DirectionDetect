#pragma once


// CStudyDlgTabPage1 �Ի���

class CStudyDlgTabPage1 : public CDialogEx
{
	DECLARE_DYNAMIC(CStudyDlgTabPage1)

public:
	CStudyDlgTabPage1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStudyDlgTabPage1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDY1_P1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
