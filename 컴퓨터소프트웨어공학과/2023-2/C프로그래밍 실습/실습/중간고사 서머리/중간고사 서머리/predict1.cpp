#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//1. 프로그램 시작
int main(void) {
    //2. 시간 변수 선언(네모)
    int time;
    //3. 시간 입력받기(평행사변형)
    printf("시간을 입력하세요 >>");
    scanf("%d", &time);

    //4. 조건문(마름모)
    if (time < 12) {
        printf("오전 입니다 \n");
    }
    else {
        printf("오후 입니다. \n");
    }

    //5.프로그램 끝 알림(평행 사변형)
    printf("프로그램 끝! \n");
}