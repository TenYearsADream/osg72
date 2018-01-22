//osgview glider.osg 
#include"Common.h"   //�������ͷ�ļ�

#include<osgViewer/Viewer>
#include<osgDB/ReadFile>

#include<osgGA/GUIEventAdapter>
#include<osgViewer/ViewerEventHandlers>  //osgGA.lib

#include<osg/Geode>
#include<osg/ShapeDrawable>//����ͼԪ

#include<osg/Material>//��������
#include<osg/StateSet> //״̬����

#include<osg/Image>//�������
#include<osg/Texture2D> 



#include<istream>

 osg::ref_ptr<osg::Geode> Createbox()
 {
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	osg::ref_ptr<osg::TessellationHints> hints = new osg::TessellationHints;// ����
	osg::ref_ptr<osg::ShapeDrawable> shape = new osg::ShapeDrawable(new osg::Box(osg::Vec3(0.0,0.0,0.0),10.0,10.0,1.0),hints.get());//box���������ĵ㣬xyz,����
	//ShapeDrawable(Shape* shape, TessellationHints* hints=0);
	//shape:class Sphere; Box; Cone; Cylinder; Capsule; InfinitePlane;TriangleMesh; ConvexHull; HeightField;
	osg::ref_ptr<osg::Material> material = new osg::Material;// ����ָ��

	osg::ref_ptr<osg::Texture2D> texture2D = new osg::Texture2D;
	osg::ref_ptr<osg::Image> image = new osg::Image;

	//������ɫ
	shape->setColor(osg::Vec4f(0.5, 0.5, 0.5, 0.5));
	// void setColor(const Vec4& color); ShapeDrawable��Ĺ��к���
	
	//���þ���
	hints->setDetailRatio(0.5);

	//���ò�������
	material->setAmbient(osg::Material::FRONT_AND_BACK,osg::Vec4f(1.0, 1.0, 1.0, 0.5));//�������ղ���:rgba
	//void setAmbient( Face face, const Vec4& ambient );
	material->setDiffuse(osg::Material::FRONT_AND_BACK,osg::Vec4f(1.0, 1.0, 1.0, 0.5));//��������ղ���:rgba
	//void setDiffuse( Face face, const Vec4& diffuse );
	material->setSpecular(osg::Material::FRONT_AND_BACK,osg::Vec4f(1.0, 1.0, 1.0, 0.5));//���淴����ղ���:rgba
	material->setShininess(osg::Material::FRONT_AND_BACK,10.0);//���ò��Ϲ���ȣ�0->127��

	//�������� �ǵü�������ı��
	image = osgDB::readImageFile("Image/wyl.jpg");//�ļ��б����ڵ�ǰ��Ŀ���ļ���
	//inline osg::Image*  readImageFile(const std::string& filename)
	if(image.valid())
	{
		texture2D->setImage(image.get());//����ȡ��ͼƬ��������Ϊ����
	}

	//���ý����úõ�����Ӧ���ڽڵ�������
	geode->getOrCreateStateSet()->setAttributeAndModes(material.get(),osg::StateAttribute::ON);//<osg/StateSet> 
	// void setAttributeAndModes(StateAttribute *attribute, StateAttribute::GLModeValue value=StateAttribute::ON);
	
	//�������ģʽ������͸���� 
	geode->getOrCreateStateSet()->setMode(GL_BLEND,osg::StateAttribute::ON); //Ĭ�ϲ���ʱon�����Ҳд�� 
	//������Ȳ��ԣ�ʹ�����в�θ�
	geode->getOrCreateStateSet()->setMode(GL_DEPTH_TEST,osg::StateAttribute::ON); 

	geode->getOrCreateStateSet()->setTextureAttributeAndModes(0, texture2D.get(), osg::StateAttribute::ON);
	//void setTextureAttributeAndModes(unsigned int unit,StateAttribute *attribute, StateAttribute::GLModeValue value=StateAttribute::ON);
	geode->addDrawable(shape.get());//��ͼԪ���ص� drawable
	//virtual bool addDrawable( Drawable *drawable );


	 return geode;
 }

int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;

	viewer->setSceneData(Createbox());
	return viewer->run();
}
