#include <stdio.h>
#include <math.h>

int main() {
    int n = 1;
    while (30 * n + 4 > pow(n, 2)) {
        n++;
    }
    printf("30n + 4 가 n^2 보다 작은 최초의 값은 n = %d 일 때입니다.\n", n);
    while (30 * n + 4 < pow(n, 2)) {
        printf("n = %d 일 때, 30n + 4 = %d 이고, n^2 = %d 입니다.\n", n, 30 * n + 4, (int)pow(n, 2));
        n++;
    }
    printf("n = %d 일 때, 30n + 4 = %d 이고, n^2 = %d 입니다.\n", n, 30 * n + 4, (int)pow(n, 2));
    return 0;
}
