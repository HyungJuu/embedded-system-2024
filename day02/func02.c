#include <stdio.h>
// 더하기, 빼기, 곱하기, 나누기 연산을 수행하는 func 함수 선언
void func(int a, int b);

void main() 
{
    int x = 10, y = 20; // 변수 이름을 올바르게 수정
    func(x, y); // 수정된 변수 이름으로 func 함수 호출
}

void func(int a, int b) 
{
    printf("더하기: %d + %d = %d\n", a, b, a + b);
    printf("빼기: %d - %d = %d\n", a, b, a - b);
    printf("곱하기: %d * %d = %d\n", a, b, a * b);

    // 나누기 연산 시 b가 0인 경우를 고려
    if (b != 0) 
    {
        printf("나누기: %d / %d = %d\n", a, b, a / b);
    } 

    else 
    {
        printf("0으로 나눌 수 없습니다.\n");
    }
}