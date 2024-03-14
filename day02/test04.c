#include <stdio.h>

void main() 
{
    char name[100]; // 이름을 저장할 문자 배열
    int age;        // 나이를 저장할 변수

    // 1. 이름 입력
    printf("이름을 입력하세요: ");
    scanf("%s", name); // 이름 입력 받기

    // 2. 나이 입력하여 출력
    printf("나이를 입력하세요: ");
    scanf("%d", &age); // 나이 입력 받기

    // 이름과 나이 순서대로 출력
    printf("이름: %s, 나이: %d\n", name, age);

    // 3. 나이 입력
    printf("나이를 다시 입력하세요: ");
    scanf("%d", &age); // 나이 입력 받기

    // 4. 이름 입력하여 출력
    printf("이름을 다시 입력하세요: ");
    scanf("%s", name); // 이름 입력 받기

    // 나이와 이름 순서를 바꿔 출력
    printf("나이: %d, 이름: %s\n", age, name);
}