#include <stdio.h>
 
// 다른파일에 있는 함수임을 알 수 있음
extern char* input(); // extern을 통해 확장
extern void showf(char*);
 
void main()
{
    char* str = input();
//  printf("%s", str);
    showf(str);
    showf("\n");
}
