//osgview glider.osg 
#include"Common.h"   //�������ͷ�ļ�

#include<osgViewer/Viewer>
#include<osgDB/ReadFile>

#include<osgGA/GUIEventAdapter>
#include<osgViewer/ViewerEventHandlers>  //osgGA.lib

#include<osg/Geode>
#include<osg/ShapeDrawable>//����ͼԪ

#include<osg/MatrixTransform> //����ת��ͷ�ļ�
#include<osg/AnimationPath>//����·��ͷ�ļ�

#include<istream>


//���һ��������ʵ�־������
osg::ref_ptr<osg::Node>  MatrixOperation()//group ����ֵ���� ��Ӧ osg::Node ֦�ڵ�
{
	osg::ref_ptr<osg::Group> group = new osg::Group;
	osg::ref_ptr<osg::MatrixTransform> mat1 = new osg::MatrixTransform;
	osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("glider.osg");//�ظ�Ҫ�õĵ���д����
	osg::ref_ptr<osg::MatrixTransform> mat2 = new osg::MatrixTransform;
	osg::ref_ptr<osg::MatrixTransform> mat3 = new osg::MatrixTransform;
	osg::ref_ptr<osg::MatrixTransform> mat4 = new osg::MatrixTransform;

	//ƽ�� 
	//mat->addChild(osgDB::readNodeFile("Glider.osg"));//��mat��ӽڵ�����
	mat2->addChild(node.get());//mat2���ò�������
	mat2->setMatrix(osg::Matrix::translate(5.0, 0.0, 0.0));//����Χ��������Ƶ�(5.0, 0.0, 0.0)
	//void setMatrix(const Matrix& mat)   tanslate������ת������
	//��ת
	//ʵ�ְ뾶Ϊ5��������ת�����뽫ƽ�ƾ������ò������ó���ת����һ��child�ڵ�
	mat1->setUpdateCallback(new osg::AnimationPathCallback(osg::Vec3(3.0, 0.0, 0.0),osg::Z_AXIS, 3.0));//�Ƶ㣬���ᣬ���ٶ�
	mat1->addChild(mat2.get());//Ϊʵ����ת��ƽ�ƣ�ԭ���Ǵӣ�000������

	mat4->addChild(node.get());
	mat4->setMatrix(osg::Matrix::translate(-5.0, 0.0, 0.0));//��������ʼ��ת��
	mat3->setUpdateCallback(new osg::AnimationPathCallback(osg::Vec3(-3.0, 2.0, 3.0),osg::Z_AXIS, 3.0)); 
	mat3->addChild(mat4.get()); 

	//ʵ�ְ뾶Ϊ5��������ת�����뽫ƽ�ƾ������ò������ó���ת����һ��child�ڵ�
	group->addChild(node.get());//��һ��ģ��
	group->addChild(mat1.get());//virtual bool addChild( Node *child ); 
	group->addChild(mat3.get()); 
	
	return group;//������group
}

int main()
{
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;


	viewer->setSceneData(MatrixOperation());
	return viewer->run();//ָ��
}
