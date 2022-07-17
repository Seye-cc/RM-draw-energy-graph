#ifndef TOOLS_H
#define TOOLS_H

#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

/*
������ͼ���ࣺ
	������ʽ ��Graph(Mat img_, Point2i accuracy_, double refresh_time_)
	Mat img_ ����ͼ��ͼƬ��
	Point2i accuracy_ ����ͼ�ľ��ȣ����� Point2i(40,4)������ʾ��ͼ����Ϊx����40����/�룬y����4����/�ȡ�
	float refresh_x_ ��ˢ�º�x������գ���λ���롣
*/
class Graph
{
private:
	Mat img,background;
	int x_width;
	double x_temp[2];//[0]����һ�ε�ʱ�䣬[1]��һ������λ��
	int refresh_temp = 0;//�ж�ˢ�µ�����
	Point2i accuracy;//����
	int refresh_x;//ˢ�º�x�������
public:
	/*
	Mat img ����ͼ��ͼƬ��
	Point2i accuracy ����ͼ�ľ��ȣ����� Point2i(40,4)������ʾ��ͼ����Ϊx����40����/�룬y����4����/�ȡ�
	float refresh_x ��ˢ�º�x������գ���λ���롣
	*/
	Graph(Mat img_, Point2i accuracy_, double refresh_time_);
	/*
	Point2d actu �������ʵ�����꣬x��ʱ�䣬y���ٶȡ�
	Scalar color �����ߵ���ɫ��
	string title �����ڱ���
	*/
	void draw_graph(Point2d actu, Scalar color, string title);
};

#endif