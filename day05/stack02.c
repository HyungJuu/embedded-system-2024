/* 연결리스트로 구현 */
#include <stdio.h>

#define STACK_SIZE 10

typedef struct STACK {
    int buf[STACK_SIZE];
    int top;
}stack;

// 함수 선언
void push(stack*, int);

void main()
{
    stack* newstack;
    push(newstack, 10);
}

// 함수 정의
void push(stack* pstack, int pdata)
{
    pstack->buf[pstack->top++] = pdata;
}