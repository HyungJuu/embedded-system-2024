/* 연결리스트를 이용한 큐 자료구조 */
#include <stdio.h>
#include <stdlib.h>

#define QSIZE 3

typedef struct
{
    int front;
    int rear;
    char queue[QSIZE];
}queue;

// 함수 선언
queue* create();
void enqueue(queue*, char);
int dequeue(queue*);

// 메인 함수
void main()
{
    queue* q = create();
    enqueue(q, 'A');
    enqueue(q, 'B');
    enqueue(q, 'C');
    enqueue(q, 'D');    // Overflow

    printf("%c\n", q->queue[0]);
    printf("%c\n", q->queue[1]);
    printf("%c\n", q->queue[2]);
    //  printf("%c\n", q->queue[3]);    // Underflow
}

// 함수 정의
queue* create()
{
    queue* newqueue = (queue*)malloc(sizeof(queue));
    if(newqueue == NULL) exit(1);

    newqueue->front = -1;
    newqueue->rear = -1;

    return newqueue;
}

void enqueue(queue* enq, char data)
{
    if(enq->rear >= QSIZE - 1)
    {
        printf("QUEUE Overflow!!\n");
        return;
    }
    enq->queue[++(enq->rear)] = data;
}

int dequeue(queue* deq)
{
    if(deq->front == deq->rear)
    {
        printf("QUEUE Underflow!!\n");
        return -1;
    }
    return deq->queue[++(deq->front)];
}