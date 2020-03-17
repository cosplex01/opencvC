#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	// 메트릭스에 영상파일을 담을 구조체 생성
	Mat frame;
	// 영상파일 이름을 지정한다[읽어들일 파일명]
	VideoCapture cap("output.avi");
	if (!cap.isOpened())
	{
		cerr << "카메라를 열 수 없습니다." << endl;
		return -1;
	}
	
	while (1)
	{
		// 구조체에 영상파일을 담는다
		cap.read(frame);
		if (frame.empty())
		{
			cerr << "캡쳐 실패" << endl;
			break;
		}
		// 구조체에 담은내용을 창에 보여준다
		imshow("Live", frame);
		// 어떠한 키보드입력을 받으면 루프문 벗어남
		if (waitKey(30) >= 0)
			break;
	}
	return 0;
}