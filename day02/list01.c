#include <stdio.h>
#include <stdlib.h>

// 연결 리스트의 노드를 정의하는 구조체
typedef struct node 
{
    int data;           // 노드가 저장하는 데이터
    struct node *next;  // 다음 노드를 가리키는 포인터
} Node;

void main() 
{
    // 연결 리스트의 헤드 노드에 메모리를 동적 할당
    Node *head = malloc(sizeof(Node));
    Node *node1 = malloc(sizeof(Node));
    Node *node2 = malloc(sizeof(Node)); // node2를 선언 및 할당

    // 연결 리스트의 헤드 노드를 초기화
    head->data = 10;     // 예시로 10를 저장
    head->next = NULL;   // 다음 노드를 가리키는 포인터를 NULL로 초기화

    // node1 초기화
    node1->data = 11;
    node1->next = NULL;

    // node2 초기화
    node2->data = node1->data; // node1의 data 멤버 값을 node2의 data 멤버로 복사
    node2->next = NULL;

    // node1의 다음 노드로 node2를 지정
    node1->next = node2;

    // 할당된 메모리를 해제
    printf("data: %d, next : %d\n", head->data, (int)head->next); // 포인터 값을 정수로 형변환하여 출력
    printf("data: %d, next : %d\n", node1->data, (int)node1->next); // 포인터 값을 정수로 형변환하여 출력
    printf("data: %d, next : %d\n", node2->data, (int)node2->next); // 포인터 값을 정수로 형변환하여 출력

    free(head);
    free(node1);
    free(node2);
}