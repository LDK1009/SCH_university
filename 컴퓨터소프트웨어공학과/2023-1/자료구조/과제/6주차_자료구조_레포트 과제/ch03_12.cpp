#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <string>
using namespace std;

typedef struct Node
{
	int item1;
	string item2;
	char string[21];
}Node;

int main()
{
	Node* input;
	input = (Node*)malloc(sizeof(Node));
	input->item1 = 100;
	strcpy(input->item2, "just testing");
	free(input);
	return 0;
}