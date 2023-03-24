/*
학과 : 컴퓨터소프트웨어공학과
학번 : 20194463
이름 : 이동규
작성일자 : 2023.03.19
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
	// 1. 파일에서 데이터 읽어들여 1차원 배열에 저장
	FILE* fp = fopen("data1차원배열활용.txt", "r");
	if (fp == NULL) {
		printf("파일로드실패");
	}
	while (!feof(fp)) {
		if (nCount > 13) {
			printf("유효하지 않은 ISBN 번호입니다. \n");
		}
		fscanf(fp, "%d", ISBN[nCount]);
		nCount++;
	}
	// 2. 1차원 배열을 인자값으로 ISBN 여부 확인
	nResult = is_ISBN(ISBN);

	// 3. 입력받은 ISBN과 유효성 여부 출력
	for (int i = 0; i < 13; i++)
		printf("%d", ISBN[i]);

	if (nResult == 1)
		printf("은 유효한 ISBN 입니다. \n");
	else
		printf("은 유효하지 않은 ISBN입니다. \n");

	fclose(fp);
	return 0;

}