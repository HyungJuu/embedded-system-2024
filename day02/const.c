#include <stdio.h>

void main()
{
    const int i = 10;
    printf("i: %d\n", i);
    /*
    i = 20;
    printf("i: % d\n", i);
    */

    const int* pi = &i;
    printf("*pi: %d\n",*pi);

    const int* pi2 = &i;
    printf("*pi2: %d\n", *pi2);
}