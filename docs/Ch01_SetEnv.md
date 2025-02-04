# MAC - QT Environment Setting (in VS Code)

## Install QT
1. Homebrew 설치 
    * 설치 확인 
        - 이미 설치되어 있는지 확인
        - 해당 명령어 터미널에 입력: "brew --version" 
        - 명령어 입력 후, 버전 명이 표기되면 올바르게 설치된 것

    * 설치 방법 
        - 해당 명령어 터미널에 입력: "/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
     
2. QT & C++ 개발 환경 설치 
    * 설치 방법 
        - 해당 명령어 순서대로 입력:
            1. "brew install qt cmake ninja"
            2. "brew install llvm"  
                - 최신 clang 컴파일러 설치 (선택 사항)

    * 설치 확인
        - 해당 명령어 각각 입력하여 설치된 버전명이 표기되는지 확인
        - 명령어:
            1. "clang --version"
            2. "cmake --version"


## Setting VS Code
1. Extension Program 설치
    * C/C++ (Microsoft)
    * CMake Tools
    * Qt VSCode Tools (Qt 관련 지원 추가)
    * CodeLLDB (디버깅 지원)

## Start QT Project 
1. Project Directory 생성 및 이동
    * 예시(터미널 명령어): 
        1. "mkdir ~/QtProjects/MyApp"
        2. "cd ~/QtProjects/MyApp"

2. CMakeLists.txt 파일 생성 및 내용 입력
    * 파일명은 무조건 동일해야 함
    * 해당 파일 내 입력 내용:
    <img src="./CMakeLists_입력내용.png">
        


