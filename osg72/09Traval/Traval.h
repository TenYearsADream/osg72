#include<osgViewer/Viewer>
#include<osgDB/ReadFile>

#include<osgGA/GUIEventAdapter>
#include<osgViewer/ViewerEventHandlers>  //osgGA.lib

#include<osg/Geode>
#include<osg/ShapeDrawable>//����ͼԪ

#include<osg/MatrixTransform> //����ת��ͷ�ļ�
#include<osg/AnimationPath>//����·��ͷ�ļ�

#include<osg/MatrixTransform>
#include<osg/PositionAttitudeTransform>
#include<osg/Matrixd>
#include<istream>

//����һ���������࣬��CameraManipulator���濽����غ���

//class TravalManipulator :public MatrixManipulator ����
class TravalManipulator :public osgGA::CameraManipulator   //��CameraManipulator
{
public:
		TravalManipulator();
public:
		//ʵ�ֵõ�����Ľӿ�
	      /** ���õ�ǰ�ӿ�set the position of the matrix manipulator using a 4x4 Matrix.*/
        virtual void setByMatrix(const osg::Matrixd& matrix);

        /** ���õ�ǰ�ӿ������set the position of the matrix manipulator using a 4x4 Matrix.*/
        virtual void setByInverseMatrix(const osg::Matrixd& matrix);

        /** �õ���ǰ�ӿ�get the position of the manipulator as 4x4 Matrix.*/
        virtual osg::Matrixd getMatrix() const;

        /** �õ���ǰ�ӿڵ������get the position of the manipulator as a inverse matrix of the manipulator, typically used as a model view matrix.*/
        virtual osg::Matrixd getInverseMatrix() const;

		virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& us);//���������ռ�osgGA
private:
	//�ӿ�
	osg::Vec3 m_vPosition;
	//����
	osg::Vec3 m_vRotation;
	int m_vStep;
	float m_vRotateStep;
	
};