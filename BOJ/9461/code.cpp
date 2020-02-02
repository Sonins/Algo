#include <iostream>
#include <vector>
#define MAX 110
using namespace std;
typedef long long int lli;
int main() {
    int T;
    cin >> T;
    lli dp[MAX] = {0};
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for (size_t i = 6; i <= 100; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    int N;
    for (size_t t = 0; t < T; t++)
    {
        cin >> N;    
        cout << dp[N] << endl;
    }

    return 0;
}