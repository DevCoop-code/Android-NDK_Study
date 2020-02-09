# JNI
Java Native Interface의 약어로 Android가 Java 또는 Kotlin 프로그래밍 언어로 작성된 관리 코드에서 컴파일 하는 바이트코드가 C/C++로 작성된 네이티브 코드와 상호 작용할 수 있는 방법을 정의
https://developer.android.com/training/articles/perf-jni

## Native Library
표준 System.loadLibrary를 사용하여 공유 라이브러리에서 네이티브 코드를 로드하는 것이 가능<br><br>

- Runtime에서 Native Method를 찾는 두 가지 방법
  - <b>RegisterNatives</b>를 사용하여 명시적으로 등록
    - 장점: 기호가 있는지 미리 검사할 뿐 아니라 JNI_OnLoad 이외의 항목을 내보내지 않으므로 더 작고 빠른 공유 라이브러리를 가질 수 있음
  - <b>dlsym</b>를 사용하여 런타임을 통해 동적으로 검색
  
  <br>
  <b>RegisterNatives</b> 사용을 위해선 아래를 수행<br>
  1. JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) 함수를 제공<br>
  2. JNI_OnLoad에서 RegisterNatives를 사용하여 모든 Native Method를 등록<br>
  3. 사용자 JNI_OnLoad만 라이브러리에서 내보내도록 -fvisibility=hidden을 사용하여 빌드. 이렇게 하면 더 빠르고 작은 코드가 생성, 앱에 로드되는 다른 라이브러리와 잠재적 충돌을 피할 수 있음

## JavaVM 및 JNIEnv
JNI는 두 개의 주요 데이터 구조인 <b>JavaVM</b>과 <b>JNIEnv</b>를 정의. 둘 다 본질적으론 함수 테이블에 대한 포인터의 포인터.
JavaVM은 JavaVM을 만들고 삭제할 수 있는 '호출 인터페이스' 함수를 제공. 이론적으론 Process당 여러 개의 JavaVM을 사용할 수 있지만 Android에서는 하나만 허용
JNIEnv는 대부분의 JNI 함수를 제공. 네이티브 함수는 모두 JNIEnv를 첫 번째 인수로 받음