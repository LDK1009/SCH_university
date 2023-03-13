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

	//printf("x와 n을 입력하시오. ");
	//scanf("%d %d", &x, &n);
	//printf("n을 입력하시오. ");
	//scanf("%d", &n);


	//result = ;

	//printf("\n%d의  팩토리얼은 %d입니다. \n\n", n, result);
	//printf("\n%d의  %d승은 %d입니다. \n\n", x, n, result);
	//printf("\n%d의  피보나치는 %d입니다. \n\n", n, result);
	//printf("\n%s의  길이는 %d입니다. \n\n", str, result);
	//printf("\n역문자열은");
	//printReverseStr(str);
	//printf("입니다. \n\n");
	//printf("%d번째에 찾으려는 값이있습니다.", sequentialSearsh(arr, 5, 3)+1);

	return 0;
}

