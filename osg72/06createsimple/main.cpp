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

#include<osg/LineWidth> //�����߿�

#include<istream>

 //������ͼԪ
 osg::ref_ptr<osg::Geode> CreatSimple() //����Ҷ�ӽڵ�
 {
	 osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	 osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;//��Ҫ���ļ��ζ���
	 
	
	//����һЩ����
	osg::ref_ptr<osg::Vec3Array>  coords = new osg::Vec3Array;//����
	osg::ref_ptr<osg::Vec4Array>  colors = new osg::Vec4Array;//������ɫ
	osg::ref_ptr<osg::Vec3Array>  normal = new osg::Vec3Array;//��������һ�����ӵ��η�������ܶ�
	osg::ref_ptr<osg::LineWidth>  linewidth = new osg::LineWidth; // �߿� 


	geode->addDrawable(geom.get());//��ͼԪ���ص�ԭadddrawable
	
	//��͸����
    geode->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	
	//�����߿�
	linewidth->setWidth(15.0); //void setWidth(float width);
	//�߿������Ҫд���ڵ�����ȥ
	geode->getOrCreateStateSet()->setAttributeAndModes(linewidth.get(), osg::StateAttribute::ON) ;

	//���ö���,�󶨶����������VAO
	geom->setVertexArray(coords.get());//void setVertexArray(Array* array);
	 //���ö���Ĺ�����ʽ��ͼԪ��
	geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINE_LOOP, 0, 4)); //QUADS
		 //bool addPrimitiveSet(PrimitiveSet* primitiveset);
	
	//���� ��ɫ,����ɫ���������VAO
	//���������˰��죬ע�⿴����������ɫ���� geom->setVertexArray(colors.get());//��
	geom->setColorArray(colors.get());
	geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	 
	//���÷�����
	geom->setNormalArray(normal.get());
	geom->setNormalBinding(osg::Geometry::BIND_OVERALL);



	//���붥������
	coords->push_back(osg::Vec3(-10.0, 5.0, -10.0));//��һ���㣺���� ���Ϊ5
	coords->push_back(osg::Vec3( 10.0, 5.0, -10.0));//����
	coords->push_back(osg::Vec3(10.0, 5.0, 10.0));//����
	coords->push_back(osg::Vec3(-10.0, 5.0, 10.0));//����

	 
	//��ɫ����
	colors->push_back(osg::Vec4f(1.0f, 0.0f,0.0f, 0.5f));
	colors->push_back(osg::Vec4f(0.0f, 1.0f,0.0f, 0.5f));
	colors->push_back(osg::Vec4f(0.0f, 0.0f,1.0f, 0.5f));
	colors->push_back(osg::Vec4f(1.0f, 1.0f,0.0f, 0.5f));

	//ѹ�뷨����
	normal->push_back(osg::Vec3(0.0, -1.0, 0.0));  //�ڳ��������������Ƚ���

	return geode;
 }
int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	//���������һ������������ʾ͸����
	osg::ref_ptr<osg::Group> group = new osg::Group;//һ����
	group->addChild(osgDB::readNodeFile("cow.osg")); //��Ϊ���յ�ţ
	group->addChild(CreatSimple());

	viewer->setSceneData(group.get());//���ó���Ϊ������
	return viewer->run();
}
