#include <iostream>
using namespace std;

pair<int, int> dp[50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, N;
    cin >> T;

    dp[0].first = 1;
    dp[0].second = 0;
    dp[1].first = 0;
    dp[1].second = 1;

    for (size_t i = 2; i <= 40; i++) {
        dp[i].first = dp[i - 1].first + dp[i - 2].first;
        dp[i].second = dp[i - 1].second + dp[i - 2].second;
    }

    for (size_t t = 0; t < T; t++) {
        cin >> N;
        cout << dp[N].first << ' ' << dp[N].second << '\n';
    }
    
    return 0;
}