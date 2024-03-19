#include <stdio.h>

#define Q_SIZE 3

// 전역변수 선언
int queue[Q_SIZE];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if(rear >= Q_SIZE-1)
    {
        printf("QUEUE OverFlow!!\n");
        return;
    }
    queue[++rear] = data;
}

int dequeue()
{
    if(front == rear)
    {
        printf("QUEUE UnderFlow!!\n");
        return -1;
    }
    return queue[++front];
}

void main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);    // overflow

    printf("%d\n", dequeue());  // 10
    printf("%d\n", dequeue());  // 20
    printf("%d\n", dequeue());  // 30
    // printf("%d\n", dequeue());  // underflow
}