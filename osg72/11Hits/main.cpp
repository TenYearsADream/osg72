#include"Common.h"

#include<osgViewer/Viewer>
#include<osgDB/ReadFile>
#include<osg/Geode>
#include<osg/ShapeDrawable> //绘制图形

//新建一个绘制函数，返回值作参数
osg::ref_ptr<osg::Geode> Creatbox()
{
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	geode->addDrawable(new osg::ShapeDrawable(new osg::Box(osg::Vec3(0,0,0) ,10.0, 10.0, 10.0)));//中心为坐标，上下左右都是5(-5)
	
	return geode;
}


int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osg::ref_ptr<osg::Group> group = new osg::Group;
	viewer->setUpViewInWindow( 100, 100, 800, 600, 0 ); 

	//group->addChild(osgDB::readNodeFile("glider.osg"));
	group->addChild(Creatbox());
	
	viewer->setSceneData(group);
	
	return viewer->run();
}