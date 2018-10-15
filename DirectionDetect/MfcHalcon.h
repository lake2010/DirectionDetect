#pragma once
//3.配置halcon12
//(1)项目 - 属性 - 配置属性 - 链接器 - 输入 - 附加依赖项添加如下：
//halconcpp.lib
//(2)项目 - 属性 - 配置属性 - VC++目录 - 包含目录添加如下：
//D : \software\halcon12\include;
//D:\software\halcon12\include\halconcpp;
//(3)项目 - 属性 - 配置属性 - VC++目录 - 库目录添加如下：
//D : \software\halcon12\lib\x64 - win64
//	(4)项目 - 属性 - 配置属性 - 配置管理器，将项目平台改为x64。
//	(5)源文件中添加如下：
//
//#include "Halconcpp.h"
//	using namespace HalconCpp;


//办公室电脑halcon路径  D:\program\halcon
//个人电脑halcon路径		F:\program files\HALCON


#include "Halconcpp.h"
using namespace HalconCpp;


BOOL halcon_test(void *p = NULL);								//全局测试函数


/*typedef*/ struct WorkThreadFunParameters {

	LONG64 m_lHalconWindId = 0;
};
//检测挤盂方向
unsigned int __stdcall gWorkThreadFun(PVOID pM);





namespace MFC_HALCON
{
//打开一个halcon窗口   参数：父窗口，在父窗口中的左上、右下位置
	LONG64 MH_OpenWindow(HWND h_wFather, CRect rect);	

//读取指定路径图像
	BOOL MH_ReadImage(CString szpath, HObject &Image);

//显示HObject图像
	BOOL MH_DispImage(HObject &Image, HTuple wndId, CRect position =0);
};