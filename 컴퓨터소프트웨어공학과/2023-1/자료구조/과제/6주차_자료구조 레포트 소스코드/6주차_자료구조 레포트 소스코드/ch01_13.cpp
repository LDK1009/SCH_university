#include <stdio.h>
#include <math.h>

int main() {
    int n = 1;
    while (30 * n + 4 > pow(n, 2)) {
        n++;
    }
    printf("30n + 4 �� n^2 ���� ���� ������ ���� n = %d �� ���Դϴ�.\n", n);
    while (30 * n + 4 < pow(n, 2)) {
        printf("n = %d �� ��, 30n + 4 = %d �̰�, n^2 = %d �Դϴ�.\n", n, 30 * n + 4, (int)pow(n, 2));
        n++;
    }
    printf("n = %d �� ��, 30n + 4 = %d �̰�, n^2 = %d �Դϴ�.\n", n, 30 * n + 4, (int)pow(n, 2));
    return 0;
}
