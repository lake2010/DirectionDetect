#pragma once


// CStudyDlgTabPage3 �Ի���

class CStudyDlgTabPage3 : public CDialogEx
{
	DECLARE_DYNAMIC(CStudyDlgTabPage3)

public:
	CStudyDlgTabPage3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStudyDlgTabPage3();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDY1_P3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
