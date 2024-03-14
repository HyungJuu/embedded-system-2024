#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int data;
	struct NODE *next;
}node;

void pre_addNode(node* pnode, int _data)        // 전위삽입
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = _data;
	newNode->next = pnode->next;
	pnode->next = newNode;
}
void rear_addNode(node* pnode, int pdata) // 후위삽입
 {
   node* newNode = (node*)malloc(sizeof(node));
   newNode->data = pdata;
   newNode->next = NULL;

   while(pnode->next != NULL)
   {
     pnode = pnode->next;
   }
   pnode->next = newNode;
 }

void main()
{
	node* head = (node*)malloc(sizeof(node));
	head->next = NULL;
	
	rear_addNode(head, 10); 
	pre_addNode(head, 20); 
	rear_addNode(head, 30); 
	rear_addNode(head, 40);
	pre_addNode(head, 50);
	
	node* curr = head->next; 
	printf("*****노드 생성*****\n");
	while(curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next; 
	} 
	
	curr = head->next;
	
	printf("*****노드 삭제*****\n");
	while(curr != NULL)
	{
		curr = curr->next;
		free(head->next);
		head->next = curr; 
	}
	free(head);
}