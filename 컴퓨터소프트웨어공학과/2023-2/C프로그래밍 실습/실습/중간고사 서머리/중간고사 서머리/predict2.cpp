#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//if �� switch ��ȯ ������
// ���� ����ϱ�
int main(void) {
	int score; //��������

	printf("���� �Է� ���� >> ");
	scanf("%d", &score);

	//if�� ���̽�
	if (score > 90) {
		printf("�ڳ״� A�� \n");
	}
	else if (score > 80) {
		printf("�ڳ״� B��  \n");
	}
	else if (score > 70) {
		printf("�ڳ״� C�� \n");
	}
	else if (score > 60) {
		printf("�ڳ״� D�� \n");
	}
	else if (score > 50) {
		printf("�ڳ״� F��. ���߻���. \n");
	}
	else
	{
		printf("�̰� ����? �������� ���ݾ�? \n");
	}
	printf("�̸� ���ư��� \n");

	//swith�� ���̽�
	switch (score / 10)
	{
	case 9:
		printf("�ڳ״� A�� \n");
		break;
	case 8:
		printf("�ڳ״� B�� \n");
		break;
	case 7:
		printf("�ڳ״� C�� \n");
		break;
	case 6:
		printf("�ڳ״� D�� \n");
		break;
	case 5:
		printf("�ڳ״� F��  ���߻���\n");
		break;
	default:
		printf("�̰� ����? �������� ���ݾ�? \n");
		break;
	}
	printf("���� ����");
}