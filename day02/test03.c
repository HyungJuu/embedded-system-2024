#include <stdio.h>
#define BUFSIZE 20

void main() 
{
    char str[BUFSIZE] = "RASBERRYPI!!!";
    printf("%s\n", str);

    for (int i = 0; i < BUFSIZE; i++) 
    {
        printf("%c", str[i]);
    }
    printf("\n");
}