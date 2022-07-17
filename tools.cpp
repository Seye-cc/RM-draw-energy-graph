#include "tools.h"

Graph::Graph(Mat img_, Point2i accuracy_, double refresh_time)
{
	img = img_.clone();
	background = img.clone();
	accuracy = accuracy_;
	refresh_x = (refresh_time*accuracy.x)+0.5;
	x_width = img.cols;
}

void Graph::draw_graph(Point2d actu,Scalar color, string title)
{
	//初次打印出x和y轴的范围
	if (x_temp[0]==0)
	{
		cout << "x轴的长度为: " << img.cols / accuracy.x << "秒\ty轴的长度为: " << img.rows / accuracy.y << endl;
	}
	//
	int y = actu.y*accuracy.y + 0.5;
	double delta_x = (actu.x - x_temp[0])*accuracy.x;
	int judgment = (x_temp[1]+delta_x) / x_width;
	x_temp[0] = actu.x;
	/*cout << actu << endl;*/
	//cout << delta_x << endl;
	/*cout << x_temp[1] << endl;*/
	if (refresh_temp<judgment)
	{
		refresh_temp = judgment;
		int trans_x = x_width - 1 - refresh_x;
		x_temp[1] = x_temp[1] + delta_x + trans_x+1;
		int x = int(x_temp[1]+0.5) % x_width;
		Rect stay(refresh_x - 1, 0, x_width - refresh_x, img.rows), stick(0, 0, x_width - refresh_x, img.rows);
		Mat img_temp = background.clone();
		img(stay).copyTo(img_temp(stick));
		img = img_temp.clone();
		circle(img, Point(x, y), 1, color, -1);
	}
	else
	{
		x_temp[1] = x_temp[1] + delta_x;
		int x = int(x_temp[1]+0.5) % x_width;
		circle(img, Point(x, y), 1, color, -1);
	}
	imshow(title, img);
	waitKey(1);
}