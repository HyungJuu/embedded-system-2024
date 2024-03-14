#include <stdio.h>

void func(int a, int b) {
    // 더하기, 빼기, 곱하기, 나누기 결과를 출력
    printf("더하기: %d\n", a + b);
    printf("빼기: %d\n", a - b);
    printf("곱하기: %d\n", a * b);
    if (b != 0) 
    {
        printf("나누기: %.2f\n", (float)a / b); // 나눗셈 결과가 실수일 수 있으므로 형 변환
    } 

    else 
    {
        printf("나누기: 무한대 (분모가 0)\n");
    }
}

int main()  // 올바른 반환 타입 사용
{
    int x = 10, y = 20; // 변수 선언과 초기화
    func(x, y); // 수정된 변수를 사용하여 func 호출
    // printf(""); // 필요한 출력이 func 함수 내에서 처리

    return 0; // 올바른 종료 상태 반환
}