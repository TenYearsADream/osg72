//osgview glider.osg 
#include"Common.h"   //包含库的头文件

#include<osgViewer/Viewer>
#include<osgDB/ReadFile>

#include<osgGA/GUIEventAdapter>
#include<osgViewer/ViewerEventHandlers>  //osgGA.lib

#include<osg/Geode>
#include<osg/ShapeDrawable>//绘制图元

#include<osg/Material>//材料属性
#include<osg/StateSet> //状态设置

#include<osg/Image>//纹理相关
#include<osg/Texture2D> 

#include<osg/LineWidth> //设置线宽

#include<istream>

 //创建简单图元
 osg::ref_ptr<osg::Geode> CreatSimple() //返回叶子节点
 {
	 osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	 osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;//需要画的几何对象
	 
	
	//申请一些数组
	osg::ref_ptr<osg::Vec3Array>  coords = new osg::Vec3Array;//坐标
	osg::ref_ptr<osg::Vec4Array>  colors = new osg::Vec4Array;//申请颜色
	osg::ref_ptr<osg::Vec3Array>  normal = new osg::Vec3Array;//法向量，一个复杂地形法向量会很多
	osg::ref_ptr<osg::LineWidth>  linewidth = new osg::LineWidth; // 线宽 


	geode->addDrawable(geom.get());//将图元加载到原adddrawable
	
	//打开透明度
    geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	
	//设置线宽
	linewidth->setWidth(15.0); //void setWidth(float width);
	//线宽的设置要写到节点里面去
	geode->getOrCreateStateSet()->setAttributeAndModes(linewidth.get(), osg::StateAttribute::ON) ;

	//设置顶点,绑定顶点数组对象VAO
	geom->setVertexArray(coords.get());//void setVertexArray(Array* array);
	 //设置顶点的关联方式（图元）
	geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINE_LOOP, 0, 4)); //QUADS
		 //bool addPrimitiveSet(PrimitiveSet* primitiveset);
	
	//设置 颜色,绑定颜色点数组对象，VAO
	//这个错误调了半天，注意看，是设置颜色数组 geom->setVertexArray(colors.get());//绑定
	geom->setColorArray(colors.get());
	geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	 
	//设置法向量
	geom->setNormalArray(normal.get());
	geom->setNormalBinding(osg::Geometry::BIND_OVERALL);



	//输入顶点数据
	coords->push_back(osg::Vec3(-10.0, 5.0, -10.0));//第一个点：左下 深度为5
	coords->push_back(osg::Vec3( 10.0, 5.0, -10.0));//右下
	coords->push_back(osg::Vec3(10.0, 5.0, 10.0));//右上
	coords->push_back(osg::Vec3(-10.0, 5.0, 10.0));//左上

	 
	//颜色数据
	colors->push_back(osg::Vec4f(1.0f, 0.0f,0.0f, 0.5f));
	colors->push_back(osg::Vec4f(0.0f, 1.0f,0.0f, 0.5f));
	colors->push_back(osg::Vec4f(0.0f, 0.0f,1.0f, 0.5f));
	colors->push_back(osg::Vec4f(1.0f, 1.0f,0.0f, 0.5f));

	//压入法向量
	normal->push_back(osg::Vec3(0.0, -1.0, 0.0));  //在朝向我们这个方向比较亮

	return geode;
 }
int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	//可以载添加一个参照物来显示透明度
	osg::ref_ptr<osg::Group> group = new osg::Group;//一个组
	group->addChild(osgDB::readNodeFile("cow.osg")); //作为参照的牛
	group->addChild(CreatSimple());

	viewer->setSceneData(group.get());//设置场景为整个组
	return viewer->run();
}
