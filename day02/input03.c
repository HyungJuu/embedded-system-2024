#include <stdio.h>

 void main() 
 {
   char ch;
   int n;
   printf("문자 : ");
   scanf("%c", &ch); // 수정됨: 불필요한 공백 제거
   // 문자 입력 후 엔터를 치면 '\n'이 입력버퍼에 남아있으므로 다음 scanf가 올바르게 작동하도록 버퍼를 비워야 함
   while (getchar() != '\n'); // 추가된 코드 : 남은 '\n'을 버퍼에서 제거
   printf("Number : ");
   scanf("%d", &n);
 }