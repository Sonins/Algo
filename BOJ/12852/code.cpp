#include <iostream>
#define MAX 1000010
using namespace std;

int dp[MAX];
int before[MAX];

int main() {
    int N;
    cin >> N;
    dp[2] = 1;
    dp[3] = 1;
    before[2] = 1;
    before[3] = 1;
    
    for (size_t i = 4; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        before[i] = i - 1;
        if (!(i % 2) && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            before[i] = i / 2;
        }
        if (!(i % 3) && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            before[i] = i / 3;
        }

    }
    cout << dp[N] << '\n';

    while (N) {
        cout << N << " ";
        N = before[N];
    }
    cout << '\n';
    return 0;
}