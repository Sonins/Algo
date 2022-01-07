#include <stdio.h>

using namespace std;

bool visit[10];

int N, M;

char a[16] = "               ";

void sol(int n) {
    if (n == M * 2) {
        printf("%s\n", a);
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (!visit[i]) {
            a[n] = i + '0';
            visit[i] = true;
            sol(n + 2);
            visit[i] = false;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    a[2 * M] = 0;
    sol(0);
}