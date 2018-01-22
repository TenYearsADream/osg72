//osgview glider.osg 
#include"Common.h"   //包含库的头文件

#include<osgViewer/Viewer>
#include<osgDB/ReadFile>

#include<osgGA/GUIEventAdapter>
#include<osgViewer/ViewerEventHandlers>  //osgGA.lib
#include<istream>

//模拟一个事件类，响应单击h
class PrintWords : public osgGA::GUIEventHandler
{
    public: 
		 bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
		 {
			 return false; 		//如果上一个event return true，则终止传递值，下面的event,不再显示,所有的鼠标等事件也无作用
		 }
		 virtual void getUsage(osg::ApplicationUsage& usage) const //注意该虚函数也必须为常函数const类型
		 {
			 usage.addKeyboardMouseBinding("WangYanlin", "verygood."); //按下h键显示新的一列
		 }

};

int main()
{
	//osgViewer::Viewer viewer;
	//使用智能指针
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer; //指针
	osg::ref_ptr<osg::Node> node  = new osg::Node;
	
	//申请一个定时器类 osg::timer,自己可以看源码（头文件），获取成员函数
	osg::Timer* timer = new osg::Timer;
	osg::Timer_t start_time = 0;
	osg::Timer_t end_time = 0;

	//得到一个tick值为多少
	std::cout<<timer->getSecondsPerTick()<<std::endl;

	start_time = timer->tick(); //获取当前tick值
	timer->setStartTick();//方法一直接用函数设置当前tick
	//读取模型
	node = osgDB::readNodeFile("glider.osg"); 
	end_time = timer->tick();
	//方法一：用函数 设置tick
	std::cout<<"读取当前模型时间为： " << timer->time_s()<< std::endl;
	//方法二：两个tick的差值就是读取模型的时间
	//std::cout<<"读取当前模型时间为： " << delta_s（start_time,end_time）<< std::endl;对象调用成员函数，成员函数不单独使用
	std::cout<<"读取当前模型时间为： " << timer->delta_s(start_time,end_time)<< std::endl;
	//方法三，用osgviewer带的函数 starttime = viewer->elapsedTime(),endtime = viewer->elapsedTime(),starttime-endtime;
	
	//事件 ViewerEventHandlers 右击包含文件进入即可查询
		//添加帮助事件 默认按h出现帮助文字   我们也可以改写这个类
	viewer->addEventHandler(new PrintWords);//自定义事件类
	 viewer->addEventHandler(new osgViewer::HelpHandler); //new osgViewer::HelpHandler 命名空间，对象
	//修改HelpHandler来实现按一下一个键桌面上出现很多文字
    //如果上一个event return true，则终止传递值，下面的event,不再显示

	 viewer->addEventHandler(new osgViewer::StatsHandler); //显示帧数

	 viewer->addEventHandler(new osgViewer::WindowSizeHandler); //构造函数里面看初值 f
	 viewer->addEventHandler(new osgViewer::ScreenCaptureHandler);//截图
	 //还可以添加其他的事件类，右击ViewerEventHandlers,看里面的类

	viewer->setSceneData(node.get());//node 和 viewer都是指针，node.get()
	return viewer->run();//viewer.run()
	//return viewer.run();
}
