#ifndef _COMMON_H_
#define _COMMON_H_

//ָ����include �� libĿ¼֮��
// ������ļ���ʹ������Ե�����Ӧ�Ķ�̬���ӿ⣬������ȥ������
#ifdef _DEBUG  
#pragma comment(lib, "osgd.lib")   //debugģʽ ��׺����d
#pragma comment(lib, "osgDBd.lib")
#pragma comment(lib, "osgViewerd.lib")
#pragma comment(lib, "OpenThreadsd.lib")

#pragma comment(lib, "osgGAd.lib")


//#pragma comment(lib, "osgd.lib")

#else 
#pragma comment(lib, "osg .lib")   //releaseģʽ  
#pragma comment(lib, "osgDB.lib")
#pragma comment(lib, "osgViewer.lib")
#pragma comment(lib, "OpenThreads.lib")
#pragma comment(lib, "osgGA.lib")
#endif


#endif