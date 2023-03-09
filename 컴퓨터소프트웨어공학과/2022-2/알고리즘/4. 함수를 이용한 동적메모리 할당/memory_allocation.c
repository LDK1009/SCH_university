#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

void allocMemory(int **ptr, int m_size)
{
	int i;

	*ptr = (int *)malloc(sizeof(int)*m_size);    // 포인터 ptr이 가리키고 있는곳에 저장된 값

	for (i = 0; i < m_size; i++)
	{
		(*ptr)[i] = (i + 1) * 10;  // 1*10, 2*10, 3*10 ...10*10
	}

	printf("=== allocMemory 함수 내에서 출력 ===\n"); //동적메모리에 할당된 값을 배열로 취급하여
	for (i = 0; i < m_size; i++)					  //(*ptr)[i]로 값을 불러들임
	{
		printf("%d\n", (*ptr)[i]);
	}
}

int main()
{
	int *numPtr;
	int size = 10;
	int i;

	allocMemory(&numPtr, size); // 포인터 numPtr의 주소값을 보냄

	for (i = 0; i < size; i++)
	{
		numPtr[i] = numPtr[i] + 1;
	}

	printf("=== main 함수 내에서 출력 ===\n");
	for (i = 0; i < size; i++)
	{
		printf("%d\n", numPtr[i]);
	}

	free(numPtr);

	return 0;
}
// int main() 윗 함수는 그냥 함수를 정의한 것 뿐 실행 시에 출력되지않음
// ===allocmemory 에서 출력이 나온것은 28번줄 코드에서 함수를 호출하였기 때문.
// 함수를 호출 해 메모리에 1*10 2*10....을 담은 후 출력한 뒤 함수 호출 밑에 있는 루프 코드들이 실행되어
// 각 메모리의 값에 +1 적용되어 ===main 함수 내 출력에 출력됨
