#include <stdio.h>
#include <stdlib.h>

void main()
{
    char msg[20] = "File Test!!!";

    FILE* fp;   // 파일 포인터
    fp = fopen("test.txt", "w");    // 쓰기를 목적으로 test.txt 파일 호출(열기)
    if(fp == NULL)
    {
        fprintf(stderr, "Error");   // 파일입출력 : 입력(0), 출력(1), 에러(2)
    }
    fprintf(fp, "%s", msg);   // 파일로 출력
    printf("%s", msg);

    // printf("file descriptor : %d\n, fp");
    fclose(fp);   // 파일을 닫아줌
}