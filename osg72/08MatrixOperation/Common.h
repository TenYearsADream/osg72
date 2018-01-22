#ifndef _COMMON_H_
#define _COMMON_H_

//指定完include 和 lib目录之后
// 导入库文件，使程序可以调用相应的动态链接库，不必再去设置了
#ifdef _DEBUG  
#pragma comment(lib, "osgd.lib")   //debug模式 后缀加上d
#pragma comment(lib, "osgDBd.lib")
#pragma comment(lib, "osgViewerd.lib")
#pragma comment(lib, "OpenThreadsd.lib")

#pragma comment(lib, "osgGAd.lib")


//#pragma comment(lib, "osgd.lib")

#else 
#pragma comment(lib, "osg .lib")   //release模式  
#pragma comment(lib, "osgDB.lib")
#pragma comment(lib, "osgViewer.lib")
#pragma comment(lib, "OpenThreads.lib")
#pragma comment(lib, "osgGA.lib")
#endif


#endif