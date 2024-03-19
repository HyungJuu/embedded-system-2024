#include <stdio.h>

char* input()
{
     static char str[10];  // 프로그램이 종료될때까지 사용할 수 있도록 static
    static char *pstr = str;
    
    printf("입력 >> ");
    scanf("%s", str);
    
    return pstr;
}
