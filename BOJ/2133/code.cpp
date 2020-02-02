#include <iostream>
#define MAX 40
using namespace std;

int main() {
    int N;
    cin >> N;
    int dp[MAX] = {0};
    dp[0] = 1;
    dp[2] = 3;
    for (size_t i = 4; i <= N; i += 2)
    {
        dp[i] = dp[i - 2] * dp[2];
        for (size_t j = 4; j <= i; j++)
        {   
            dp[i] += dp[i - j] * 2;
        }
        
    }
    
    
    cout << dp[N] << endl;
    return 0;
}