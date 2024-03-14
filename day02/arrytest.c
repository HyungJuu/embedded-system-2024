#include <stdio.h>
#define MAX 20

void main()
{
    int arr[MAX], num, i;

    // 사용자로부터 배열의 크기 입력 
    printf("배열 크기 입력(1~20) : ");
    scanf("%d", &num);  // scanf : 출력
    if(num < 1 || num > MAX)
    {
        printf("범위 초과\n");
        return;
    }

    // 배열의 원소를 입력받음
    printf("배열 사이즈 %d 입력 : ", num);
    for(int i = 0; i < num; i++)
    {
        printf("%d : ",i+1);
        scanf("%d", &arr[i]);
    }

    // 배열을 역순으로 출력
    printf("배열의 역순 : \n");
    for(int i = num - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}