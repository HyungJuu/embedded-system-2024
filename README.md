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
	
- 배열


## 6일차
- 큐(순차 자료구조)
	- enqueue()
	- dequeue()
	- printQueue()
	
	
- makefile : 컴파일

	- c++ 에서 파일분할과 비슷함

- .o : 오브젝트 파일