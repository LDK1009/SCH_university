#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int n) {
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

//int power(int x, int n) {
//	if (n == 0)
//		return 1;
//	else
//		return x * power(x, n - 1);
//
//}
//
//int fibonacci(int n) 
//{
//	if (n == 0)
//		return 0;
//	if (n == 1)
//		return 1;
//	return fibonacci(n - 2) + fibonacci(n - 1);
//
//}
//
//int length(char* str)
//{
//	if (*str == '\0')
//		return 0;
//	else
//		return 1 + length(str + 1);
//}
//
//char printStr(char* str)
//{
//	if (*str == '\0')
//		return 0;
//	return
//	{
//	printf("%c", *str);
//	printStr(str + 1);
//	}
//}
//
//char printReverseStr(char* str)
//{
//	if (*str == '\0')
//		return 0;
//	return {
//	printReverseStr(str + 1);
//	printf("%c", *str);
//	}
//}

int maze[8][10] =
{
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 0, 0, 0, 0, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 0, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 0, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 0, 1, 1,
};

int visited[8][10]; // 지나온 경로 마킹

int mazeExplorer(int i, int j)
{
	visited[i][j] = 1;
	printf("%d, %d\n", i, j);

	if (j + 1 < 10 && maze[i][j + 1] != 1 && cisited[i][j + 1] == 0) // 동쪽으로이동하는 경우
		mazeExplorer(i, j + 1);

	if (j - 1 < 0 && maze[i][j -1] != 1 && cisited[i][j - 1] == 0) // 서쪽으로이동하는 경우
		mazeExplorer(i, j - 1);


	if (i + 1 < 8 && maze[i+1][j] != 1 && cisited[i+1][j] == 0) // 남쪽으로이동하는 경우
		mazeExplorer(i+1, j);

	if (i - 1 >= 0 && maze[i + 1][j] != 1 && cisited[i + 1][j] == 0) // 북쪽으로이동하는 경우
		mazeExplorer(i-1, j);

}

int main()
{
	prnitf("Maze Exploring Statt \n");
	mazeExplorer(1, 0);
	printf("Maze Exploring Finish \n");
}

int main()
{
	int n;
	int result;

	//char str[] = "Hello World \n";

	//printf("String Length : %d\n", length(str));
	//printf("String Print : %c\n", printStr(str));

	printf("n을 입력하시오. ");
	scanf("%d", &n);

	result = factorial(n);

	printf("\n%d의 팩토리얼 결과는 %d입니다. \n\n", n, result);

	return 0;
}

