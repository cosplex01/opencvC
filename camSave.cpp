#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp> // for cvtColor
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//영상을 담을 메트릭스 생성
	Mat frame;
	//웹켐 캡처용 변수 지정
	VideoCapture cap(0);
	if (!cap.isOpened())
	{
		cerr << "카메라를 열 수 없습니다." << endl;
		return -1;
	}
	//캡쳐한영상을 저장할 세부변수 지정
	int fps = 30;
	int width = cap.get(CAP_PROP_FRAME_WIDTH);
	int height = cap.get(CAP_PROP_FRAME_HEIGHT);
	int fourcc = VideoWriter::fourcc('M', 'J', 'P', 'G');
	//캡쳐한영상을 담을 변수지정
	VideoWriter outputVideo;
	outputVideo.open("output.avi", fourcc, fps, Size(width, height), true);
	
	while (1)
	{
		cap.read(frame);
		if (frame.empty())
		{
			cerr << "캡쳐 실패" << endl;
			break;
		}

		//cvtColor(frame, frame, COLOR_BGR2GRAY);

		imshow("Live", frame);
		// 메트릭스에 저장된 켑쳐영상을 저장함
		outputVideo.write(frame);

		if (waitKey(1) >= 0)
			break;
	}
	// 캡쳐영상 저장작업 헤제
	outputVideo.release();

	return 0;
}