#include <cstdio>
int main() {
    int N;
    scanf("%d", &N);
    int result = 0;
    for (int i = 1; i <= N; i++)
        result += i;
    printf("%d\n", result);
    return 0;
}