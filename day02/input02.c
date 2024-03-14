#include <stdio.h>

void findMaxMin(int num1, int num2) 
{
    if (num1 > num2) 
    {
        printf("최대값: %d\n", num1);
        printf("최소값: %d\n", num2);
    } 

    else 
    {
        printf("최대값: %d\n", num2);
        printf("최소값: %d\n", num1);
    }
}

void main() 
{
    int num1, num2;

    printf("두 개의 숫자를 입력하세요: ");
    scanf("%d %d", &num1, &num2);

    findMaxMin(num1, num2);
}