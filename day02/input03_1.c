#include <stdio.h>

void main() 
{
    char ch, ch2;
    int n;
    // printf("문자: ");
    // scanf("%c", &ch); 
    printf("학번: ");
    scanf("%d", &n); 
    printf("이름:  ");
    scanf("%c", &ch);
    printf("%d, %c\n", ch, n);
}