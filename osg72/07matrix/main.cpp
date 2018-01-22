//osgview glider.osg 
#include"Common.h"   //包含库的头文件

#include<osgViewer/Viewer>
#include<osgDB/ReadFile>

#include<osgGA/GUIEventAdapter>
#include<osgViewer/ViewerEventHandlers>  //osgGA.lib

#include<osg/Geode>
#include<osg/ShapeDrawable>//绘制图元

#include<osg/MatrixTransform> //矩阵转换头文件
#include<osg/AnimationPath>//动画路径头文件

#include<istream>


//添加一个函数来实现矩阵操作
osg::ref_ptr<osg::Node>  MatrixOperation()//group 返回值类型 对应 osg::Node 枝节点
{
	osg::ref_ptr<osg::Group> group = new osg::Group;
	osg::ref_ptr<osg::MatrixTransform> mat1 = new osg::MatrixTransform;
	osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("glider.osg");//重复要用的单独写出来
	osg::ref_ptr<osg::MatrixTransform> mat2 = new osg::MatrixTransform;
	osg::ref_ptr<osg::MatrixTransform> mat3 = new osg::MatrixTransform;
	osg::ref_ptr<osg::MatrixTransform> mat4 = new osg::MatrixTransform;

	//平移 
	//mat->addChild(osgDB::readNodeFile("Glider.osg"));//给mat添加节点数据
	mat2->addChild(node.get());//mat2设置操作数据
	mat2->setMatrix(osg::Matrix::translate(5.0, 0.0, 0.0));//将包围球的中心移到(5.0, 0.0, 0.0)
	//void setMatrix(const Matrix& mat)   tanslate将生成转换函数
	//旋转
	//实现半径为5的绕轴旋转，必须将平移矩阵设置操作设置成旋转的下一级child节点
	mat1->setUpdateCallback(new osg::AnimationPathCallback(osg::Vec3(3.0, 0.0, 0.0),osg::Z_AXIS, 3.0));//绕点，绕轴，角速度
	mat1->addChild(mat2.get());//为实现旋转的平移，原本是从（000）过边

	mat4->addChild(node.get());
	mat4->setMatrix(osg::Matrix::translate(-5.0, 0.0, 0.0));//类似于起始旋转点
	mat3->setUpdateCallback(new osg::AnimationPathCallback(osg::Vec3(-3.0, 2.0, 3.0),osg::Z_AXIS, 3.0)); 
	mat3->addChild(mat4.get()); 

	//实现半径为5的绕轴旋转，必须将平移矩阵设置操作设置成旋转的下一级child节点
	group->addChild(node.get());//第一个模型
	group->addChild(mat1.get());//virtual bool addChild( Node *child ); 
	group->addChild(mat3.get()); 
	
	return group;//画的是group
}

int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;


	viewer->setSceneData(MatrixOperation());
	return viewer->run();//指针
}
