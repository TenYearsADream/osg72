#include"Common.h"

#include<osgViewer/Viewer>
#include<osgViewer/ViewerEventHandlers> //HelpHandler
#include<osg/GraphicsContext>
#include <osgDB/ReadFile>//osgDB::readNodeFile

#include <osgGA/GUIEventHandler>
#include <osgGA/GUIActionAdapter>

#include<iostream> 
class ChangeWindow : public osgGA::GUIEventHandler
{
public:
	ChangeWindow() {first = false;}
	bool handle(const osgGA::GUIEventAdapter &ea, osgGA::GUIActionAdapter & aa)
	{
		if(!first)
		{
			osgViewer::Viewer *viewer = dynamic_cast<osgViewer::Viewer*>(&aa);
			osgViewer::Viewer::Windows ws;
			first = true;
			viewer->getWindows(ws); //获取当前窗口
			if(!ws.empty())//获取成功
			{
				osgViewer::Viewer::Windows::iterator iter = ws.begin();
				for(; iter != ws.end(); iter++)
				{
					(*iter) -> setWindowRectangle(320, 150, 800, 600 );
					(*iter) -> setWindowDecoration(false); //设置无边框
					(*iter) -> setCursor(osgViewer::GraphicsWindow::WaitCursor); //设置鼠标格式为忙鼠标
				}
			}
		}
		return false;
	}
	private:
		bool first;
};


int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osgViewer::Viewer::Windows ws;

	viewer->setSceneData(osgDB::readNodeFile("glider.osg"));
	
	viewer->addEventHandler(new ChangeWindow()); //新建一个事件类

	viewer->run();

/*	
	//申请用于获得 系统的分辨率的 指针 windowsolution
	osg::GraphicsContext::WindowingSystemInterface * windowsolution = osg::GraphicsContext::getWindowingSystemInterface();
	
	unsigned int height, width;//屏幕分辨率的高和宽
	osg::GraphicsContext::Traits traits; //traits 屏幕参数对象

	if(windowsolution)//判断是否获得成功
	{
		std::cout << "Get device interface success " << std::endl;
		windowsolution -> getScreenResolution(traits, width, height);//获取参数
		std::cout << "系统分辨率为：" << width << "x"  << height << std::endl;
		//traits.x = 0;
		//traits.y = 0;
		//traits.width = 800;
		//traits.height = 600;
		windowsolution->setScreenResolution(traits, 800, 600); //设置屏幕分辨率为800 * 600

		
	}
	else
	{
		std::cout <<  "Fail to get device interface" << std::endl;
	}

*/
	return 0;
}

//viewer->setUpViewInWindow( 100, 100, 800, 600, 0 ); 之前是用这个函数来实现设置显示屏幕