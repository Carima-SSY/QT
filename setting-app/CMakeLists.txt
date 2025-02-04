cmake_minimum_required(VERSION 3.16)
project(MyQtApp)

# Qt 설치 경로 확인
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt")

# Qt 패키지 찾기
find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(MyQtApp src/main.cpp)

# Qt 라이브러리 연결
target_link_libraries(MyQtApp PRIVATE Qt6::Widgets)