#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void error(char * message)
{
    fputs(message, stderr);
    fputs("\n", stderr);
    exit(1);
}

void main()
{
    char msg[] = "Kimgeunah\n";
    char info[20];
    int fd;
    int cfd;

    // 파일 생성 -> 문제없음
    fd = open("geunah_L.txt", O_CREAT | O_RDWR | O_TRUNC, 00600);
    if(fd < 0)    // 기본적으로 -1, 하지만 좀 더 확실하게 오류를 잡기 위해서  < 0 으로 작성
        error("open error!");

    if(write(fd, msg,sizeof(msg)) < 0)
        error("write error!");

    close(fd);

    // 파일 읽기
    fd = open("geunah_L.txt", O_RDONLY);
    if(fd < 0)
        error("open error!");

    if(read(fd, info, sizeof(info)) < 0)
        error("read error!");

    close(fd);

    cfd = open("geunah_Lcopy.txt", O_CREAT | O_WRONLY | O_TRUNC, 00600);
    if(cfd < 0)
        error("open error!");

    if(write(cfd, info, strlen(info)) < 0)
        error("write error!");

    close(cfd);
}
