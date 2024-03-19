#include <stdio.h>
#include "qhead.h"

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