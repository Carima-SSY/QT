cmake_minimum_required(VERSION 3.16)
project(MyQtApp)

# Qt 설치 경로 확인
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt")
#표준 설정: C++17로 빌드
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt 패키지 찾기
find_package(Qt6 REQUIRED COMPONENTS Widgets Core Network)


# AWS SDK 경로 수동 지정
set(AWS_SDK_CPP_DIR "/usr/local/aws-sdk-cpp")
include_directories(${AWS_SDK_CPP_DIR}/include)
link_directories(${AWS_SDK_CPP_DIR}/lib)


add_executable(MyQtApp src/main.cpp)


# Qt 및 AWS SDK 연결
target_link_libraries(MyQtApp PRIVATE 
    Qt6::Widgets 
    Qt6::Network
    ${AWS_SDK_CPP_DIR}/lib/libaws-cpp-sdk-s3.dylib
    ${AWS_SDK_CPP_DIR}/lib/libaws-cpp-sdk-core.dylib
)