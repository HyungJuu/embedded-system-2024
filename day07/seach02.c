/* 이진 탐색 */
#include <stdio.h>

void main()
{
    int ary[] = {3, 5, 2, 4, 9, 8, 1};
    int size = sizeof(ary) / sizeof(ary[0]);
    int first = 0;
    int last = size;
    int middle = 0;

    while(first <= last)
    {
        middle = (first + last) / 2;
        if(target == ary[middle])
            printf("%d\n", ary[middle]);
        else
        {
            if(target > ary[middle])
                first = middle + 1;
            else
                last = middle - 1;
        }
    }
}