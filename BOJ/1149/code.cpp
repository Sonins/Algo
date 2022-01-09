#include <stdio.h>

#define MAX 1010

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int N;
    int c[MAX][3];
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &c[i][0], &c[i][1], &c[i][2]);
    }

    for (int i = 1; i < N; i++) {
        c[i][0] = min(c[i - 1][1], c[i - 1][2]) + c[i][0];
        c[i][1] = min(c[i - 1][0], c[i - 1][2]) + c[i][1];
        c[i][2] = min(c[i - 1][0], c[i - 1][1]) + c[i][2];
    }

    printf("%d\n", min(min(c[N - 1][0], c[N - 1][1]), c[N - 1][2]));
    return 0;
}