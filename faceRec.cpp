#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/core/core_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <iostream>

using namespace cv;
using namespace std;

String face_cascade = "D://opencv//sources//data//haarcascades//haarcascade_frontalface_alt.xml"; //�󱼺κ� �ν� �˰���
String eye_cascade = "D://opencv//sources//data//haarcascades//haarcascade_eye.xml"; //�� �κ� �ν� �˰���
String img_name = "face.jpg"; //����� ���ϸ�

//�νľ˰��� ��������
CascadeClassifier face; 
CascadeClassifier eye;

int main()
{
	// ��Ʈ������ ������ ������ ��´�
	Mat img = imread(img_name);
	// ����� ������ �о�����, �νĺ����� ã�Ҵ°� Ȯ���ϴ� ��ƾ
	if (img.data == NULL)
	{
		cout << img_name << "�̹��� ������ �����ϴ�" << endl;
		return -1;
	}
	if (!face.load(face_cascade) || !eye.load(eye_cascade))
	{
		cout << "�ν��� ������ �����ϴ�" << endl;
		return -1;
	}

	#pragma region faceRead
	Mat gray; //�νĺ����� ������ ��Ʈ������ ����
	cvtColor(img,gray,CV_RGB2GRAY); //����ȭ�� �۵����� �νİ����ϰ� ó��

	vector<Rect> face_pos; //�󱼺��� ����
	face.detectMultiScale(gray,face_pos,1.1,3,0 | CASCADE_SCALE_IMAGE, Size(10,10)); //������ �󱼺��� ����
	//�󱼿��� ǥ��
	for (int i =0; i<(int)face_pos.size();i++)
	{
		//�󱼿��� ǥ�ú�
		rectangle(img, face_pos[i],Scalar(0,255,0),2);
	}
	#pragma endregion	

	#pragma region EyeRead
	for (int i=0;i<(int)face_pos.size();i++)
	{
		vector<Rect> eye_pos; //����ġ ����
		
		Mat roi = gray(face_pos[i]); //����ġ �˻����� ����
		eye.detectMultiScale(roi, eye_pos, 1.1, 3, 0 | CASCADE_SCALE_IMAGE, Size(10,10)); //������ ������ ����
		//������ ǥ��
		for (int j=0; j<(int)eye_pos.size();j++)
		{
			//�������� �߾���
			Point center(face_pos[i].x + eye_pos[j].x + (eye_pos[j].width / 2),
				face_pos[i].y+ eye_pos[j].y + (eye_pos[j].height / 2));
			//�������� ǥ�ú�
			int radius = cvRound((eye_pos[j].width + eye_pos[j].height)*0.2);
			circle(img,center,radius,Scalar(0,0,255),2);
		}
	}
	#pragma	endregion

	namedWindow("����");
	imshow("����", img);

	waitKey();
	return 0;
}