#include "stdafx.h"
#include "MfcHalcon.h"

BOOL halcon_test(void* p)
{
		HTuple newHWindowID(*((LONG64 *)p));
		HTuple ImageWidth;
		HTuple ImageHeight;
		HObject hImage;
		ReadImage(&hImage, "UserImages.bmp");
		GetImagePointer1(hImage, NULL, NULL, &ImageWidth, &ImageHeight);
		SetPart(newHWindowID, 0, 0, ImageHeight, ImageWidth);// 
		DispObj(hImage, newHWindowID);
	return 0;
}



unsigned int __stdcall gWorkThreadFun(PVOID pM)
{
	/*��������
	��ʼ�����
	����Ƿ��˳�ѭ��

	��ȡPLC ������λ��Ϣ
	��Դ��ͨ
	��ʱ
	����
	��Դ�Ͽ�
	ͼ����
	����ش�
	ѭ��

	�ͷ����
	*/
	HTuple hv_AcqHandle;//������
	OpenFramegrabber("GigEVision", 0, 0, 0, 0, 0, 0, "default", -1, "default", -1,
		"false", "default", "c42f90f1c384_Hikvision_MVCA00330GM", 0, -1, &hv_AcqHandle);
	GrabImageStart(hv_AcqHandle, -1);

	HObject ho_Image;//����ͼ��
	while (true)
	{
		GrabImageAsync(&ho_Image, hv_AcqHandle, -1);



	}

	CloseFramegrabber(hv_AcqHandle);
	return 0;
}







//----------------------------MFC_HALCON BEGIN-----------------------------------------------

LONG64 MFC_HALCON::MH_OpenWindow(HWND h_wFather ,CRect rect) {
	HTuple HFatherWindow;
	HTuple newHWindowID;
	HFatherWindow = (Hlong)h_wFather;
	OpenWindow(rect.top, rect.left, rect.Width(), rect.Height(), HFatherWindow, "visible", "", &newHWindowID);
	return newHWindowID.L();
}

BOOL MFC_HALCON::MH_ReadImage(CString szpath, HObject &Image) {
	//T2A
	char chPath[301];
	int n = szpath.GetLength(); //���ַ����㣬str�ĳ���
	int len = WideCharToMultiByte(CP_ACP, 0, szpath, n, NULL, 0, NULL, NULL);//��Byte����str����
	if (len > 300)
		return -1;
	WideCharToMultiByte(CP_ACP, 0, szpath, n, chPath, len, NULL, NULL);//���ֽ�ת��Ϊ���ֽڱ���
	chPath[len] = '\0';//��Ҫ����ĩβ������־
	HTuple path(chPath);
	ReadImage(&Image, path);//
	
}

BOOL MFC_HALCON::MH_DispImage(HObject &Image, HTuple wndId, CRect position) {
	if (position.Width() == 0)
	{
		HTuple width, height;
		GetImageSize(Image, &width, &height);
		SetPart(wndId, 0, 0, height, width);
	}
	else
	{
		SetPart(wndId, 0, 0, 50, 200);
	}
	DispObj(Image, wndId);
	return 0;
}
//----------------------------MFC_HALCON OVER-----------------------------------------------