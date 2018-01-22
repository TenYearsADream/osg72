#include"Traval.h"
//#include"Common.h"
int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("cow.osg");

	viewer->setSceneData(node.get());
	viewer->setUpViewInWindow( 100, 100, 800, 600, 0 ); 

	viewer->setCameraManipulator(new TravalManipulator()); //添加操作器对象  注意视口和朝向的设置

	return viewer->run();
}