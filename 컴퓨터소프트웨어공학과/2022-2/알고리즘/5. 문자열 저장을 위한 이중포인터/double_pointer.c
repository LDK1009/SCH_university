#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE
int main(void)
{
	FILE *fp;
	char **names;
	char buffer[30]; // �Է��� ���� ����. �Է¹޴� �̸��� �ִ� ���̴� 99����Ʈ �̳�
	int i, cnt = 0;
	int size = 0;

	fp = fopen("station_data.txt", "r");

	while (!feof(fp))
	{
		fscanf(fp, "%s", buffer);
		cnt++;
	}

	names = (char**)malloc(sizeof(char *) * cnt);
	rewind(fp);

	for (i = 0; i < cnt; i++)
	{
		fscanf(fp, "%s", buffer);
		size = strlen(buffer);
		names[i] = (char*)malloc(sizeof(char) * (size + 1));
		strcpy(names[i], buffer);
	}

	for (i = 0; i < cnt; i++)
	{
		printf("%s \n", names[i]);
	}

	fclose(fp);

	// Dynamic���� �Ҵ�� �迭�� ����
	for (i = 0; i < cnt; i++)  free(names[i]);
	free(names);

	return 0;
}