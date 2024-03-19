#include <stdio.h>
#include <stdlib.h>
#include "qhead.h"

// 함수 정의
linkQ* create()
{
    linkQ* lq = (linkQ*)malloc(sizeof(linkQ));
    lq->rear = NULL;
    lq->front = NULL;
    return lq;
}

void enQueue(linkQ* enq, int _data)
{
    node* newNode = (node*)malloc(sizeof(node));

    newNode->data = _data;
    newNode->link = NULL;
    printf("ENQUEUE 삽입 => %d\n", _data);

    if(enq->rear == NULL)   // 큐가 비었을 때
    {
        enq->front = newNode;
        enq->rear = newNode;
    }
    else
    {
        enq->rear->link = newNode;
        enq->rear = newNode;
    }
}

int deQueue(linkQ* deq)
{
    node* delNode = (node*)malloc(sizeof(node));
    delNode = deq->front;
    
    int data = delNode->data;
    deq->front = delNode->link;

    printf("DEQUEUE 추출 => %d\n", data);
    return data;
}

// 출력함수
void printQ(linkQ* prq)
{
    printf("현재 QUEUE의 데이터 => ");
    node* curr = prq->front;
    while(curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->link;
    }
    printf("\n\n");
}