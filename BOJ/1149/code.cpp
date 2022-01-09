#include <stdio.h>

using namespace std;

#define MAX 1010

int color[MAX][3];

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &color[i][0], &color[i][1], &color[i][2]);
    }

    for (int i = 1; i < N; i++) {
        color[i][0] = min(color[i - 1][1], color[i - 1][2]) + color[i][0];
        color[i][1] = min(color[i - 1][0], color[i - 1][2]) + color[i][1];
        color[i][2] = min(color[i - 1][0], color[i - 1][1]) + color[i][2];
    }

    printf("%d\n", min(min(color[N - 1][0], color[N - 1][1]), color[N - 1][2]));
    return 0;
}