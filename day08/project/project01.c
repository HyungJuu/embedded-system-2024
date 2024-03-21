/* 아이디 비번 입력 -> 맞으면 저장된 파일 오픈 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char id[20];
    char pwd[20];
    char myinfo[50] = "이름:김근아\n생년월일:20001122\n";

    FILE* fp;

    fp = fopen("myinfo.txt", "w");
    fprintf(fp, "%s", myinfo);
    fclose(fp);

    printf("아이디 입력 >> ");
    scanf("%s", id);

    printf("비밀번호 입력 >> ");
    scanf("%s", pwd);

    if(strcmp(id, "kim") == 0 && strcmp(pwd, "1111") == 0)
    {
        printf("<<로그인 성공>>\n");

        fp = fopen("myinfo.txt", "r");
        if (fp == NULL)
        {
            printf("open error!\n");
        }

        // 파일내용 출력
        printf("파일 내용:\n");
        while (fgets(myinfo, sizeof(myinfo), fp) != NULL)
        {
        printf("%s", myinfo);
        }
        fclose(fp);
    }
    else
        printf("아이디나 비밀번호가 일치하지 않습니다.\n");
}