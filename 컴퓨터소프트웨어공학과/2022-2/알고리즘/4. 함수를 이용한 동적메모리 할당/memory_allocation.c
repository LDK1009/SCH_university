#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

void allocMemory(int **ptr, int m_size)
{
	int i;

	*ptr = (int *)malloc(sizeof(int)*m_size);    // ������ ptr�� ����Ű�� �ִ°��� ����� ��

	for (i = 0; i < m_size; i++)
	{
		(*ptr)[i] = (i + 1) * 10;  // 1*10, 2*10, 3*10 ...10*10
	}

	printf("=== allocMemory �Լ� ������ ��� ===\n"); //�����޸𸮿� �Ҵ�� ���� �迭�� ����Ͽ�
	for (i = 0; i < m_size; i++)					  //(*ptr)[i]�� ���� �ҷ�����
	{
		printf("%d\n", (*ptr)[i]);
	}
}

int main()
{
	int *numPtr;
	int size = 10;
	int i;

	allocMemory(&numPtr, size); // ������ numPtr�� �ּҰ��� ����

	for (i = 0; i < size; i++)
	{
		numPtr[i] = numPtr[i] + 1;
	}

	printf("=== main �Լ� ������ ��� ===\n");
	for (i = 0; i < size; i++)
	{
		printf("%d\n", numPtr[i]);
	}

	free(numPtr);

	return 0;
}
// int main() �� �Լ��� �׳� �Լ��� ������ �� �� ���� �ÿ� ��µ�������
// ===allocmemory ���� ����� ���°��� 28���� �ڵ忡�� �Լ��� ȣ���Ͽ��� ����.
// �Լ��� ȣ�� �� �޸𸮿� 1*10 2*10....�� ���� �� ����� �� �Լ� ȣ�� �ؿ� �ִ� ���� �ڵ���� ����Ǿ�
// �� �޸��� ���� +1 ����Ǿ� ===main �Լ� �� ��¿� ��µ�
