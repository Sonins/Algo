#include <algorithm>
#include <iostream>
#define MAX 401
using namespace std;

int dp[MAX][MAX][MAX];
//     box   up  down

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int arr[2][MAX];
    int count[] = {0, 0};
    cin >> N;
    int num;
    for (size_t i = 1; i <= 2 * N; i++) {
        cin >> num;
        if (num) {
            count[i / (N + 1)]++;
            arr[i / (N + 1)][count[i / (N + 1)]] = num;
        }
    }
    dp[1][1][1] = arr[0][1] * arr[1][1];
    for (size_t i = 2; i <= N; i++) {
        for (size_t j = 1; j <= count[0] && j <= i; j++) {
            for (size_t k = 1; k <= count[1] && k <= i; k++) {
                dp[i][j][k] = dp[i - 1][j - 1][k - 1] + arr[0][j] * arr[1][k];
                if (i - 1 >= j && i - 1 >= k)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                if (i - 1 >= k && i - 1 >= j - 1)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k]);
                if (i - 1 >= j && i - 1 >= k - 1)
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
            }
        }
    }
    cout << dp[N][count[0]][count[1]] << '\n';
    return 0;
}