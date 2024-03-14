#include <stdio.h>

// 공백을 출력하는 함수
void printSpaces(int numSpaces) 
{
    for (int i = 0; i < numSpaces; i++) 
    { // numSpaces만큼 반복
        printf(" "); // 공백 출력
    }
}

// 별표를 출력하는 함수
void printStars(int numStars) 
{
    for (int i = 0; i < numStars; i++) 
    { // numStars만큼 반복
        printf("*"); // 별표 출력
    }
    printf("\n"); // 별표 출력 후 줄바꿈
}

// 피라미드를 출력하는 함수
void printPyramid(int height) 
{
    for (int i = 1; i <= height; i++) 
    { // 피라미드의 높이만큼 반복
        printSpaces(height - i); // 공백 출력
        printStars(2 * i - 1); // 별표 출력
    }
}

// 프로그램의 시작점
void main() 
{
    int height; // 피라미드의 높이를 저장할 변수

    // 사용자로부터 피라미드의 높이를 입력받음
    printf("피라미드 높이를 입력하세요 : ");
    scanf("%d", &height);

    // 입력된 높이가 유효하지 않은 경우 오류 메시지 출력 후 종료
    if (height <= 0) 
    {
        printf("잘못된 높이입니다.\n");
        return;
    }

    // 입력된 높이에 맞는 피라미드 출력
    printf("피라미드 높이 : %d\n", height);
    printPyramid(height);
}