#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 4
#define COLS 4

/*
    �ۼ���:2023.04.13
    �ۼ���: ��ǻ�ͼ���Ʈ������а� / 20194463 / �̵���
    ���α׷���: �����Ҵ��� �̿��� �� ��� �� ���� ���α׷�
*/

// ���ϱ� ���� �Լ�
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

// ���� ���� �Լ�
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

// ���ϱ� ���� �Լ�
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
    int** arr1, ** arr2, ** result; // ���� �Ҵ��� ���� ������ ����

    // 2���� �迭 2���� ��� ��� ��� �迭�� �������� �Ҵ��Ѵ�.
    arr1 = (int**)malloc(ROWS * sizeof(int*));
    arr2 = (int**)malloc(ROWS * sizeof(int*));
    result = (int**)malloc(ROWS * sizeof(int*));

    for (i = 0; i < ROWS; i++)
    {
        arr1[i] = (int*)malloc(COLS * sizeof(int));
        arr2[i] = (int*)malloc(COLS * sizeof(int));
        result[i] = (int*)malloc(COLS * sizeof(int));
    }

    // ���� ���� & ������ ����
    FILE* fp = fopen("data02.txt", "r");

    // ���� ���� ���� ��
    if (fp == NULL)
    {
        printf("Failed to open file.\n");
        return 1;
    }

    // arr1 ������ ����
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            fscanf(fp, "%d", &arr1[i][j]);
        }
    }

    // arr2 ������ ����
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            fscanf(fp, "%d", &arr2[i][j]);
        }
    }

    // close file
    fclose(fp);

    // ���� ��� ���
    printf("===============���ϱ� ����===============");
    add_matrices(arr1, arr2, result);

    printf("===============���� ����===============");
    subtract_matrices(arr1, arr2, result);

    printf("===============���ϱ� ����===============");
    multiply_matrices(arr1, arr2, result);

    // �Ҵ�� �޸𸮸� ����
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