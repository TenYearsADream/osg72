#include"Common.h" 
#include<osgDB/ReadFile>
#include<osgViewer/Viewer>
#include<osg/Node>
#include<osg/MatrixTransform>
osg::ref_ptr<osg::Node> Translation() //枝节点 
{
    osg::ref_ptr<osg::Group> root = new osg::Group();   
    osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("cow.osg");//设置默认的模型    
    osg::ref_ptr<osg::MatrixTransform> trans1 = new osg::MatrixTransform();
    osg::ref_ptr<osg::MatrixTransform> trans2 = new osg::MatrixTransform();
    
	trans1->addChild(node.get());//设置指针指向的操作数据，然后设置平移旋转矩阵
	trans1->setMatrix(osg::Matrix::translate(0,0,10));//平移操作

	trans2->addChild(node.get());//设置指针指向的操作数据
	trans2->setMatrix(osg::Matrix::translate(0,0,-10));//平移操作  

    root->addChild(node.get());//显示的第一个模型
    root->addChild(trans1.get());//平移后的模型
    root->addChild(trans2.get());//平移后的模型
	return root;
}
osg::ref_ptr<osg::Node> Zoom() //枝节点 
{
    osg::ref_ptr<osg::Group> root = new osg::Group();   
    osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("cow.osg");//设置默认的模型    
    osg::ref_ptr<osg::MatrixTransform> zoom1 = new osg::MatrixTransform();
    osg::ref_ptr<osg::MatrixTransform> zoom2 = new osg::MatrixTransform();
    
	zoom1->addChild(node.get());//设置指针指向的操作数据,然后再设置平移缩放
	zoom1->setMatrix(osg::Matrix::scale(0.5,0.5,0.5)*osg::Matrix::translate(0,-10,0));
	
	zoom2->addChild(node.get());//设置指针指向的操作数据
	zoom2->setMatrix(osg::Matrix::scale(2.0,2.0,2.0)*osg::Matrix::translate(0,10,0));	  

    root->addChild(node.get());//显示的第一个模型
    root->addChild(zoom1.get());//平移后的模型
    root->addChild(zoom2.get());//平移后的模型
	return root;
}
osg::ref_ptr<osg::Node> Rotate() //枝节点 
{
    osg::ref_ptr<osg::Group> root = new osg::Group();   
    osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("cow.osg");//设置默认的模型    
    osg::ref_ptr<osg::MatrixTransform> rotate1 = new osg::MatrixTransform();
    osg::ref_ptr<osg::MatrixTransform> rotate2 = new osg::MatrixTransform();
    
	rotate1->addChild(node.get());//设置指针指向的操作数据,然后再设置平移旋转缩放矩阵
	rotate1->setMatrix(osg::Matrix::rotate(osg::DegreesToRadians(-90.0),3,3,3));
	//绕点旋转指定角度后停止，动态旋转参照上一个项目
	rotate2->addChild(node.get());//设置指针指向的操作数据
	rotate2->setMatrix(osg::Matrix::rotate(osg::DegreesToRadians(90.0),0,1,0));	  

    root->addChild(node.get());//显示的第一个模型
    root->addChild(rotate1.get());//平移后的模型
    root->addChild(rotate2.get());//平移后的模型
	return root;
}
int main()
{

	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	viewer->setUpViewInWindow( 100, 100, 800, 600, 0 ); //生成非全屏视图,左上角为（0，0）
	//void setUpViewInWindow(int x, int y, int width, int height, unsigned int screenNum=0);

	viewer->setSceneData(Translation());
	
	return viewer->run();//指针
}
