#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student_info //����ü ����
{
	int id;
	char *name;
	int age;
	float height;
}student;

int main(void)
{
	FILE *fp;
	student *std_info, temp; //*std_info ����ü ����, temp ����ü ���� ����
	char buffer[30]; // �Է��� ���� ����. �Է¹޴� �̸��� �ִ� ���̴� 30����Ʈ �̳�
	int i, cnt = 0;
	int size = 0;

	fp = fopen("student.txt", "r");

	while (!feof(fp)) //���Ͽ� �ؽ�Ʈ���� ���� & cnt ++ //temp ����ü ������ �ؽ�Ʈ ���� �б�
	{
		fscanf(fp, "%d%s%d%f", &temp.id, buffer, &temp.age, &temp.height);
		cnt++;
	}

	std_info = (student*)malloc(sizeof(student) * cnt);
	rewind(fp); //fp�� ��ġ �����ڸ� �� ó������ �����Ѵ� �б�->����, ����->�б� �� �ڵ忡���� �б�(r)->����(w)�� ����


	for (i = 0; i < cnt; i++)
	{
		fscanf(fp, "%d%s%d%f", &std_info[i].id, buffer, &std_info[i].age, &std_info[i].height); //std_info ����ü ������ �ؽ�Ʈ ���� �б�
		size = strlen(buffer); //���ۿ� �Էµ� ���� �� ��ŭ size ���� �ʱ�ȭ
		std_info[i].name = (char*)malloc(sizeof(char)*(size + 1)); //����ü���� �� name ����� ���� �Է� ���� 1�� ū �����Ҵ� �޸� ����
		strcpy(std_info[i].name, buffer); //�����Ҵ�� i��° �޸𸮿��� ���� ���ڿ��� ������ ����
	}

	fclose(fp);

	for (i = 0; i < cnt; i++)
	{
		printf("%d %s %d %.1f\n", std_info[i].id, std_info[i].name, std_info[i].age, std_info[i].height);
	}

	// �����Ҵ� ����
	for (i = 0; i < cnt; i++) free(std_info[i].name);
	free(std_info);

	return 0;
}