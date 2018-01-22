//osgview glider.osg 
#include"Common.h"   //�������ͷ�ļ�

#include<osgViewer/Viewer>
#include<osgDB/ReadFile>

#include<osgGA/GUIEventAdapter>
#include<osgViewer/ViewerEventHandlers>  //osgGA.lib
#include<istream>

//ģ��һ���¼��࣬��Ӧ����h
class PrintWords : public osgGA::GUIEventHandler
{
    public: 
		 bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
		 {
			 return false; 		//�����һ��event return true������ֹ����ֵ�������event,������ʾ,���е������¼�Ҳ������
		 }
		 virtual void getUsage(osg::ApplicationUsage& usage) const //ע����麯��Ҳ����Ϊ������const����
		 {
			 usage.addKeyboardMouseBinding("WangYanlin", "verygood."); //����h����ʾ�µ�һ��
		 }

};

int main()
{
	//osgViewer::Viewer viewer;
	//ʹ������ָ��
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer; //ָ��
	osg::ref_ptr<osg::Node> node  = new osg::Node;
	
	//����һ����ʱ���� osg::timer,�Լ����Կ�Դ�루ͷ�ļ�������ȡ��Ա����
	osg::Timer* timer = new osg::Timer;
	osg::Timer_t start_time = 0;
	osg::Timer_t end_time = 0;

	//�õ�һ��tickֵΪ����
	std::cout<<timer->getSecondsPerTick()<<std::endl;

	start_time = timer->tick(); //��ȡ��ǰtickֵ
	timer->setStartTick();//����һֱ���ú������õ�ǰtick
	//��ȡģ��
	node = osgDB::readNodeFile("glider.osg"); 
	end_time = timer->tick();
	//����һ���ú��� ����tick
	std::cout<<"��ȡ��ǰģ��ʱ��Ϊ�� " << timer->time_s()<< std::endl;
	//������������tick�Ĳ�ֵ���Ƕ�ȡģ�͵�ʱ��
	//std::cout<<"��ȡ��ǰģ��ʱ��Ϊ�� " << delta_s��start_time,end_time��<< std::endl;������ó�Ա��������Ա����������ʹ��
	std::cout<<"��ȡ��ǰģ��ʱ��Ϊ�� " << timer->delta_s(start_time,end_time)<< std::endl;
	//����������osgviewer���ĺ��� starttime = viewer->elapsedTime(),endtime = viewer->elapsedTime(),starttime-endtime;
	
	//�¼� ViewerEventHandlers �һ������ļ����뼴�ɲ�ѯ
		//��Ӱ����¼� Ĭ�ϰ�h���ְ�������   ����Ҳ���Ը�д�����
	viewer->addEventHandler(new PrintWords);//�Զ����¼���
	 viewer->addEventHandler(new osgViewer::HelpHandler); //new osgViewer::HelpHandler �����ռ䣬����
	//�޸�HelpHandler��ʵ�ְ�һ��һ���������ϳ��ֺܶ�����
    //�����һ��event return true������ֹ����ֵ�������event,������ʾ

	 viewer->addEventHandler(new osgViewer::StatsHandler); //��ʾ֡��

	 viewer->addEventHandler(new osgViewer::WindowSizeHandler); //���캯�����濴��ֵ f
	 viewer->addEventHandler(new osgViewer::ScreenCaptureHandler);//��ͼ
	 //����������������¼��࣬�һ�ViewerEventHandlers,���������

	viewer->setSceneData(node.get());//node �� viewer����ָ�룬node.get()
	return viewer->run();//viewer.run()
	//return viewer.run();
}
