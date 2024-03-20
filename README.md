# embedded-system-2024
부경대 2024 IoT 개발자과정 임베디드시스템 학습 리포지토리

## 1일차

- 개발환경 설치
	- 라즈베리파이 설치 : https://www.raspberrypi.com/software/
	- sd card formatter 설치 : https://www.sdcard.org/downloads/formatter/sd-memory-card-formatter-for-windows-download/
		- sd카드 리더기를 usb포트에 삽입 후 포맷작업
		
	- putty 설치 : https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html

	- <업데이트>
		- sudo apt update
		- sudo apt upgrade -y
		- clear

	- 환경설정
		- 편집기 : 코드 작업할 때 사용하는 프로그램(nano)
		- 한글
			- 기존 PC와 같이 사용해서는 안된다.
			- 순서에 맞춰서 사용 (동작중 다른 명령어 처리 X)
			
- 기본 명령어
	- <흰색은 파일 , 파란색은 폴더>
	- ls : 현재 위치의 디렉토리 안의 내용(디렉토리, 파일 등)목록을 보여줌
		- -a : 숨겨진 파일을 모두 보여줌
		- -l : 상세하게 보여줌
		- /etc : 환경(기본 설정)에 관련된 디렉토리
		
	- pwd : 현재 내 위치
	- mkdir : 새로운 디렉토리 생성
	- rm -fr : 디렉토리 삭제
	- clear : 화면 초기화
	- cd : 해당 위치로 이동
	- cd .. : 상위 디렉토리로 빠져나옴
	- ctrl + c : 실행취소
	- ctrl + x : 종료(빠져나옴)
	
- sudo nano /etc/nanorc -> 관리자 권한(sudo)으로 실행
	- 주석제거
		- autoindent 
		- linenumbers
		- tabsize 8 -> tabsize 2

## 2일차
- VNC Viewer 설치 : https://www.realvnc.com/en/connect/download/viewer/
	- putty -> vncserver-virtual
	
- 기본 명령어(추가)
	- <초록색은 실행파일>
	- gcc : 컴파일  
		&rarr; 형식 : gcc -o 만들실행파일명 소스파일명  
		&rarr; ex) gcc -o test01 test01.c --> 소스파일 test01.c의 실행파일을 test01 이라는 이름으로 생성  
		- gcc test01.c  -->  a.out 이라는 기본적인 실행파일 생성(출력(./a.out)은 동일하게 됨)
	- ./ : 출력
	- mv : 파일이동, 수정  
		&rarr; ex) mv test01.c test02.c  -->  test01.c를 test02.c로 수정(변경)
	- cp : 파일 복사  
		&rarr; ex) cp test.c test03.c  -->  test.c를 복사하여 test03.c를 생성
		
- 입력과 출력
	- printf : 출력
	- scanf : 입력
 
		```C
		void main()
		{
			int a;
			printf("정수 하나를 입력하세요 >> ");
			scanf("%d", &a);
		}
		```
		
## 3일차
- 연결리스트 (참고 : https://velog.io/@woukl22/posts)
	- 서로 다른 물리적 위치에 있는 노드가 연결되어 만들어진 리스트
	- 각 노드에 저장된 다음 노드에 대한 주소값을 통해 연결
		- 헤드(Head) -> 맨앞
		- 테일(Tail) -> 맨뒤
		
	![노드](https://raw.githubusercontent.com/HyungJuu/embedded-system-2024/main/images/node.png)
	![노드설명](https://raw.githubusercontent.com/HyungJuu/embedded-system-2024/main/images/node01.png)
	
	- 연결리스트 노드
	```C
	typedef struct NODE	// 구조체
	{
		int data;	// int형 데이터를 저장하는 노드
		struct NODE *next;
	}node;
	```
	
	- 노드 생성
	```C
	typedef struct	// 구조체
	{
		node *head;	// 멤버 : head
	}headNode;
	
	headNode* createHeadNode(void)	// 입력 x 출력 o (type : headNode)
	{
		headNode* head = (headNode*)malloc(sizeof(headNode));	// 메모리공간을 동적 할당. (headNode*) : 형변환
		// sizeof(headNode) : haedNode 자료형의 크기를 구한다.
		return head;	// 출력이 있으므로 리턴 필수★★★
	}
	```
	
	- 노드 추가(전위, 후위)
		- 전위삽입  
			&rarr; 연결리스트가 비어있으면(NULL) 새로 생성한 노드를 헤드노드 앞에 연결하고 새노드가 헤드로 지정됨
		
		![전위](https://raw.githubusercontent.com/HyungJuu/embedded-system-2024/main/images/%EC%A0%84%EC%9C%84%EC%82%BD%EC%9E%85.png)

		```C
		void pre_addNode(node* pnode, int _data)	// 전위삽입
		{
			node* newNode = (node*)malloc(sizeof(node));	// 노드 생성
			// node크기만큼의 메모리공간을 동적 할당받아 포인터변수 newNode에 저장
			newNode->data = _data;
			newNode->next = pnode->next;
			pnode->next = newNode;
		}

		```
		
		- 후위삽입  
			&rarr; 연결리스트가 비어있지 않으면(!NULL) 새로 생성한 노드를 테일노드 뒤에 연결
		
		![후위](https://raw.githubusercontent.com/HyungJuu/embedded-system-2024/main/images/%ED%9B%84%EC%9C%84%EC%82%BD%EC%9E%85.png)
		

		```C
		void rear_addNode(node* pnode, int pdata) // 후위삽입
		 {
		   node* newNode = (node*)malloc(sizeof(node));	// 노드 생성
		   newNode->data = pdata;
		   newNode->next = NULL;

		   while(pnode->next != NULL)	// pnode의 다음값이 NULL일 때까지
		   {
				pnode = pnode->next;	// pnode를 다음값으로 지정(이동)
		   }
		   pnode->next = newNode;	// 테일노드 다음 노드에 새로생성한 노드를 연결
		 }
		```
		![후위삽입설명](https://raw.githubusercontent.com/HyungJuu/embedded-system-2024/main/images/%ED%9B%84%EC%9C%84%EC%82%BD%EC%9E%85%EC%84%A4%EB%AA%85.png)

## 4일차
- 연결리스트 이어서
	- 노드 삭제
		- 헤드노드를 삭제할 경우  
			&rarr; 헤드노드를 헤드노드 다음노드로 지정  
			&rarr; 기존 헤드노드 삭제
			
		- 헤드노드가 아닌 노드를 삭제할 경우  
			&rarr; 삭제할 노드를 찾아줄 변수를 하나 생성  
			&rarr; 생성한 노드의 다음노드가 삭제할 노드가 아니면, 다음노드로 연결(이동)  
			&rarr; 다음노드가 삭제할 노드면, 해당 노드를 삭제(소멸) &rarr; 삭제한 노드의 다음노드와 연결
			
		![노드삭제설명](https://raw.githubusercontent.com/HyungJuu/embedded-system-2024/main/images/%EB%85%B8%EB%93%9C%EC%82%AD%EC%A0%9C%EC%84%A4%EB%AA%85.png)
	
	```C
	void allFreeNode(headNode* pnode)	// 전체 메모리 해제
	{
		node* curr = pnode->head; 

		while(curr != NULL)
		{
			pnode->head = curr->next;
			free(curr);	// free() : 힙영역에서 메모리공간 반환
			curr = pnode->head;
		}
	}
	```
	
## 5일차
- 연결리스트 이어서
	- 노드 검색
		- N번째에 노드가 있는 경우
		- N번째에 노드가 없는 경우
	```C
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
	```
	
	- 자료구조
		- Stack(후입선출 : LIFO)
		- Queue(선입선출 : FIFO)  
	&rarr; rear : 입구  
	&rarr; front : 출구
	

## 6일차
- 큐(순차 자료구조)
	- enqueue()
	- dequeue()
	- printQueue()
	
- make : 프로그램 빌드 도구  
	&rarr; makefile 생성 후 make 컴파일 -> 실행은 ./

- makefile
	- 각각의 소스파일을 컴파일하여 오브젝트(Object)파일(.o)을 생성
	- 생성한 오브젝트 파일을 하나로 묶어(링크과정) 실행파일 생성  
	&rarr; 반복되는 컴파일 작업을 자동화  
	&rarr; 수정된 소스파일만 컴파일 -> 재컴파일 시간 단축
	
	![makefile](https://raw.githubusercontent.com/HyungJuu/embedded-system-2024/main/images/makefile.png)
	
	```makefile
	// main.o , inputf.o, printf.o 를 통해 test(실행파일) 생성
	test: main.o inputf.o printf.o
		gcc -o test main.c printf.c inputf.c

	main.o: main.c
		gcc -c main.c

	inputf.o: inputf.c
		gcc -c inputf.c

	printf.o: printf.c
		gcc -c printf.c
	```

- 파일분할
	- static : 전역변수로 설정
	- extern : 다른 소스파일에 있는 변수와 함수를 가져다 쓸 수 있다  
	&rarr; extern 자료형 전역변수명;  
	&rarr; extern 반환값자료형 함수이름(매개변수 자료형)
	
	- 헤더파일과 소스파일
		- 헤더파일(.h) -> 구조체 정의, 함수의 선언 작성
		
		```C
		#ifndef 헤더파일명(대문자)_H
		#define 헤더파일명(대문자)_H
		
		#endif
		```
		
		- 소스파일(.c) -> 함수의 정의 작성
		
		```C
		#include "헤더파일명"
		```
	
## 7일차
- 배열
	- 버블탐색
	- 배열의 크기 sizeof
	
	```C
	int ary[] = {3, 5, 2, 4, 9, 8, 1};
	int size = sizeof(ary)/sizeof(int);	// (7*4) / (1*4) = 7
	// sizeof : 할당받는 메모리공간의 크기를 byte 단위로 출력
	// sizeof(ary) : 배열안의 변수 수(7) * 변수의 자료형(int : 4) = 28
	// sizeof(int) : int 자료형의 크기 : 4
	```
	- 이진탐색

- 파일 입출력
// p.26 ~ 
	- 파일 포인터
	
	- 모든 OS에서 사용가능한 함수
		- fopen("파일명", "옵션") -> 파일 열기
			- 옵션 : 읽기(r), 쓰기(w), 추가(a)  
		
		- fprintf() -> 파일 안에 문자열 출력
			- exit() : 입력(0) 출력(1) 에러(2)  
		
		- fscanf() 
		
		- fclose() -> 파일 닫기  
		
	- 리눅스에서 사용하는 함수(file02.c) 
		- #include <fcntl.h> -> 파일 컨트롤 기능
		- #include <unistd.h> -> 유닉스 C 컴파일러 헤더파일(윈도우 X)  

		- open("파일명", "옵션") -> 파일 열기
			- 옵션  
				&rarr; O_CREAT : 파일이 존재하지 않으면 생성  
				&rarr; O_WRONLY : 파일을 쓰기 전용으로 열기  
				&rarr; O_RDONLY : 파일을 읽기 전용으로 열기  
				&rarr; O_RDWR : 파일 읽기쓰기  
		
		- printf()  
		  
		- close() -> 파일을 닫기  
			&rarr; 성공(0), 실패(-1) 반환  
			
		- file descriptor  
		
		- write() : 파일에 데이터 쓰기
		- read() : 파일에 저장된 데이터 읽기  
		  
	- 파일안의 내용 확인
		- nano test.txt : 파일을 열어서 확인
		- cat test.txt : 파일안의 내용 출력