#include <stdio.h>

void main()
{
    enum season {SPRING = 5, SUMMER, AUTUMN, WINTER} s;
    // {SPRING, SUMMER, AUTUMN, WINTER} => 순서대로 0 1 2 3 
    // {SPRING = 5, SUMMER, AUTUMN, WINTER} => 순서대로 5 6 7 8
    s = AUTUMN;
    printf("%d\n", s);

    s = WINTER;
    printf("%d\n", s);
}