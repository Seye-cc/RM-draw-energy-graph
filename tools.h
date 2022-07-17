#ifndef TOOLS_H
#define TOOLS_H

#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

/*
用来画图的类：
	创建格式 ：Graph(Mat img_, Point2i accuracy_, double refresh_time_)
	Mat img_ ：画图的图片。
	Point2i accuracy_ ：画图的精度，例如 Point2i(40,4)——表示画图精度为x轴是40像素/秒，y轴是4像素/度。
	float refresh_x_ ：刷新后x轴的留空，单位：秒。
*/
class Graph
{
private:
	Mat img,background;
	int x_width;
	double x_temp[2];//[0]是上一次的时间，[1]上一次像素位置
	int refresh_temp = 0;//判断刷新的条件
	Point2i accuracy;//精度
	int refresh_x;//刷新后x轴的留空
public:
	/*
	Mat img ：画图的图片。
	Point2i accuracy ：画图的精度，例如 Point2i(40,4)——表示画图精度为x轴是40像素/秒，y轴是4像素/度。
	float refresh_x ：刷新后x轴的留空，单位：秒。
	*/
	Graph(Mat img_, Point2i accuracy_, double refresh_time_);
	/*
	Point2d actu ：输入的实际坐标，x是时间，y是速度。
	Scalar color ：曲线的颜色。
	string title ：窗口标题
	*/
	void draw_graph(Point2d actu, Scalar color, string title);
};

#endif