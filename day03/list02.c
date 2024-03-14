#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int data;
	struct NODE *next;
}node;

void main()
{
	node* head = (node*)malloc(sizeof(node));  // head노드 : 첫번째 노드를 가리킨다.
	head->next = NULL;
	
	node* node1 = (node*)malloc(sizeof(node));  // 첫번째 노드
	node1->data = 10;
	node1->next = NULL;
	head->next = node1;
	
	node* node2 = (node*)malloc(sizeof(node));  // 두번째 노드
	node2->data = 20;
	node2->next = NULL;
	node1->next = node2;  // 두번째 노드를 연결한다.
	
	node* node3 = (node*)malloc(sizeof(node));  // 세번째 노드
	node3->data = 30;
	node3->next = NULL;
	node2->next = node3;
	
	node* curr = head->next; // 첫번째 노드를 가리킨다.
	while(curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next;  // curr이 마지막노드
	}
	free(node1);
	free(node2);
	free(node3);
}