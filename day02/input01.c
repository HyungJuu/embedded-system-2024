#include <stdio.h>

void main() 
{
    int n;

    while (1) 
    {
        printf("Put Number (0 to exit): ");
        scanf("%d", &n);

        if (n == 0) 
        {
            printf("프로그램을 종료합니다.\n");
            return; // 함수를 종료합니다.
        } 
        
        else if (n >= 1 && n <= 5) 
        {
            printf("%d를 입력하셨습니다.\n", n);
        } 

        else 
        {
            printf("잘못된 입력입니다. 1부터 5까지의 숫자를 입력하세요.\n");
        }
    }
}