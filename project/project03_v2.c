/* 
    도서검색 후 대여/반납 기능 추가하기 ?
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200

typedef struct NODE 
{
    int rental;
    int booknum;
    char publisher[SIZE];
    char title[SIZE];
    char author[SIZE];
    struct NODE *next;
} node;

node* bookAdd(node*);
void bookSearch(node*);
node* bookDelete(node*);
void bookShow(node*);
int bookSearchPrint();
void search_T(node*);
void search_A(node*);
void search_P(node*);
node* bookRental(node*, int);
node* bookReturn(node*);
void rentalselect(node*);

void main() 
{
    int num;
    node* head = NULL;
    while(1)
    {
        printf("*****도서관리 프로그램*****\n");
        printf("1. 도서등록 \n2. 도서검색 \n3. 도서삭제 \n4. 도서출력 \n0. 종료\n");
        printf("---------------------------\n");
        printf("* 번호 입력 >> ");
        scanf("%d", &num);
        printf("\n");
        
        switch(num)
        {
            case 1:
                head = bookAdd(head);
                break;

            case 2:
                while(1)
                {
                    switch(bookSearchPrint())   // 검색방법에 대한 함수에서 리턴한 값을 받음
                    {
                        case 1:
                            search_T(head); // 제목을 검색할때의 함수 호출
                            // bookRental(head);
                            rentalselect(head);
                            break;
                        
                        case 2:
                            search_A(head); // 저자를 검색할 때의 함수 호출
                            break;

                        case 3:
                            search_P(head); // 출판사를 검색할 때의 함수 호출
                            break;
                        
                        default:
                            printf("[잘못된 입력입니다. 번호(1~3)를 다시 입력하세요.]\n\n");
                            continue;
                    }
                    break;
                }
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

// 대여 / 반납 선택
void rentalselect(node* head)
{
    int answer;
    printf("1. 대여 \n2. 반납\n");
    printf("선택지를 입력하세요 >> ");
    scanf("%d", &answer);
    printf("\n");
    switch(answer)
    {
        case 1:
            head = bookRental(head, answer); // 대여 기능 호출
            break;
        
        case 2:
            head = bookReturn(head);    // 반납기능 호출
            break;
        
        default:
            printf("[잘못된 입력입니다. y 또는 n을 입력하세요.]\n");
            printf("\n");
            break;
    }
}

// 1. 도서등록
node* bookAdd(node* head)
{
    printf("*********도서 등록*********\n");
    node* newBook =(node*)malloc(sizeof(node));

    printf("* 제목 입력 >> ");
    scanf("%s", newBook->title);
    printf("* 저자 입력 >> ");
    scanf("%s", newBook->author);
    printf("* 출판사 입력 >> ");
    scanf("%s", newBook->publisher);
    printf("\n");

    newBook->rental = 0;
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

    return head; // 시작점 반환
}

// 2. 도서검색 -> 방법선택
int bookSearchPrint()
{
    int num;
    printf("*********도서 검색*********\n");
    printf("1. 제목 \n2. 저자 \n3. 출판사 \n");
    printf("---------------------------\n");
    printf("검색할 방법을 선택하세요 >> ");
    scanf("%d", &num);
    printf("\n");

    return num;
}

// 제목 검색
void search_T(node* head)
{
    char STitle[SIZE];
    printf("[제목 검색]\n");
    printf("제목을 입력하세요 >> ");
    scanf("%s", STitle);
    printf("\n");

    node* temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->title, STitle) == 0)
        {
            printf("[검색한 도서가 확인되었습니다.]\n");
            printf(">> [제목 : %s]\n", temp->title);
            printf(">> [저자 : %s]\n", temp->author);
            printf(">> [출판사 : %s]\n", temp->publisher);
            printf("\n");
            return;
        }
        temp = temp->next;
    }
    printf("[도서를 찾을 수 없습니다.]\n");
    printf("\n");
}

// 저자 검색
void search_A(node* head)
{
    char SAuthor[SIZE];
    printf("[저자 검색]\n");
    printf("저자를 입력하세요 >> ");
    scanf("%s", SAuthor);
    printf("\n");

    node* temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->author, SAuthor) == 0)
        {
            printf("[검색한 도서가 확인되었습니다.]\n");
            printf(">> [제목 : %s]\n", temp->title);
            printf(">> [저자 : %s]\n", temp->author);
            printf(">> [출판사 : %s]\n", temp->publisher);
            printf("\n");
            return;
        }
        temp = temp->next;
    }
    printf("[도서를 찾을 수 없습니다.]\n");
    printf("\n");
}

// 출판사 검색
void search_P(node* head)
{
    char SPublisher[SIZE];
    printf("[출판사 검색]\n");
    printf("출판사를 입력하세요 >> ");
    scanf("%s", SPublisher);
    printf("\n");

    node* temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->publisher, SPublisher) == 0)
        {
            printf("[검색한 도서가 확인되었습니다.]\n");
            printf(">> [제목 : %s]\n", temp->title);
            printf(">> [저자 : %s]\n", temp->author);
            printf(">> [출판사 : %s]\n", temp->publisher);
            printf("\n");
            return;
        }
        temp = temp->next;
    }
    printf("[도서를 찾을 수 없습니다.]\n");
    printf("\n");
}

// 도서 대여
node* bookRental(node* head, int booknum)
{
    char answer;
    printf("해당 도서를 대여하시겟습니까?(y/n) >> ");
    scanf("%s", &answer);

    node* curr = head;    

    while(curr != NULL)
    {
        if(curr->booknum == booknum)
        {
            if(curr->rental == 0)
            {
                curr->rental == 1;
                printf("[도서를 대여하였습니다.]\n");
            }
            else
            {
                printf("[이미 대여중인 도서입니다.]\n");
            }
            return head;
        }
        // if(answer == 'y' || answer == 'Y')
        // {
        //     curr->rental = 1;
        //     printf("[도서를 대여하였습니다.]\n");
        //     printf("\n");
        //     return head;
        // }
        // else
        // {
        //     if(answer == 'n' || answer == 'N')
        //     {
        //         printf("[도서대여를 취소하였습니다.]\n");
        //         printf("\n");
        //         return head;
        //     }
        //     else
        //     {
        //         printf("[잘못된 입력입니다. y 또는 n을 입력하세요.]\n");
        //         printf("\n");
        //         continue;
        //     }
        curr = curr->next;
    }

    printf("[도서를 찾을 수 없습니다.]\n");
    printf("\n");
    return head;
}

// 도서 반납
node* bookReturn(node* head)
{
    char answer;

    printf("해당 도서를 반납하시겠습니까?(y/n) >> ");
    scanf("%s", answer);

    node* curr = head;
    while(curr != NULL)
    {
        if(answer == 'y' || answer == 'Y')
        {
            curr->rental = 0;
            printf("[도서를 반납하였습니다.]\n");
            printf("\n");
            return head;
        }
        else
        {
            if(answer == 'n' || answer == 'N')
            {
                printf("[도서 반납을 취소하였습니다.]\n");
                printf("\n");
                return head;
            }
            else
            {
                printf("[잘못된 입력입니다. y 또는 n을 입력하세요.]\n");
                printf("\n");
                return head;
            }
        }
        curr = curr->next;
    }

    printf("[도서를 찾을 수 없습니다.]\n");
    printf("\n");
    return head;
}



// 3. 도서삭제
node* bookDelete(node* head)
{
    char DTitle[SIZE], DAuthor[SIZE], DPublisher[SIZE];

    printf("*********도서 삭제*********\n");
    printf("[삭제할 도서 정보를 입력하세요]\n");
    printf("* 제목 >> ");
    scanf("%s", DTitle);
    printf("* 저자 >> ");
    scanf("%s", DAuthor);
    printf("* 출판사 >> ");
    scanf("%s", DPublisher);

    node* curr = head;
    node* prev = NULL;

    while(curr != NULL)
    {
        if(strcmp(curr->title, DTitle) == 0 && strcmp(curr->author, DAuthor) == 0 && strcmp(curr->publisher, DPublisher) == 0)
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
    // free(DTitle);
    // free(DAuthor);
    // free(DPublisher);
}

// 4. 도서출력
void bookShow(node* head)
{
    int count = 1;
    printf("*********도서 목록*********\n");

    if(head == NULL)
    {
        printf("[도서가 존재하지 않습니다.]\n");
        printf("\n");
        return;
    }

    node* curr = head;
    while(curr != NULL)
    {
        if(curr->rental == 1)
        {
            printf(">> %d. 제목: %s / 저자: %s / 출판사: %s / 대여상태: 대여 중\n", count, curr->title, curr->author, curr->publisher);
        }
        else
        {
            printf(">> %d. 제목: %s / 저자: %s / 출판사: %s / 대여상태: 대여 가능\n", count, curr->title, curr->author, curr->publisher);
        }
        curr = curr->next;
        count++;
    }
    printf("\n");
}
