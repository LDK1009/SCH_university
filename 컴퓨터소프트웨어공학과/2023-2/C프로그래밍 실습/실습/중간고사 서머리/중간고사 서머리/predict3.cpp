#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	// for while�� ��ȯ
	int love;

	love = 0;
	printf("==========for������ ��ȯ========== \n");
	for (int i = 0; i < 5; i++) {
		love++;
		printf("����� �����մϴ� ���� ����� : %d �Դϴ� \n", love);
	}

	printf("==========while������ ��ȯ========== \n");
	love = 0;

	while (love < 5)
	{
		love++;
		printf("����� �����մϴ� ���� ����� : %d �Դϴ� \n", love);
	}
}

