/*
�а� : ��ǻ�ͼ���Ʈ������а�
�й� : 20194463
�̸� : �̵���
�ۼ����� : 2023.03.19
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
    // 1. ������ ���� ����
    fp = fopen("data_���߹迭.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file.");
        return 1;
    }

    // 2. ��� ������ �ʱ�ȭ
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            nAr[i][j] = -1;
            TransAr[i][j] = -1;
        }
    }

    // 3. ���� ������ Ȯ��
    while (!feof(fp)) {
        if (chTemp == '\n') {
            break;
        fscanf(fp, "%d%c", &nTemp, &chTemp);
        nCount++;
        }
    
    }
    rewind(fp);

    // 4. ���� ��� �б�
    while (!feof(fp)){ 
        for (i = 0; i < nCount; i++) 
            fscanf(fp, "%d", &nAr[nRow][i]);
         nRow++;
    }

    // 5. ���� ��� ���
    printf("Original Matrix\n");
    for (i = 0; i < nRow; i++) {
        for (int j = 0; j < nCount; j++) {
            printf("%d\t", nAr[i][j]);
        }
        printf("\n");
    }

    // 6. ��ġ ���
    for (i = 0; i < nRow; i++) {
        for (int j = 0; j < nCount; j++) {
            TransAr[j][i] = nAr[i][j];
        }
    }

    // 7. ��ġ ��� ���
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