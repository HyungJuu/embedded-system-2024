#include <stdio.h>

void main() 
{
    int ary[] = {9, 4, 8, 15, 3, 7, 2, 1};
    int size = sizeof(ary) / sizeof(int); // 배열의 요소 수
    // sizeof(int) : int 자료형의 크기를 구함 -> 4
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (ary[j] > ary[j + 1]) 
            {
                int temp = ary[j];
                ary[j] = ary[j + 1];
                ary[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) 
    {
        printf("%d ", ary[i]);
    }
    printf("\n");
}
