#include <stdio.h>

using namespace std;

int arr[101][2];
int dp[100010];

inline int max(int a, int b) { return a > b ? a : b; }

int main() {
    int N, K;

    scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    for (int j = 1; j <= N; j++) {
        for (int i = K; i > 0; i--) {
            if (i >= arr[j][0])
                dp[i] = max(dp[i - arr[j][0]] + arr[j][1], dp[i]);
        }
    }

    printf("%d\n", dp[K]);

    return 0;
}