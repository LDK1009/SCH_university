#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE
int main(void)
{
	FILE *fp;
	char **names;
	char buffer[30]; // 입력을 위한 버퍼. 입력받는 이름의 최대 길이는 99바이트 이내
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

	// Dynamic으로 할당된 배열을 해제
	for (i = 0; i < cnt; i++)  free(names[i]);
	free(names);

	return 0;
}