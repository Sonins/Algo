#include <stdio.h>

int main() {
    int dp[21][21][21];
    int a = 0, b = 0, c = 0;
    dp[0][0][0] = 1;
    for (int i = 1; i <= 20; i++) {
        dp[i][0][0] = 1;
        for (int j = 1; j <= 20; j++) {
            dp[i][j][0] = 1;
            dp[0][j][0] = 1;
            for (int k = 1; k <= 20; k++) {
                dp[0][0][k] = 1;
                dp[i][0][k] = 1;
                dp[0][j][k] = 1;
                if (a < b && b < c)
                    dp[i][j][k] =
                        dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
                else dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
            }
        }
    }
    int ans;
    while (true) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) break;
        if (a <= 0 || b <= 0 || c <= 0) ans = 1;
        else if (a > 20 || b > 20 || c > 20) ans = dp[20][20][20];
        else ans = dp[a][b][c];
        printf("w(%d, %d, %d) = %d\n", a, b, c, ans);
    }
    return 0;
}