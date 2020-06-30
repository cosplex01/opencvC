import cv2
CAM_ID = 0

cap = cv2.VideoCapture(CAM_ID) #카메라 생성

if cap.isOpened() == False: #카메라 생성 확인
    print('Can\'t open the CAM(%d)' % (CAM_ID))
    exit()

#윈도우 생성 및 사이즈 변경
cv2.namedWindow('Face')

face_cascade = cv2.CascadeClassifier()
face_cascade.load('haarcascade_frontalface_default.xml')#알고리즘 파일을 읽어들임

while(True):
    #카메라에서 이미지 얻기
    ret, frame = cap.read()
    #얻어낸 이미지를 흑백으로 변경한뒤 히스토그램이 일치하는 것을 선택함
    grayframe = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    grayframe = cv2.equalizeHist(grayframe)
    #얻은 이미지에서 알고리즘을 이용해서 얼굴인식을 시도함
    faces = face_cascade.detectMultiScale(grayframe, 1.1, 3, 0, (30, 30))
    
    #인식한 이미지를 표시하기 위한 사각형 표시
    for (x,y,w,h) in faces:
        cv2.rectangle(frame,(x,y),(x+w,y+h),(0,255,0),3, 4, 0)
    
    cv2.imshow('Face',frame)
    #10ms 동안 키입력 대기
    if cv2.waitKey(10) >= 0:
        break;
#윈도우 종료
cap.release()
cv2.destroyWindow('Face')