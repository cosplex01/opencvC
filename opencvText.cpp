#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	// 컬러 이미지를 저장할 Mat 개체를 생성합니다.
	int img_w = 640;
	int img_h = 480;
	// 이미지의 형식을 지정한다
	Mat img(img_h, img_w, CV_8UC3, Scalar(0, 0, 0));

	Scalar red(0, 0, 255);
	Scalar green(0, 255, 0);
	Scalar blue(255, 0, 0);
	Scalar white(255, 255, 255);
	Scalar yellow(0, 255, 255);
	Scalar cyan(255, 255, 0);
	Scalar magenta(255, 0, 255);
	// 글자를 보여줄 포인트지점 설정
	int center_x = int(img_w / 2.0);
	int center_y = int(img_h / 2.0);

	int thickness = 2; //글자두께
	Point location(center_x - 200, center_y - 100);
	int font = FONT_HERSHEY_SCRIPT_SIMPLEX;// 산세리프 필기체 폰트
	double fontScale = 3.5; //글자 크기
	putText(img, "OpenCV", location, font, fontScale, yellow, thickness);

	location = Point(center_x - 150, center_y + 20);
	font = FONT_ITALIC; // 이텔릭 폰트
	fontScale = 2;
	putText(img, "Hello Sample", location, font, fontScale, red, thickness);

	location = Point(center_x - 250, center_y + 100);
	font = FONT_HERSHEY_SIMPLEX;  // 산세리프 심플 폰트
	fontScale = 1.5;
	putText(img, "OpenCV TextTest", location, font, fontScale, blue, thickness);

	location = Point(center_x - 250, center_y + 150);
	font = FONT_HERSHEY_COMPLEX; // 산세리프 일반화 폰트 
	fontScale = 1.2;
	putText(img, "Covid19!!", location, font, fontScale, green, thickness);

	imshow("drawing", img);
	waitKey(0);

	return 0;
}