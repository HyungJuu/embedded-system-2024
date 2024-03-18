/* 배열로 구현 */
#include <stdio.h>
#define STACK_SIZE 100

#define TRUE 1   // true, false를 지원하지 않기 때문에 직접 정의
#define FALSE 0

int stack[STACK_SIZE];  // 자료구조 : int 타입의 자료를 STACK_SIZE만큼 담을 수 있는 스택배열 생성
int top = -1;

// 함수 선언
void push();
int pop();
int isFull();
int isEmpty();

void main()
{
    // 배열에 데이터 삽입
    push(3);    // 함수호출
    push(5);
    push(10);

    printf("%d\n",pop());
    printf("%d\n",pop());
    printf("%d\n",pop());
}

void push(int data) // 함수정의
{
    // if(top == STACK_SIZE -1)
    if(isFull())
    {
        printf("stack overflow!!\n");   // 예외처리
        return ;
    }
    stack[++top] = data;    // 배열구조
}

int pop()
{
    // if(top == -1)   // stack 이라는 자료구조에 아무것도 없을 때
    if(isEmpty())
    {
        printf("stack underflow!!\n");
        return -1;  // 일반적으로 잘못되었을 때 -1 리턴
    }
    return stack[top--];    // 함수의 출력형태 : int -> return 필수
    // top--;
}

// 예외처리에 대한 함수 정의
int isFull()
{
    if(top == STACK_SIZE -1)
    {
        return TRUE; // 1(대표적) == true
    }
    else  // 안써도 상관없음
    {
        return FALSE; // 0 == false
    }
}

// isEmpty() 추가
int isEmpty()
{
    if(top <= -1)   // 어떠한 이유로 -1 이 -2로 바뀌면 FALSE가 되므로 == 대신 <= 사용
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}