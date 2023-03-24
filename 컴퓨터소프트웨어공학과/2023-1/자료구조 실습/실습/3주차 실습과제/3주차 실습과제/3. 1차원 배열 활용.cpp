/*
�а� : ��ǻ�ͼ���Ʈ������а�
�й� : 20194463
�̸� : �̵���
�ۼ����� : 2023.03.19
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int is_ISBN(int ar[]) {
	int nSum = 0;

	for (int i = 0; i < 13; i++) {
		if ((i % 2) == 1) {
			nSum += ar[i] * 3;
		}
		else {
			nSum += ar[i];
		}
	}
	if ((nSum % 10) == 0)
		return 1;
	else
		return 0;
}

int main()
{
	int ISBN[13];
	int nCount = 0;
	int nResult = 0;
	// 1. ���Ͽ��� ������ �о�鿩 1���� �迭�� ����
	FILE* fp = fopen("data1�����迭Ȱ��.txt", "r");
	if (fp == NULL) {
		printf("���Ϸε����");
	}
	while (!feof(fp)) {
		if (nCount > 13) {
			printf("��ȿ���� ���� ISBN ��ȣ�Դϴ�. \n");
		}
		fscanf(fp, "%d", ISBN[nCount]);
		nCount++;
	}
	// 2. 1���� �迭�� ���ڰ����� ISBN ���� Ȯ��
	nResult = is_ISBN(ISBN);

	// 3. �Է¹��� ISBN�� ��ȿ�� ���� ���
	for (int i = 0; i < 13; i++)
		printf("%d", ISBN[i]);

	if (nResult == 1)
		printf("�� ��ȿ�� ISBN �Դϴ�. \n");
	else
		printf("�� ��ȿ���� ���� ISBN�Դϴ�. \n");

	fclose(fp);
	return 0;

}