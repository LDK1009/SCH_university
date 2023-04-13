#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 8

/*
    작성일:2023.04.13
    작성자: 컴퓨터소프트웨어공학과 / 20194463 / 이동규
    프로그램명: 좌표 사이 거리 계산하기
*/



int main()
{
    int data[MAX_SIZE];     // 좌표를 입력 받을 배열
    int size = 0;
    int num;

    // 파일 오픈 & 데이터 리드
    FILE* fp = fopen("data01.txt", "r");

    // 파일 오픈 실패 시
    if (fp == NULL)
    {
        printf("Failed to open file.\n");
        return 1;
    }
    
    // 파일 데이터 리드
    while (fscanf(fp, "%d", &num) != EOF && size < MAX_SIZE) {
        data[size] = num;
        size++;
    }
    
    // 배열 원소 2개 당 (x,y) 좌표 한 묶음, 따라서 i를 2씩 증가시켜 좌표 묶음 분리
    for (int i = 0; i < MAX_SIZE; i=i+2)
    {
        float distance1 = sqrt(pow(data[i] - data[i + 2], 2) + pow(data[i + 1] - data[i + 3], 2));      // 기준 좌표와 비교군 좌표1 의 거리
        float distance2 = sqrt(pow(data[i] - data[i + 4], 2) + pow(data[i + 1] - data[i + 5], 2));      // 기준 좌표와 비교군 좌표2 의 거리
        float distance3 = sqrt(pow(data[i] - data[i + 6], 2) + pow(data[i + 1] - data[i + 7], 2));      // 기준 좌표와 비교군 좌표3 의 거리

        if (i >= MAX_SIZE - 2)      // 비교군 좌표 인덱스가 배열의 크기를 넘었을 때 즉, 비교군 좌표가 더 이상 없을 때 거리 출력 X
            continue;
        printf("(%d, %d)와(%d, %d)의 사이의 거리는 %.5f 입니다. \n", data[i], data[i + 1], data[i + 2], data[i + 3], distance1);

        if (i >= MAX_SIZE - 4)      // 비교군 좌표2가 없을 때 거리 출력 X
            continue;
        printf("(%d, %d)와(%d, %d)의 사이의 거리는 %.5f 입니다. \n", data[i], data[i + 1], data[i + 4], data[i + 5], distance2);

        if (i >= MAX_SIZE - 6)      // 비교군 좌표3가 없을 때 거리 출력 X
            continue;
        printf("(%d, %d)와(%d, %d)의 사이의 거리는 %.5f 입니다. \n", data[i], data[i + 1], data[i + 6], data[i + 7], distance3);
    }
    
    // close file
    fclose(fp);

    return 0;
}