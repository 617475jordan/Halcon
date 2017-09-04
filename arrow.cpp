#include <opencv_all.h>

void drawArrow(cv::Mat& img, cv::Point pStart, cv::Point pEnd, int len, int alpha,
	cv::Scalar& color, int thickness = 1, int lintType = 8);

int main(int argc, char** argv)
{

	Mat m(400, 400, CV_8UC3, Scalar(0, 0, 0));
	Point pStart(380, 100), pEnd(100, 250);
	Scalar lineColor(0, 255, 255);
	drawArrow(m, pStart, pEnd, 10, 45, lineColor);
	pStart = Point(100, 100);
	pEnd = Point(320, 190);
	lineColor = Scalar(0, 0, 255);
	drawArrow(m, pStart, pEnd, 25, 30, lineColor, 2, CV_AA);
	pStart = Point(200, 420);
	pEnd = Point(370, 170);
	lineColor = Scalar(255, 0, 255);
	drawArrow(m, pStart, pEnd, 17, 15, lineColor, 1, 4);
	imshow("draw arrow", m);

	waitKey();
	return 0;
}


void drawArrow(cv::Mat& img, cv::Point pStart, cv::Point pEnd, int len, int alpha, cv::Scalar& color, int thickness, int lineType)
{
	const double PI = 3.1415926;
	Point arrow;
	//���� �� �ǣ���򵥵�һ�����������ͼʾ���Ѿ�չʾ���ؼ����� atan2 ��������������棩   
	double angle = atan2((double)(pStart.y - pEnd.y), (double)(pStart.x - pEnd.x));

	//��halcon �� angle =Pi/2-angle; cos(PI*3/2-x)
	line(img, pStart, pEnd, color, thickness, lineType);

	//������Ǳߵ���һ�˵Ķ˵�λ�ã�����Ļ��������Ҫ����ͷ��ָ��Ҳ����pStart��pEnd��λ�ã� 
	arrow.x = pEnd.x + len * cos(angle + PI * alpha / 180);

	arrow.y = pEnd.y + len * sin(angle + PI * alpha / 180);

	line(img, pEnd, arrow, color, thickness, lineType);

	arrow.x = pEnd.x + len * cos(angle - PI * alpha / 180);

	arrow.y = pEnd.y + len * sin(angle - PI * alpha / 180);

	line(img, pEnd, arrow, color, thickness, lineType);
}