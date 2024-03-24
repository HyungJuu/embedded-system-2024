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

void bookAdd(node*);
void bookSearch(node*);
void bookDelete(node*);
void showBook(node*);

void main() 
{
    int num;
    node* title = (node*)malloc(sizeof(node));
    while(1)
    {
        printf("--------------------------도서관리 프로그램--------------------------\n");
        printf("1. 도서구입(등록) / 2. 도서검색 / 3. 도서삭제 / 4. 도서출력 / 0. 종료\n");
        printf("번호 입력 >> ");
        scanf("%d", &num);
        printf("\n");

        switch(num)
        {
        case 1:
            bookAdd(title);
            break;

        case 2:
            bookSearch(title);
            break;

        case 3:
            bookDelete(title);
            break;

        case 4:
            showBook(title);
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

// 1. 도서등록 + 저자 출판사?
void bookAdd(node* pnode)
{
    printf("<<도서 등록>>\n");
    node* newBook =(node*)malloc(sizeof(node));

    printf("제목 입력 >> ");
    scanf("%s", newBook->title);
    printf("저자 입력 >> ");
    scanf("%s", newBook->author);
    printf("출판사 입력 >> ");
    scanf("%s", newBook->publisher);

    newBook->next = NULL;

    while(pnode->next != NULL)
    {
        pnode = pnode->next;
    }
    pnode->next = newBook;
    printf("\n");
}

// 2. 도서검색
void bookSearch(node* pnode)
{
    char STitle[SIZE];

    printf("[도서 검색]\n");

    printf("제목을 입력하세요 >> ");
    scanf("%s", STitle);

    while(pnode != NULL)
    {
        if(strcmp(pnode->title, STitle) == 0)
        {
            printf("[검색한 도서가 확인되었습니다.]\n");
            printf("[제목 : %s]\n", pnode->title);
            printf("[저자 : %s]\n", pnode->author);
            printf("[출판사 : %s]\n", pnode->publisher);
            return;
        }
        pnode = pnode->next;
    }
    printf("[도서를 찾을 수 없습니다.]\n");
}

// 3. 도서삭제
void bookDelete(node* pnode)
{
    char DTitle[SIZE];

    printf("[도서 삭제]\n");
    printf("삭제할 도서 제목을 입력하세요 >> ");
    scanf("%s", DTitle);

    node* curr = pnode;
    node* prev = NULL;

    while(curr != NULL)
    {
        if(strcmp(curr->title, DTitle) == 0)
        {
            if(prev == NULL)
            {
                pnode = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            free(curr);
            printf("[도서를 삭제하였습니다.]\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("[도서를 찾을 수 없습니다.]\n");
}

// 4. 도서출력
void showBook(node* pnode)
{
    int count = 1;
    printf("[도서목록 출력]\n");

    if(pnode == NULL)
    {
        printf("[출력할 도서가 없습니다.]\n");
        return;
    }

    while(pnode != NULL)
    {
        printf("%d. 제목: %s / 저자: %s / 출판사: %s\n", count, pnode->title, pnode->author, pnode->publisher);
        pnode = pnode->next;
        count++;
    }
}
