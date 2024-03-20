#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void error_handling(char* massage);

int main()
{
    int fd;
    char buf[] = "Let's go!\n";

    fd = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC);  // 파일이 없으면 생성, 쓰기 전용, 기존데이터 모두>
    if(fd == -1)
        error_handling("open() error!");
    printf("file descriptor : %d \n", fd);

    if(write(fd, buf, sizeof(buf)) == -1)
        error_handling("write() error!");
    close(fd);

    return 0;
 }

 void error_handling(char* message)
 {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
 }