/* 연결자료구조를 이용한 큐 */
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *link;
}node;

typedef struct
{
    node* rear;
    node* front;
}linkQ;

// 함수 선언
linkQ* create();
void enQueue(linkQ*, int);
void printQ(linkQ*);
int deQueue(linkQ*);

// 메인 함수
void main()
{
    linkQ* q = create();
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    printQ(q);

    deQueue(q);
    printQ(q);

    // node* curr = q->front;
    // while (curr != NULL) {
    //     printf("%d\n", curr->data);
    //     curr = curr->link;
    // }
}

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