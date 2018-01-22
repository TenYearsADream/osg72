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



#include<istream>

 osg::ref_ptr<osg::Geode> Createbox()
 {
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	osg::ref_ptr<osg::TessellationHints> hints = new osg::TessellationHints;// 精度
	osg::ref_ptr<osg::ShapeDrawable> shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0.0,0.0,0.0),10.0,10.0,1.0),hints.get());//box参数：中心点，xyz,精度
	//ShapeDrawable(Shape* shape, TessellationHints* hints=0);
	//shape:class Sphere; Box; Cone; Cylinder; Capsule; InfinitePlane;TriangleMesh; ConvexHull; HeightField;
	osg::ref_ptr<osg::Material> material = new osg::Material;// 智能指针

	osg::ref_ptr<osg::Texture2D> texture2D = new osg::Texture2D;
	osg::ref_ptr<osg::Image> image = new osg::Image;

	//设置颜色
	shape->setColor(osg::Vec4f(0.5, 0.5, 0.5, 0.5));
	// void setColor(const Vec4& color); ShapeDrawable类的公有函数
	
	//设置精度
	hints->setDetailRatio(0.5);

	//设置材质属性
	material->setAmbient(osg::Material::FRONT_AND_BACK,osg::Vec4f(1.0, 1.0, 1.0, 0.5));//环境光照参数:rgba
	//void setAmbient( Face face, const Vec4& ambient );
	material->setDiffuse(osg::Material::FRONT_AND_BACK,osg::Vec4f(1.0, 1.0, 1.0, 0.5));//漫反射光照参数:rgba
	//void setDiffuse( Face face, const Vec4& diffuse );
	material->setSpecular(osg::Material::FRONT_AND_BACK,osg::Vec4f(1.0, 1.0, 1.0, 0.5));//镜面反射光照参数:rgba
	material->setShininess(osg::Material::FRONT_AND_BACK,10.0);//设置材料光泽度（0->127）

	//设置纹理 记得加上纹理的编号
	image = osgDB::readImageFile("Image/wyl.jpg");//文件夹必须在当前项目的文件下
	//inline osg::Image*  readImageFile(const std::string& filename)
	if(image.valid())
	{
		texture2D->setImage(image.get());//将读取的图片内容设置为纹理
	}

	//设置将设置好的属性应用在节点数据上
	geode->getOrCreateStateSet()->setAttributeAndModes(material.get(),osg::StateAttribute::ON);//<osg/StateSet> 
	// void setAttributeAndModes(StateAttribute *attribute, StateAttribute::GLModeValue value=StateAttribute::ON);
	
	//开启混合模式，设置透明度 
	geode->getOrCreateStateSet()->setMode(GL_BLEND,osg::StateAttribute::ON); //默认参数时on，最好也写上 
	//开启深度测试，使更加有层次感
	geode->getOrCreateStateSet()->setMode(GL_DEPTH_TEST,osg::StateAttribute::ON); 

	geode->getOrCreateStateSet()->setTextureAttributeAndModes(0, texture2D.get(), osg::StateAttribute::ON);
	//void setTextureAttributeAndModes(unsigned int unit,StateAttribute *attribute, StateAttribute::GLModeValue value=StateAttribute::ON);
	geode->addDrawable(shape.get());//将图元加载到 drawable
	//virtual bool addDrawable( Drawable *drawable );


	 return geode;
 }

int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;

	viewer->setSceneData(Createbox());
	return viewer->run();
}
