#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student_info //구조체 생성
{
	int id;
	char *name;
	int age;
	float height;
}student;

int main(void)
{
	FILE *fp;
	student *std_info, temp; //*std_info 구조체 변수, temp 구조체 변수 생성
	char buffer[30]; // 입력을 위한 버퍼. 입력받는 이름의 최대 길이는 30바이트 이내
	int i, cnt = 0;
	int size = 0;

	fp = fopen("student.txt", "r");

	while (!feof(fp)) //파일에 텍스트파일 저장 & cnt ++ //temp 구조체 변수에 텍스트 파일 읽기
	{
		fscanf(fp, "%d%s%d%f", &temp.id, buffer, &temp.age, &temp.height);
		cnt++;
	}

	std_info = (student*)malloc(sizeof(student) * cnt);
	rewind(fp); //fp의 위치 지정자를 맨 처음으로 설정한다 읽기->쓰기, 쓰기->읽기 위 코드에서는 읽기(r)->쓰기(w)로 변경


	for (i = 0; i < cnt; i++)
	{
		fscanf(fp, "%d%s%d%f", &std_info[i].id, buffer, &std_info[i].age, &std_info[i].height); //std_info 구조체 변수에 텍스트 파일 읽기
		size = strlen(buffer); //버퍼에 입력된 글자 수 만큼 size 변수 초기화
		std_info[i].name = (char*)malloc(sizeof(char)*(size + 1)); //구조체변수 중 name 멤버에 버퍼 입력 보다 1이 큰 동적할당 메모리 생성
		strcpy(std_info[i].name, buffer); //동적할당된 i번째 메모리에서 버퍼 문자열을 꺼내어 복사
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