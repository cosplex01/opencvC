#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

#define CAM_WIDTH 1280
#define CAM_HEIGHT 720

// 외부함수로 메인 작업을 분할
void detectAndDisplay(Mat frame);
// 전역변수 설정
String face_cascade_name;
CascadeClassifier face_cascade;
String window_name = "Face detection";
// 메인함수 부분
int main(int argc, const char** argv)
{
    //화면 인식 알고리즘 파일의 내용을 읽어들임
    face_cascade_name = "d:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt.xml";
    if (!face_cascade.load(face_cascade_name)) { printf("--(!)Error loading face cascade\n"); return -1; };

    VideoCapture cam(0);
    Mat frame;
    //입력받는 화면의 크기를 결정
    cam.set(CAP_PROP_FRAME_WIDTH, CAM_WIDTH);
    cam.set(CAP_PROP_FRAME_HEIGHT, CAM_HEIGHT);
    //화면 입력장치 작동되지 않을때
    if (!cam.isOpened()) { printf("--(!)Error opening video cam\n"); return -1; }
    //영상 데이터를 정상적으로 수신할때
    while (cam.read(frame))
    {
        if (frame.empty())
        {
            printf(" --(!) No cam frame -- Break!");
            break;
        }

        detectAndDisplay(frame); //<-영상인식 및 표시담당 함수
        char c = (char)waitKey(10);
        if (c == 27) { break; }
    }
    return 0;
}
// 영상인식 및 표시를 담당
void detectAndDisplay(Mat frame)
{
    std::vector<Rect> faces;
    Mat frame_gray;
    //화상 이진화 처리
    cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
    equalizeHist(frame_gray, frame_gray);
    //화상인식 알고리즘을 이용한 분류작업 실시
    face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
    //인식처리된 부분을 표시하는 부분
    for (size_t i = 0; i < faces.size(); i++)
    {
        Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
        ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2),
            0, 0, 360, Scalar(0, 0, 255), 4, 8, 0);
    }
    imshow(window_name, frame);
}
