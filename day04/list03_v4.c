#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int data;
	struct NODE *next;
}node;

typedef struct
{
    node *head;
}headNode;

headNode* createHeadNode(void)
{
    headNode* head = (headNode*)malloc(sizeof(headNode));
    return head;
}

void pre_addNode(headNode* pnode, int _data)        // 전위삽입
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = _data;
	newNode->next = pnode->head;
	pnode->head = newNode;
}
void rear_addNode(headNode* pnode, int pdata) // 후위삽입
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = pdata;
	newNode->next = NULL;

	node* curr = pnode->head;

	while(curr->next != NULL)
	{
  		curr = curr->next;
   	}
	curr->next = newNode;
}

void showNode(headNode* pnode)      // 출력함수
{
    node* curr = pnode->head;

    while(curr != NULL)
    {
    	printf("%d\n", curr->data);
    	curr = curr->next;
    }
}

void allFreeNode(headNode* pnode)   // 전체 메모리 해제
{
	node* curr = pnode->head; 

    while(curr != NULL)
    {
        pnode->head = curr->next;
        free(curr);
        curr = pnode->head;
    }
    // free(pnode);
}

void main()
{
	// node* head = (node*)malloc(sizeof(node));
	// head->next = NULL;
	headNode* head = createHeadNode();
    
	pre_addNode(head, 10); 
	pre_addNode(head, 20); 
	rear_addNode(head, 30); 
	rear_addNode(head, 40);
	pre_addNode(head, 50);
	//node* curr = head->next; 

    printf("*****노드 생성*****\n");
    showNode(head);
	/*
	printf("*****노드 생성*****\n");
	while(curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next; 
	} 
	*/
	
	//curr = head->next;

    printf("*****노드 삭제*****\n");
    allFreeNode(head);

    /*
	printf("*****노드 삭제*****\n");
	while(curr != NULL)
	{
		curr = curr->next;
		free(head->next);
		head->next = curr; 
	}
	free(head);
    */
}