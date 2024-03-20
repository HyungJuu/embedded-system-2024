#include <stdio.h>
#include <stdlib.h>

void main()
{
    char msg[20];
    FILE* fp; // 파일포인터
    if((fp = fopen("test.txt", "r")) == NULL)
    {
        fprintf(stderr, "ERROR");   // stderr -> 모니터와 연결되어 있다.
        exit(1);
    }
    fscanf(fp, "%s", msg);  // fp가 가리키는 파일의 내용을 msg에 저장
    printf("%s\n", msg);

    fclose(fp);
}