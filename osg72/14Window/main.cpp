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
			viewer->getWindows(ws); //��ȡ��ǰ����
			if(!ws.empty())//��ȡ�ɹ�
			{
				osgViewer::Viewer::Windows::iterator iter = ws.begin();
				for(; iter != ws.end(); iter++)
				{
					(*iter) -> setWindowRectangle(320, 150, 800, 600 );
					(*iter) -> setWindowDecoration(false); //�����ޱ߿�
					(*iter) -> setCursor(osgViewer::GraphicsWindow::WaitCursor); //��������ʽΪæ���
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
	
	viewer->addEventHandler(new ChangeWindow()); //�½�һ���¼���

	viewer->run();

/*	
	//�������ڻ�� ϵͳ�ķֱ��ʵ� ָ�� windowsolution
	osg::GraphicsContext::WindowingSystemInterface * windowsolution = osg::GraphicsContext::getWindowingSystemInterface();
	
	unsigned int height, width;//��Ļ�ֱ��ʵĸߺͿ�
	osg::GraphicsContext::Traits traits; //traits ��Ļ��������

	if(windowsolution)//�ж��Ƿ��óɹ�
	{
		std::cout << "Get device interface success " << std::endl;
		windowsolution -> getScreenResolution(traits, width, height);//��ȡ����
		std::cout << "ϵͳ�ֱ���Ϊ��" << width << "x"  << height << std::endl;
		//traits.x = 0;
		//traits.y = 0;
		//traits.width = 800;
		//traits.height = 600;
		windowsolution->setScreenResolution(traits, 800, 600); //������Ļ�ֱ���Ϊ800 * 600

		
	}
	else
	{
		std::cout <<  "Fail to get device interface" << std::endl;
	}

*/
	return 0;
}

//viewer->setUpViewInWindow( 100, 100, 800, 600, 0 ); ֮ǰ�������������ʵ��������ʾ��Ļ