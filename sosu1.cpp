#include <opencv2/opencv.hpp>
#include <iostream>


using namespace cv;
using namespace std;
/*
// 영상을 재생하기 위해서는 미리 영상이 있어야 합니다
// 영상을 재생하기 위해서는 영상 저장하는 부분이 사용되지 않습니다
*/

int main()
{
	Mat img_color;

	//비디오 캡쳐 초기화
	VideoCapture cap("output.avi"); //cap("파일명")은 캡쳐한 영상을 재생하는 것임
	if (!cap.isOpened()) {
		cerr << "에러 - 카메라를 열 수 없습니다.\n";
		return -1;
	}
	
	/*
	// 동영상 파일을 저장하기 위한 준비  
	Size size = Size((int)cap.get(CAP_PROP_FRAME_WIDTH),
		(int)cap.get(CAP_PROP_FRAME_HEIGHT));

	VideoWriter writer;
	double fps = 30.0;
	writer.open("output.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size, true);
	if (!writer.isOpened())
	{
		cout << "동영상을 저장하기 위한 초기화 작업 중 에러 발생" << endl;
		return 1;
	}*/
	
	while (1)
	{
		cap.read(img_color);
		if (img_color.empty()) {
			cerr << "빈 영상이 캡쳐되었습니다.\n";
			break;
		}

		//동영상 파일에 한 프레임을 저장함.  
		//writer.write(img_color);
		//영상을 화면에 보여줍니다
		imshow("Color", img_color);
		//ESC키로 영상 캡쳐 루프를 종료합니다
		if (waitKey(25) >= 0)
			break;
	}
	return 0;
}