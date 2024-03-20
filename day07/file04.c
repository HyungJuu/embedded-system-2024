/*
    파일이름 : 이름.txt
    복사된 파일이름 : 이름_copy. txt
*/
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char name[20] = "KIMGEUNAH";
    char copy[20];

    // 파일 생성
    FILE* fp;   // 파일포인터
    fp = fopen("geunah.txt", "w");  // 파일 열기(쓰기모드)
    fprintf(fp, "%s", name);    // fp가 가리키는 파일(geunah.txt) 안에 name 데이터 출력

    fclose(fp); // 파일 닫기

    FILE* fcp;
    fcp = fopen("geunah.txt", "r"); // 파일 열기(읽기모드)
    fscanf(fp, "%s", copy); // fp가 가리키는 파일(geunah.txt)의 내용을 copy에 저장

    fclose(fcp);    // 파일 닫기

    fcp = fopen("geunah_copy.txt", "w");    // 파일 열기(쓰기모드)
    fprintf(fcp, "%s", copy);   // fcp가 가리키는 파일(geunah_copy.txt) 안에 copy 데이터 출력
    fclose(fcp);    // 파일 닫기

    printf("%s", name);
}