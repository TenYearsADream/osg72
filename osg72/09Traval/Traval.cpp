#include"Common.h" 
#include"Traval.h"

TravalManipulator::TravalManipulator() //构造函数：初始化视口和朝向为0
{
	m_vPosition = osg::Vec3(0, 0, 10);//视口
	m_vRotation = osg::Vec3(0, 0, 0);//朝向    注意视口和朝向的参数要设置好，不然看不到物体
	m_vStep = 0;
	m_vRotateStep = 0.0;
}

void TravalManipulator::setByMatrix(const osg::Matrixd& matrix)
{
	
}


void TravalManipulator::setByInverseMatrix(const osg::Matrixd& matrix)
{
	
}

osg::Matrixd TravalManipulator::getMatrix() const //当前视口
{
	osg::Matrix mat;
	mat.makeTranslate(m_vPosition);
	return mat * osg::Matrix::rotate(m_vRotation[0],osg::X_AXIS,m_vRotation[1],osg::Y_AXIS,m_vRotation[2],osg::Z_AXIS);
	
}

osg::Matrixd TravalManipulator::getInverseMatrix() const //当前视口的逆
{
	osg::Matrix mat;
	mat.makeTranslate(m_vPosition);
	return osg::Matrix::inverse(mat * osg::Matrix::rotate(m_vRotation[0],osg::X_AXIS,m_vRotation[1],osg::Y_AXIS,m_vRotation[2],osg::Z_AXIS));
}

bool TravalManipulator::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& us) //事件处理器，写一些操作响应
{
	switch(ea.getEventType())
	{
	case osgGA::GUIEventAdapter::KEYDOWN:
		{
			if(ea.getKey() == 'w')
			{
				m_vPosition[2] += 2;
			}
			else if(ea.getKey() == 's')
			{
				m_vPosition[2] -= 2;
			}
			else //必须加上else
			{
				
			}

		}
	}
	return false;
}
