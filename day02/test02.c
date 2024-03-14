#include <stdio.h>
 
void main()
{
    printf("%d\n", 28);           // => 정수 출력
    printf("%d\n", 0123);        // => 8진수 출력
    printf("%d\n", 0xACC);       // => 16진수 출력
    printf("%f\n", 3.14);        // => 소수점 출력
    printf("int: %d\n", sizeof(int));           // => int size 출력
    printf("float: %d\n", sizeof(float));       // => float size 출력
    printf("double: %d\n", sizeof(double));     //=> double size 출력
    printf("%c\n", 'A');
    printf("%d\n", 'A');
    printf("%d\n", 'a');
    printf("%c\n", 97);

    printf("%s\n", "RaspberryPI OS\n");
}