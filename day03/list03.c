#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int data;
	struct NODE *next;
}node;

void addNode(node* pnode, int _data)
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = _data;
	newNode->next = pnode->next;
	pnode->next = newNode;
	
}

void main()
{
	node* head = (node*)malloc(sizeof(node));
	head->next = NULL;
	
	addNode(head, 10); // 첫번째 노드로 삽입
	addNode(head, 20); // 첫번째 노드가 뒤로 밀려나고
	addNode(head, 30); // 그앞에 새로 생성한 노드가 첫번째로 삽입됨
	addNode(head, 40);
	addNode(head, 50); // 즉 가장 마지막에 생성한 노드가 첫번째
	
	node* curr = head->next; // curr은 첫번째 노드를 가리킴
	printf("*****노드 생성*****\n");
	while(curr != NULL)
	{
		printf("%d\n", curr->data); // 첫번째 노드인 50을 출력
		curr = curr->next; // curr에 다음노드인 40을 저장. 반복
	} // while문이 끝났을 때 curr은 10을 가리키고 있음
	
	curr = head->next; // curr을 첫번째 값으로 초기화
	
	printf("*****노드 삭제*****\n");
	while(curr != NULL)
	{
		curr = curr->next; // curr이 두번째 값을 가리키도록 저장
		free(head->next); // free: 삭제. 첫번째 값을 삭제
		head->next = curr; // 첫번째 값이 curr이 가리키고 있는 두번째 값을 가리키도록 저
	}
	free(head);
}