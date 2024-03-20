#include <stdio.h>

int lSeach(int *ary, int size, int num)
{
    for(int i = 0; i < size; i++)
    {
        if(ary[i] == num) // 인덱스값이 찾는 값일 때
            return i;   // 인덱스 번호를 리턴

        else  // 인덱스값이 찾는값이 아닐 때
            continue;
    }
    return -1;  // 찾는값이 배열안에 없을 때 -1 리턴
}
 
void main()
{
    int ary[] = {3, 5, 2, 4, 9, 8, 1};
    int size = sizeof(ary)/sizeof(int);
    int ridx;
//    int num;

//  printf("찾을 값 : ");
//  scanf("%d\n", num);

    ridx = lSeach(ary, size, 10); // 배열, 배열의 크기, 찾을 값

    if(ridx == -1) printf("찾는 원소가 없습니다.\n");
    else
        printf("찾은 값의 인덱스 : ary[%d]\n", ridx);
}
