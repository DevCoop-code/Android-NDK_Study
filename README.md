# Android NDK Guide
NDK는 Android에서 C 및 C++ 코드를 사용할 수 있게 해주는 일련의 도구 모음

## NDK 및 도구
앱의 Native code를 컴파일하고 디버깅하기 위한 구성요소
- <b>Android NDK(Native Development Kit)</b><br> Android에서 C 및 C++ 코드를 사용할 수 있도록 해주는 도구 모음
- <b>CMake</b><br> 
Gradle과 함께 작동하여 Native Library를 빌드하는 외부 빌드 도구
ndk-build만 사용시 필요하지 않음
- <b>LLDB</b><br>
Android studio에서 네이티브 코드를 디버깅 하는데 사용하는 디버거

## NDK 프로젝트 빌드
NDK로 코드를 빌드하는 방법에는 3가지 방법이 존재<br>
- Make 기반 ndk-build
- CMake
- 독립 실행형 도구 모음

### Make 기반 ndk-build
https://developer.android.com/ndk/guides/ndk-build

### CMake
https://developer.android.com/ndk/guides/cmake


#### 용어 정리
- Native Shared Library: NDK에서는 개발자의 C/C++ 소스 코드에서 이러한 라이브러리 또는 .so파일을 빌드
- Native Static Library: NDK에서는 개발자의 다른 라이브러리에 연결할 수 있는 정적 라이브러리 또는 .a파일을 빌드
- ABI(Android Binary Interface): ABI앱의 기계어 코드가 런타임 시 시스템과 어떻게 상호작용할지를 정확히 정의. NDK는 이 정의에 따라 .so파일을 빌드, 다양한 ABI는 서로 다른 Architecture에 대응. 즉, NDK에는 32비트 ARM, AArch64, x86, x86-64용 ABI지원이 포함되어 있습니다.