#include<osgViewer/Viewer>
#include<osgDB/ReadFile>

#include<osgGA/GUIEventAdapter>
#include<osgViewer/ViewerEventHandlers>  //osgGA.lib

#include<osg/Geode>
#include<osg/ShapeDrawable>//绘制图元

#include<osg/MatrixTransform> //矩阵转换头文件
#include<osg/AnimationPath>//动画路径头文件

#include<osg/MatrixTransform>
#include<osg/PositionAttitudeTransform>
#include<osg/Matrixd>
#include<istream>

//构造一个操作器类，从CameraManipulator里面拷贝相关函数

//class TravalManipulator :public MatrixManipulator 错误
class TravalManipulator :public osgGA::CameraManipulator   //在CameraManipulator
{
public:
		TravalManipulator();
public:
		//实现得到矩阵的接口
	      /** 设置当前视口set the position of the matrix manipulator using a 4x4 Matrix.*/
        virtual void setByMatrix(const osg::Matrixd& matrix);

        /** 设置当前视口逆矩阵set the position of the matrix manipulator using a 4x4 Matrix.*/
        virtual void setByInverseMatrix(const osg::Matrixd& matrix);

        /** 得到当前视口get the position of the manipulator as 4x4 Matrix.*/
        virtual osg::Matrixd getMatrix() const;

        /** 得到当前视口的逆矩阵get the position of the manipulator as a inverse matrix of the manipulator, typically used as a model view matrix.*/
        virtual osg::Matrixd getInverseMatrix() const;

		virtual bool handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& us);//加上命名空间osgGA
private:
	//视口
	osg::Vec3 m_vPosition;
	//朝向
	osg::Vec3 m_vRotation;
	int m_vStep;
	float m_vRotateStep;
	
};