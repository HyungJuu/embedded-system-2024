/* 도서출력시 먼저 빈노드가 출력되는 것 해결 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct NODE 
{
    char publisher[SIZE];
    char title[SIZE];
    char author[SIZE];
    struct NODE *next;
} node;

node* bookAdd(node*);
void bookSearch(node*);
node* bookDelete(node*);
void bookShow(node*);

void main() 
{
    int num;
    node* head = NULL;
    while(1)
    {
        printf("*****도서관리 프로그램*****\n");
        printf("1. 도서등록 \n2. 도서검색 \n3. 도서삭제 \n4. 도서출력 \n0. 종료\n");
        printf("번호 입력 >> ");
        scanf("%d", &num);
        printf("\n");

        switch(num)
        {
        case 1:
            head = bookAdd(head);
            break;

        case 2:
            bookSearch(head);
            break;

        case 3:
            head = bookDelete(head);    // 삭제후의 변경된 시작점을 받아서 head로 저장
            break;

        case 4:
            bookShow(head);
            break;

        case 0:
            printf("[프로그램을 종료합니다.]\n");
            exit(1);
            break;

        default:
            printf("[잘못된 입력입니다. 번호(0~4)를 다시 입력하세요.]\n\n");
        }
    }
}

// 1. 도서등록
node* bookAdd(node* head)
{
    printf("<<도서 등록>>\n");
    node* newBook =(node*)malloc(sizeof(node));

    printf("제목 입력 >> ");
    scanf("%s", newBook->title);
    printf("저자 입력 >> ");
    scanf("%s", newBook->author);
    printf("출판사 입력 >> ");
    scanf("%s", newBook->publisher);
    printf("\n");

    newBook->next = NULL;

    if(head == NULL)
    {
        return newBook; // 연결리스트가 비어있을 때 새노드를 head로 반환
    }

    node* curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newBook;
    printf("\n");

    return head; // 연결리스트 시작점 반환
}

// 2. 도서검색
void bookSearch(node* head)
{
    char STitle[SIZE];

    printf("[도서 검색]\n");

    printf("제목을 입력하세요 >> ");
    scanf("%s", STitle);

    node* temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->title, STitle) == 0)
        {
            printf("[검색한 도서가 확인되었습니다.]\n");
            printf("[제목 : %s]\n", temp->title);
            printf("[저자 : %s]\n", temp->author);
            printf("[출판사 : %s]\n", temp->publisher);
            printf("\n");
            return;
        }
        temp = temp->next;
    }
    printf("[도서를 찾을 수 없습니다.]\n");
    printf("\n");
}

// 3. 도서삭제
node* bookDelete(node* head)
{
    char DTitle[SIZE];

    printf("[도서 삭제]\n");
    printf("삭제할 도서 제목을 입력하세요 >> ");
    scanf("%s", DTitle);

    node* curr = head;
    node* prev = NULL;

    while(curr != NULL)
    {
        if(strcmp(curr->title, DTitle) == 0)
        {
            if(prev == NULL)
            {
                head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            free(curr);
            printf("[도서를 삭제하였습니다.]\n");
            printf("\n");
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("[도서를 찾을 수 없습니다.]\n");
    printf("\n");
    return head;
    free(DTitle);
}

// 4. 도서출력
void bookShow(node* head)
{
    int count = 1;
    printf("[도서목록]\n");

    if(head == NULL)
    {
        printf("[도서가 존재하지 않습니다.]\n");
        printf("\n");
        return;
    }

    node* curr = head;
    while(curr != NULL)
    {
        printf("%d. 제목: %s / 저자: %s / 출판사: %s\n", count, curr->title, curr->author, curr->publisher);
        curr = curr->next;
        count++;
    }
    printf("\n");
}
