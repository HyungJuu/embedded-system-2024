# embedded-system-2024
부경대 2024 IoT 개발자과정 임베디드시스템 학습 리포지토리

## 1일차

- 개발환경 설치
	- 라즈베리파이 설치 https://www.raspberrypi.com/software/
	- sd card formatter 설치 https://www.sdcard.org/downloads/formatter/sd-memory-card-formatter-for-windows-download/
		- sd카드 리더기를 usb포트에 삽입 후 포맷작업
		
	- putty 설치 https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html

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
	- ls : 현재 위치의 파일목록을 보여줌
		- -a : 숨겨진 파일을 모두 보여줌
		- -l : 상세하게 보여줌
		- /etc : 환경에 관련된 디렉토리 (흰색은 파일 , 파란색은 폴더)
		
	- pwd : 현재 내 위치
	- mkdir : 새로운 디렉토리 생성
	- rm -fr : 삭제
	- clear : 화면 초기화
	- cd : 해당 위치로 이동
	- cd .. : 상위 디렉토리로 빠져나옴
	
- sudo nano /etc/nanorc -> 관리자 권한으로 실행
	- 주석제거
		- autoindent 
		- linenumbers
		- tabsize 8 -> tabsize 2

