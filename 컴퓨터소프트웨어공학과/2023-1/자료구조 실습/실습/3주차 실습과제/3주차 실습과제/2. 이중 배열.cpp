/*
학과 : 컴퓨터소프트웨어공학과
학번 : 20194463
이름 : 이동규
작성일자 : 2023.03.19
*/

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 100

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nAr[SIZE][SIZE];
    int TransAr[SIZE][SIZE];
    int nTemp, i;
    int nCount = 0, nRow = 0;
    char chTemp = '0';

    FILE *fp;
    // 1. 데이터 파일 오픈
    fp = fopen("data_이중배열.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file.");
        return 1;
    }

    // 2. 행렬 데이터 초기화
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            nAr[i][j] = -1;
            TransAr[i][j] = -1;
        }
    }

    // 3. 행의 개수를 확인
    while (!feof(fp)) {
        if (chTemp == '\n') {
            break;
        fscanf(fp, "%d%c", &nTemp, &chTemp);
        nCount++;
        }
    
    }
    rewind(fp);

    // 4. 원본 행렬 읽기
    while (!feof(fp)){ 
        for (i = 0; i < nCount; i++) 
            fscanf(fp, "%d", &nAr[nRow][i]);
         nRow++;
    }

    // 5. 원본 행렬 출력
    printf("Original Matrix\n");
    for (i = 0; i < nRow; i++) {
        for (int j = 0; j < nCount; j++) {
            printf("%d\t", nAr[i][j]);
        }
        printf("\n");
    }

    // 6. 전치 행렬
    for (i = 0; i < nRow; i++) {
        for (int j = 0; j < nCount; j++) {
            TransAr[j][i] = nAr[i][j];
        }
    }

    // 7. 전치 행렬 출력
    printf("Translate Matrix\n");
    for (i = 0; i < nCount; i++) {
        for (int j = 0; j < nRow; j++) {
            printf("%d\t", TransAr[i][j]);
        }
        printf("\n");
    }
    fclose(fp);
    return 0;
}