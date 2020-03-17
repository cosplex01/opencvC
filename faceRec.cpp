#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/core/core_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <iostream>

using namespace cv;
using namespace std;

String face_cascade = "D://opencv//sources//data//haarcascades//haarcascade_frontalface_alt.xml"; //얼굴부분 인식 알고리즘
String eye_cascade = "D://opencv//sources//data//haarcascades//haarcascade_eye.xml"; //눈 부분 인식 알고리즘
String img_name = "face.jpg"; //사용할 파일명

//인식알고리즘 변수지정
CascadeClassifier face; 
CascadeClassifier eye;

int main()
{
	// 메트릭스에 파일의 내용을 담는다
	Mat img = imread(img_name);
	// 제대로 파일을 읽었으며, 인식부위를 찾았는가 확인하는 루틴
	if (img.data == NULL)
	{
		cout << img_name << "이미지 내용이 없습니다" << endl;
		return -1;
	}
	if (!face.load(face_cascade) || !eye.load(eye_cascade))
	{
		cout << "인식할 구역이 없습니다" << endl;
		return -1;
	}

	#pragma region faceRead
	Mat gray; //인식부위를 저장할 메트릭스를 생성
	cvtColor(img,gray,CV_RGB2GRAY); //이진화를 작동시켜 인식가능하게 처리

	vector<Rect> face_pos; //얼굴부위 지정
	face.detectMultiScale(gray,face_pos,1.1,3,0 | CASCADE_SCALE_IMAGE, Size(10,10)); //지정된 얼굴부위 검출
	//얼굴영역 표시
	for (int i =0; i<(int)face_pos.size();i++)
	{
		//얼굴영역 표시부
		rectangle(img, face_pos[i],Scalar(0,255,0),2);
	}
	#pragma endregion	

	#pragma region EyeRead
	for (int i=0;i<(int)face_pos.size();i++)
	{
		vector<Rect> eye_pos; //눈위치 지정
		
		Mat roi = gray(face_pos[i]); //눈위치 검색부위 설정
		eye.detectMultiScale(roi, eye_pos, 1.1, 3, 0 | CASCADE_SCALE_IMAGE, Size(10,10)); //지정된 눈부위 검출
		//눈영역 표시
		for (int j=0; j<(int)eye_pos.size();j++)
		{
			//눈영역의 중앙점
			Point center(face_pos[i].x + eye_pos[j].x + (eye_pos[j].width / 2),
				face_pos[i].y+ eye_pos[j].y + (eye_pos[j].height / 2));
			//눈영역의 표시부
			int radius = cvRound((eye_pos[j].width + eye_pos[j].height)*0.2);
			circle(img,center,radius,Scalar(0,0,255),2);
		}
	}
	#pragma	endregion

	namedWindow("검출");
	imshow("검출", img);

	waitKey();
	return 0;
}