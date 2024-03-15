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
    node* head = (node*)malloc(sizeof(node));
    return head;
}

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

void showNode(node* pnode)      // 출력함수
{
    node* curr = pnode->next;

    while(curr != NULL)
    {
    printf("%d\n", curr->data);
    curr = curr->next;
    }
}

void allFreeNode(node* pnode)   // 전체 메모리 해체
{
	node* curr = pnode->next; 

    while(curr != NULL)
    {
        pnode->next = curr->next;
        free(curr);
        curr = pnode->next;
    }
    free(pnode);
}

void main()
{
	// node* head = (node*)malloc(sizeof(node));
	// head->next = NULL;
	node* head = createHeadNode();
    
	rear_addNode(head, 10); 
	pre_addNode(head, 20); 
	rear_addNode(head, 30); 
	rear_addNode(head, 40);
	pre_addNode(head, 50);
	node* curr = head->next; 

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
    */
	free(head);
}