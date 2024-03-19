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
	if(head != NULL) head->head = NULL;
    return head;
}

void pre_addNode(headNode* pnode, int _data)        // 전위삽입
{
	node* newNode = (node*)malloc(sizeof(node));
	// if(newNode == NULL) return -1;
	if(newNode != NULL)
	{
		newNode->data = _data;
		newNode->next = pnode->head;
		pnode->head = newNode;
	}
}
void rear_addNode(headNode* pnode, int pdata) // 후위삽입
{
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = pdata;
	newNode->next = NULL;

	if (pnode->head == NULL)	// 첫번째 노드로 삽입
		pnode->head = newNode;
    else	// 첫번째 노드가 아니면
    {
        node* curr = pnode->head;	// 마지막노드를 찾는다.
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode;
	}
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

node* searchNode(headNode* pnode, int locate)
{
   node* curr = (node*)malloc(sizeof(node));
   curr = pnode->head;
   while(curr != NULL && locate > 0)
	{
    	curr = curr->next;
		locate--;
	}

   if(locate > 0 || curr == NULL)
   {
    	printf("노드가 없습니다.\n");
    	return  NULL;
   }
    else
    {
        printf("검색한 노드를 찾았습니다.\n");
        return curr; // 해당 노드 반환
    }
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

    // printf("*****노드 삭제*****\n");
    // allFreeNode(head);

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

	printf("*****노드 검색*****\n");
	node* searchedNode = searchNode(head, 3);
	if(searchedNode != NULL)
		printf("검색한 노드의 데이터 => %d\n", searchedNode->data);

	// return 0;
}