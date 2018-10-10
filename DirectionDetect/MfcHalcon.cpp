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






LONG64 MFC_HALCON::MH_OpenWindow(HWND h_wFather ,CRect rect) {
	HTuple HFatherWindow;
	HTuple newHWindowID;
	HFatherWindow = (Hlong)h_wFather;
	OpenWindow(rect.left, rect.top, rect.Width(), rect.Height(), HFatherWindow, "visible", "", &newHWindowID);
	return newHWindowID.L();
}




