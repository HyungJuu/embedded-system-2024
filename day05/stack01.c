/* 배열로 구현 */
#include <stdio.h>
#define STACK_SIZE 100

int stack[STACK_SIZE];  // stack이라는 자료구조(배열)
int top = -1;

// 함수 선언
void push();
int pop();

void main()
{
    // 배열에 데이터 삽입
    push(3);    // 함수호출
    push(5);
    push(10);

    printf("%d\n",pop());
    printf("%d\n",pop());
}

void push(int data) // 함수정의
{
    if(top == STACK_SIZE -1)
    {
        printf("stack overflow!!\n");   // 예외처리
        // return -1;
    }
    stack[++top] = data;    // 배열구조
}

int pop()
{
    if(top == -1)   // stack 이라는 자료구조에 아무것도 없을 때
    {
        printf("stack underflow!!\n");
        return -1;  // 일반적으로 잘못되었을 때 -1 리턴
    }
    return stack[top--];    // 함수의 출력형태 : int -> return 필수
    // top--;
}