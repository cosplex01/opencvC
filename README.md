# opencvC
opencv를 C++로 이용해 본 것입니다

visual studio로 opencv를 사용하려고 할때에 미리 준비하셔야 하는 것이 있습니다
- 각각의 프로젝트 별로 준비를 하셔야 하는 내용입니다

** 조건 : x64에서 opencv가 동작됩니다
1. 링커 부분
- 입력 탭 : 추가 종속성 부분에 opencv의 라이브러리 파일을 등록합니다
  (opencv_world숫자.lib, opencv_world숫자d.lib)
- 일반 탭의 추가 라이브러리 디렉토리에 opencv의 lib디렉토리를 등록합니다
  (?:\opencv\build\x64\vc숫자큰것\lib)
  
2. 구성속성 부분
- vc++ 디렉터리 탭의 포함 디렉터리 부분에 opencv의 include폴더를 등록합니다
  (?:\opencv\build\include)
- c/c++ 탭의 일반부분의 추가 포함 디렉터리 부분에 opencv의 include폴더를 등록합니다
  (?:\opencv\build\include)
  (?:\opencv\build\include\opencv2)
