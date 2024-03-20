/* 이진 탐색 */
#include <stdio.h>

void b_seach(int *ary, int size, int target)
{
    int first = 0;
    int last = size;
    int middle = 0;

    while(first <= last)
    {
        middle = (first + last) / 2;
        if(target == ary[middle])
        {
            printf("%d이 arr[] 배열 안에 있습니다.\n", ary[middle]);
            break;
        }
        else
        {
            if(target > ary[middle])
                first = middle + 1;
            else
                last = middle - 1;
        }
    }
}

void main()
{
    // 이진탐색에서는 배열은 오름차순 또는 내림차순으로 정렬되어 있어야 함
    int ary[] = {3, 5, 2, 4, 9, 8, 1};
    int size = sizeof(ary) / sizeof(ary[0]);

    b_seach(ary, size, 7);
}