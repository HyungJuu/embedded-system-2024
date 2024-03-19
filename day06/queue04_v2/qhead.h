#ifndef QHEAD_H
#define QHEAD_H

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

#endif