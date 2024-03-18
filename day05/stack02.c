/* 연결리스트로 구현 */
#include <stdio.h>

#define STACK_SIZE 10

typedef struct STACK {
    int buf[STACK_SIZE];
    int top;
}stack;

// 함수 선언
void push(stack*, int);

// 메인 함수
void main()
{
    stack newstack;
    newstack.top = -1;  // top을 -1로 초기화

    
    push(&newstack, 10);    // newstack 변수의 주소를 전달
    push(&newstack, 20);

    printf("%d\n",pop(&newstack));
    printf("%d\n",pop(&newstack));
    printf("%d\n",pop(&newstack));
}


// 함수 정의
void push(stack* pstack, int pdata)
{
    if(isFull(pstack))
    {
        printf("stack overflow!!\n");
        return;
    }
    pstack->buf[++(pstack->top)] = pdata;
    printf("%d번 스택에 %d push완료\n", pstack->top, pdata);
}

int pop(stack* pstack)
{
    if(isEmpty(pstack))
    {
        printf("stack underflow!!\n");
        return -1;
    }
    return pstack->buf[(pstack->top)--];
}

int isFull(stack* pstack)
{
    if(pstack->top == STACK_SIZE -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(stack* pstack)
{
    if(pstack->top <= -1)
    {
        return 1;
    }
    else return 0;
}