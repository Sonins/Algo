#include <iostream>
#include <queue>

using namespace std;

bool house[20][20];
int dp[3][20][20];
int N;

bool check(int x, int y) {
    return x >= 0 && y >= 0 && !house[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++)
            cin >> house[i][j];
    }

    dp[0][0][1] = 1;

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if (i == 0 && j < 2)
                continue;
            if (check(i, j)) {
                if (j - 1 >= 0)
                    dp[0][i][j] += dp[0][i][j - 1] + dp[2][i][j - 1];

                if (i - 1 >= 0)
                    dp[1][i][j] += dp[1][i - 1][j] + dp[2][i - 1][j];
            }

            if (check(i, j) && check(i - 1, j) && check(i, j - 1))
                dp[2][i][j] += dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
        }
    }

    cout << dp[0][N - 1][N - 1] + dp[1][N - 1][N - 1] + dp[2][N - 1][N - 1] << '\n';
    return 0;
}