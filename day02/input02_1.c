#include <stdio.h>

void main() 
{
    int a, b;
    printf("두 개의 정수를 입력하시오. > ");
    scanf("%d %d", &a, &b);

    if (a > b) 
    {
        printf("Max = %d\n", a);
        printf("Min = %d\n", b);
    } 

    else if (a < b) 
    {
        printf("Max = %d\n", b);
        printf("Min = %d\n", a);
    }
}