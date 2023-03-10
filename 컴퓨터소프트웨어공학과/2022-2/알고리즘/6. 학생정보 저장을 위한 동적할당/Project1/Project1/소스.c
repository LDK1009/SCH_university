#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student_info
{
	int id;
	char *name;
	int age;
	float height;
}student;

int main(void)
{
	FILE *fp;
	student *std_info, temp;
	char buffer[30]; // 입력을 위한 버퍼. 입력받는 이름의 최대 길이는 30바이트 이내
	int i, cnt = 0;
	int size = 0;

	fp = fopen("student.txt", "r");

	while (!feof(fp))
	{
		fscanf(fp, "%d%s%d%f", &temp.id, buffer, &temp.age, &temp.height);
		cnt++;
	}

	std_info = (student*)malloc(sizeof(student) * cnt);
	rewind(fp);


	for (i = 0; i < cnt; i++)
	{
		fscanf(fp, "%d%s%d%f", &std_info[i].id, buffer, &std_info[i].age, &std_info[i].height);
		size = strlen(buffer);
		std_info[i].name = (char*)malloc(sizeof(char)*(size + 1));
		strcpy(std_info[i].name, buffer);
	}

	fclose(fp);

	for (i = 0; i < cnt; i++)
	{
		printf("%d %s %d %.1f\n", std_info[i].id, std_info[i].name, std_info[i].age, std_info[i].height);
	}

	// 동적할당 해제
	for (i = 0; i < cnt; i++) free(std_info[i].name);
	free(std_info);

	return 0;
}