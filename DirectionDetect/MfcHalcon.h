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


#include "Halconcpp.h"
using namespace HalconCpp;


BOOL halcon_test(void *p = NULL);								//全局测试函数

namespace MFC_HALCON
{
	LONG64 MH_OpenWindow(HWND h_wFather, CRect rect);							//打开一个halcon窗口




};