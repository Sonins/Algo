#include <algorithm>
#include <iostream>

using namespace std;
long long int dp[510][510];
long long int cost[510][510];

int main() {
    ios::sync_with_stdio(false);
    int T, K;
    cin >> T;

    for (int test = 0; test < T; test++) {
        cin >> K;
        for (int i = 0; i < K; i++) {
            cin >> dp[i][i];
            cost[i][i] = 0;
        }

        for (int r = 1; r < K; r++) {
            for (int i = 0; i + r < K; i++) {
                cost[i][i + r] = __INT64_MAX__;
                for (int j = i; j < i + r; j++) {
                    if (cost[i][i + r] > cost[i][j] + cost[j + 1][i + r] +
                                             dp[i][j] + dp[j + 1][i + r]) {
                        dp[i][i + r] = dp[i][j] + dp[j + 1][i + r];
                        cost[i][i + r] =
                            cost[i][j] + cost[j + 1][i + r] + dp[i][i + r];
                    }
                }
            }
        }
        cout << cost[0][K - 1] << endl;
    }

    return 0;
}