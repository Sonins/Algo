#include <cstdio>
int main() {
    int N;
    scanf("%d", &N);
    int cand;
    int max = -__INT32_MAX__;
    int min = __INT32_MAX__;
    for (int i = 0; i < N; i++) {
        scanf("%d", &cand);
        if (max < cand)
            max = cand;
        if (min > cand)
            min = cand;
    }
    printf("%d %d", min, max);
    return 0;
}