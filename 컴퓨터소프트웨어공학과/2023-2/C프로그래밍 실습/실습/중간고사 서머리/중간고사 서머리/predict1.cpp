#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//1. ���α׷� ����
int main(void) {
    //2. �ð� ���� ����(�׸�)
    int time;
    //3. �ð� �Է¹ޱ�(����纯��)
    printf("�ð��� �Է��ϼ��� >>");
    scanf("%d", &time);

    //4. ���ǹ�(������)
    if (time < 12) {
        printf("���� �Դϴ� \n");
    }
    else {
        printf("���� �Դϴ�. \n");
    }

    //5.���α׷� �� �˸�(���� �纯��)
    printf("���α׷� ��! \n");
}