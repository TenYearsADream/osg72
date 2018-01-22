#include"Common.h" 
#include<osgDB/ReadFile>
#include<osgViewer/Viewer>
#include<osg/Node>
#include<osg/MatrixTransform>
osg::ref_ptr<osg::Node> Translation() //֦�ڵ� 
{
    osg::ref_ptr<osg::Group> root = new osg::Group();   
    osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("cow.osg");//����Ĭ�ϵ�ģ��    
    osg::ref_ptr<osg::MatrixTransform> trans1 = new osg::MatrixTransform();
    osg::ref_ptr<osg::MatrixTransform> trans2 = new osg::MatrixTransform();
    
	trans1->addChild(node.get());//����ָ��ָ��Ĳ������ݣ�Ȼ������ƽ����ת����
	trans1->setMatrix(osg::Matrix::translate(0,0,10));//ƽ�Ʋ���

	trans2->addChild(node.get());//����ָ��ָ��Ĳ�������
	trans2->setMatrix(osg::Matrix::translate(0,0,-10));//ƽ�Ʋ���  

    root->addChild(node.get());//��ʾ�ĵ�һ��ģ��
    root->addChild(trans1.get());//ƽ�ƺ��ģ��
    root->addChild(trans2.get());//ƽ�ƺ��ģ��
	return root;
}
osg::ref_ptr<osg::Node> Zoom() //֦�ڵ� 
{
    osg::ref_ptr<osg::Group> root = new osg::Group();   
    osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("cow.osg");//����Ĭ�ϵ�ģ��    
    osg::ref_ptr<osg::MatrixTransform> zoom1 = new osg::MatrixTransform();
    osg::ref_ptr<osg::MatrixTransform> zoom2 = new osg::MatrixTransform();
    
	zoom1->addChild(node.get());//����ָ��ָ��Ĳ�������,Ȼ��������ƽ������
	zoom1->setMatrix(osg::Matrix::scale(0.5,0.5,0.5)*osg::Matrix::translate(0,-10,0));
	
	zoom2->addChild(node.get());//����ָ��ָ��Ĳ�������
	zoom2->setMatrix(osg::Matrix::scale(2.0,2.0,2.0)*osg::Matrix::translate(0,10,0));	  

    root->addChild(node.get());//��ʾ�ĵ�һ��ģ��
    root->addChild(zoom1.get());//ƽ�ƺ��ģ��
    root->addChild(zoom2.get());//ƽ�ƺ��ģ��
	return root;
}
osg::ref_ptr<osg::Node> Rotate() //֦�ڵ� 
{
    osg::ref_ptr<osg::Group> root = new osg::Group();   
    osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("cow.osg");//����Ĭ�ϵ�ģ��    
    osg::ref_ptr<osg::MatrixTransform> rotate1 = new osg::MatrixTransform();
    osg::ref_ptr<osg::MatrixTransform> rotate2 = new osg::MatrixTransform();
    
	rotate1->addChild(node.get());//����ָ��ָ��Ĳ�������,Ȼ��������ƽ����ת���ž���
	rotate1->setMatrix(osg::Matrix::rotate(osg::DegreesToRadians(-90.0),3,3,3));
	//�Ƶ���תָ���ǶȺ�ֹͣ����̬��ת������һ����Ŀ
	rotate2->addChild(node.get());//����ָ��ָ��Ĳ�������
	rotate2->setMatrix(osg::Matrix::rotate(osg::DegreesToRadians(90.0),0,1,0));	  

    root->addChild(node.get());//��ʾ�ĵ�һ��ģ��
    root->addChild(rotate1.get());//ƽ�ƺ��ģ��
    root->addChild(rotate2.get());//ƽ�ƺ��ģ��
	return root;
}
int main()
{

	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	viewer->setUpViewInWindow( 100, 100, 800, 600, 0 ); //���ɷ�ȫ����ͼ,���Ͻ�Ϊ��0��0��
	//void setUpViewInWindow(int x, int y, int width, int height, unsigned int screenNum=0);

	viewer->setSceneData(Translation());
	
	return viewer->run();//ָ��
}
