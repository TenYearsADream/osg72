#include"Common.h" 
#include"Traval.h"

TravalManipulator::TravalManipulator() //���캯������ʼ���ӿںͳ���Ϊ0
{
	m_vPosition = osg::Vec3(0, 0, 10);//�ӿ�
	m_vRotation = osg::Vec3(0, 0, 0);//����    ע���ӿںͳ���Ĳ���Ҫ���úã���Ȼ����������
	m_vStep = 0;
	m_vRotateStep = 0.0;
}

void TravalManipulator::setByMatrix(const osg::Matrixd& matrix)
{
	
}


void TravalManipulator::setByInverseMatrix(const osg::Matrixd& matrix)
{
	
}

osg::Matrixd TravalManipulator::getMatrix() const //��ǰ�ӿ�
{
	osg::Matrix mat;
	mat.makeTranslate(m_vPosition);
	return mat * osg::Matrix::rotate(m_vRotation[0],osg::X_AXIS,m_vRotation[1],osg::Y_AXIS,m_vRotation[2],osg::Z_AXIS);
	
}

osg::Matrixd TravalManipulator::getInverseMatrix() const //��ǰ�ӿڵ���
{
	osg::Matrix mat;
	mat.makeTranslate(m_vPosition);
	return osg::Matrix::inverse(mat * osg::Matrix::rotate(m_vRotation[0],osg::X_AXIS,m_vRotation[1],osg::Y_AXIS,m_vRotation[2],osg::Z_AXIS));
}

bool TravalManipulator::handle(const osgGA::GUIEventAdapter& ea,osgGA::GUIActionAdapter& us) //�¼���������дһЩ������Ӧ
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
			else //�������else
			{
				
			}

		}
	}
	return false;
}
