#pragma once
//3.����halcon12
//(1)��Ŀ - ���� - �������� - ������ - ���� - ����������������£�
//halconcpp.lib
//(2)��Ŀ - ���� - �������� - VC++Ŀ¼ - ����Ŀ¼������£�
//D : \software\halcon12\include;
//D:\software\halcon12\include\halconcpp;
//(3)��Ŀ - ���� - �������� - VC++Ŀ¼ - ��Ŀ¼������£�
//D : \software\halcon12\lib\x64 - win64
//	(4)��Ŀ - ���� - �������� - ���ù�����������Ŀƽ̨��Ϊx64��
//	(5)Դ�ļ���������£�
//
//#include "Halconcpp.h"
//	using namespace HalconCpp;


//�칫�ҵ���halcon·��  D:\program\halcon
//���˵���halcon·��		F:\program files\HALCON


#include "Halconcpp.h"
using namespace HalconCpp;


BOOL halcon_test(void *p = NULL);								//ȫ�ֲ��Ժ���


/*typedef*/ struct WorkThreadFunParameters {

	LONG64 m_lHalconWindId = 0;
};
//��⼷�۷���
unsigned int __stdcall gWorkThreadFun(PVOID pM);





namespace MFC_HALCON
{
//��һ��halcon����   �����������ڣ��ڸ������е����ϡ�����λ��
	LONG64 MH_OpenWindow(HWND h_wFather, CRect rect);	

//��ȡָ��·��ͼ��
	BOOL MH_ReadImage(CString szpath, HObject &Image);

//��ʾHObjectͼ��
	BOOL MH_DispImage(HObject &Image, HTuple wndId, CRect position =0);
};