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


#include "Halconcpp.h"
using namespace HalconCpp;


BOOL halcon_test(void *p = NULL);								//ȫ�ֲ��Ժ���

namespace MFC_HALCON
{
	LONG64 MH_OpenWindow(HWND h_wFather, CRect rect);							//��һ��halcon����




};