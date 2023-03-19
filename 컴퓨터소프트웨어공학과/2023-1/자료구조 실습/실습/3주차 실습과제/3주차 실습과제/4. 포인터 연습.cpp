#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


void reverse(char*, char*);

int main()
{
	char name[50], reverseName[50] = { 0 };

	printf("이름을 입력하세요. : ");
	scanf("%s", name);

	reverse(name, reverseName);
	printf("뒤집은 이름: %s\n", reverseName);

}

void reverse(char* name, char* revname)
{
	int count = strlen(name);

	int i, j;
	for (i = count - 1, j = 0; i >= 0; i--, j++)
		*(revname + j) = *(name + i);
	*(revname + j + 1) = '\0';
}