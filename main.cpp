#include<opencv2/opencv.hpp>
#include<iostream>
#include"tools.h"

using namespace cv;
using namespace std;
void main()
{
	Mat img(600, 1200, CV_8UC3, Scalar::all(0));
	Point accuracy(40, 4);
	Graph graph(img, accuracy, 0.1);
	clock_t start, finish;
	start = clock();
	double t = 0;
	while (t+1)
	{
		double velocity = ((0.785 * sin(1.884 * t) + 1.305) * 180 / 3.14);
		graph.draw_graph(Point2d(t, velocity), Scalar(0, 255, 0), "test");
		finish = clock();
		//t = double(finish - start) / CLOCKS_PER_SEC;
		t += 0.01;
		/*cout << t << endl;*/
	}
}