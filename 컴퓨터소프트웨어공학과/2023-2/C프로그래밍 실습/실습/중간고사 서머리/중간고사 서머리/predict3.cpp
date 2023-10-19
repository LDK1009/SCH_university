#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	// for while문 변환
	int love;

	love = 0;
	printf("==========for문으로 변환========== \n");
	for (int i = 0; i < 5; i++) {
		love++;
		printf("사랑이 증가합니다 현재 사랑은 : %d 입니다 \n", love);
	}

	printf("==========while문으로 변환========== \n");
	love = 0;

	while (love < 5)
	{
		love++;
		printf("사랑이 증가합니다 현재 사랑은 : %d 입니다 \n", love);
	}
}

