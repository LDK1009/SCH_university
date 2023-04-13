#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 4
#define COLS 4

/*
    작성일:2023.04.13
    작성자: 컴퓨터소프트웨어공학과 / 20194463 / 이동규
    프로그램명: 동적할당을 이용한 두 행렬 간 연산 프로그램
*/

// 더하기 연산 함수
void add_matrices(int** a, int** b, int** result)
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (j % 4 == 0)
                printf("\n");
            printf("%d \t", result[i][j]);
        }
    }
    printf("\n\n");
}

// 빼기 연산 함수
void subtract_matrices(int** a, int** b, int** result)
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            result[i][j] = a[i][j] - b[i][j];
        }
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (j % 4 == 0)
                printf("\n");
            printf("%d \t", result[i][j]);
        }
    }
    printf("\n\n");
}

// 곱하기 연산 함수
void multiply_matrices(int** a, int** b, int** result)
{
    int i, j, k;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            result[i][j] = a[i][j] * b[i][j];
        }
    }
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (j % 4 == 0)
                printf("\n");
            printf("%d \t", result[i][j]);
        }
    }
    printf("\n\n");
}

int main()
{
    int i, j;
    int** arr1, ** arr2, ** result; // 동적 할당을 위해 포인터 선언

    // 2차원 배열 2개와 산술 결과 출력 배열을 동적으로 할당한다.
    arr1 = (int**)malloc(ROWS * sizeof(int*));
    arr2 = (int**)malloc(ROWS * sizeof(int*));
    result = (int**)malloc(ROWS * sizeof(int*));

    for (i = 0; i < ROWS; i++)
    {
        arr1[i] = (int*)malloc(COLS * sizeof(int));
        arr2[i] = (int*)malloc(COLS * sizeof(int));
        result[i] = (int*)malloc(COLS * sizeof(int));
    }

    // 파일 오픈 & 데이터 리드
    FILE* fp = fopen("data02.txt", "r");

    // 파일 오픈 실패 시
    if (fp == NULL)
    {
        printf("Failed to open file.\n");
        return 1;
    }

    // arr1 데이터 리드
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            fscanf(fp, "%d", &arr1[i][j]);
        }
    }

    // arr2 데이터 리드
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            fscanf(fp, "%d", &arr2[i][j]);
        }
    }

    // close file
    fclose(fp);

    // 연산 결과 출력
    printf("===============더하기 연산===============");
    add_matrices(arr1, arr2, result);

    printf("===============빼기 연산===============");
    subtract_matrices(arr1, arr2, result);

    printf("===============곱하기 연산===============");
    multiply_matrices(arr1, arr2, result);

    // 할당된 메모리를 해제
    for (i = 0; i < ROWS; i++)
    {
        free(arr1[i]);
        free(arr2[i]);
        free(result[i]);
    }

    free(arr1);
    free(arr2);
    free(result);

    return 0;
}