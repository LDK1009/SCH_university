#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//if 와 switch 변환 예상문제
// 성적 출력하기
int main(void) {
	int score; //시험점수

	printf("성적 입력 ㄱㄱ >> ");
	scanf("%d", &score);

	//if문 케이스
	if (score > 90) {
		printf("자네는 A야 \n");
	}
	else if (score > 80) {
		printf("자네는 B야  \n");
	}
	else if (score > 70) {
		printf("자네는 C야 \n");
	}
	else if (score > 60) {
		printf("자네는 D야 \n");
	}
	else if (score > 50) {
		printf("자네는 F야. 빵야빵야. \n");
	}
	else
	{
		printf("이게 뭐야? 시험지가 없잖아? \n");
	}
	printf("이만 돌아가바 \n");

	//swith문 케이스
	switch (score / 10)
	{
	case 9:
		printf("자네는 A야 \n");
		break;
	case 8:
		printf("자네는 B야 \n");
		break;
	case 7:
		printf("자네는 C야 \n");
		break;
	case 6:
		printf("자네는 D야 \n");
		break;
	case 5:
		printf("자네는 F야  빵야빵야\n");
		break;
	default:
		printf("이게 뭐야? 시험지가 없잖아? \n");
		break;
	}
	printf("당장 나가");
}