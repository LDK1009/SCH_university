#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int factorial(int n) {
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
}

int power(int x, int n) {
	if (n == 0)
		return 1;
	else
		return x * power(x, n - 1);

}

int fibonacci(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fibonacci(n - 2) + fibonacci(n - 1);

}

int length(char* str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + length(str + 1);
}

char printStr(char* str)
{
	if (*str == '\0')
		return 0;
	else {
		printf("%c", *str);
		printStr(str + 1);
	}
	return 0;
}

char printReverseStr(char* str)
{
	if (*str == '\0')
		return 0;
	else {
		printReverseStr(str + 1);
		printf("%c", *str);

	}
}

int sequentialSearsh(int arr[], int n, int k) {
	if (n <= -1)
		return -1;
	if (arr[n] == k)
		return n;
	else
		return sequentialSearsh(arr, n - 1, k);
}

int main()
{
	int x = 0;
	int n = 0;
	int result = 0;

	char str[] = "Hello World";
	int arr[] = { 1, 2, 3, 4, 5 };

	//printf("String Length : %d\n", length(str));
	//printf("String Print : %c\n", printStr(str));

	//printf("x�� n�� �Է��Ͻÿ�. ");
	//scanf("%d %d", &x, &n);
	//printf("n�� �Է��Ͻÿ�. ");
	//scanf("%d", &n);


	//result = ;

	//printf("\n%d��  ���丮���� %d�Դϴ�. \n\n", n, result);
	//printf("\n%d��  %d���� %d�Դϴ�. \n\n", x, n, result);
	//printf("\n%d��  �Ǻ���ġ�� %d�Դϴ�. \n\n", n, result);
	//printf("\n%s��  ���̴� %d�Դϴ�. \n\n", str, result);
	//printf("\n�����ڿ���");
	//printReverseStr(str);
	//printf("�Դϴ�. \n\n");
	//printf("%d��°�� ã������ �����ֽ��ϴ�.", sequentialSearsh(arr, 5, 3)+1);

	return 0;
}

