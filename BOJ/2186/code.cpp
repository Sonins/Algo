#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

char table[103][103];
int dp[82][103][103];

int main() {
    ios::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;

    for (size_t i = 0; i < N; i++)
        cin >> table[i];

    string word;
    cin >> word;

    reverse(word.begin(), word.end());

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) {
            if (table[i][j] == word[0])
                dp[0][i][j] = 1;
        }
    }

    int low, high;
    stack<pair<int, int> > s;
    pair<int, int> p;
    for (size_t t = 1; t < word.length(); t++) {

        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < M; j++) {
                if (table[i][j] == word[t])
                    s.push(make_pair(i, j));
            }
        }

        while (!s.empty()) {
            p = s.top();
            s.pop();

            low = max(0, p.first - K);
            high = min(N, p.first + K + 1);

            for (size_t i = low; i < high; i++) {
                if (i == p.first)
                    continue;
                dp[t][p.first][p.second] += dp[t - 1][i][p.second];
            }

            low = max(0, p.second - K);
            high = min(M, p.second + K + 1);

            for (size_t i = low; i < high; i++) {
                if (i == p.second)
                    continue;
                dp[t][p.first][p.second] += dp[t - 1][p.first][i];
            }
        }
    }

    int ans = 0;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++)
            ans += dp[word.length() - 1][i][j];
    }

    cout << ans << '\n';
    return 0;
}
