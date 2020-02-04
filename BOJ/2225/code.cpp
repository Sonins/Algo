#include <iostream>
#define MAX 210
#define DIV 1000000000
using namespace std;
typedef long long int ll;
int main() {
    int N, K;
    cin >> N;
    cin >> K;

    ll dp[MAX][MAX] = {0};

    for (size_t i = 1; i <= K; i++) {
        dp[0][i] = 1;
        dp[1][i] = i;
    }
    
    for (size_t i = 2; i <= N; i++)
    {
        dp[i][1] = 1;
        dp[i][2] = i + 1;
    }
    
    for (size_t i = 2; i <= N; i++) {
        for (size_t j = 3; j <= K; j++) {
            for (size_t k = 0; k <= i; k++)
            {
                dp[i][j] += dp[k][j - 1];
                dp[i][j] %= DIV;
            }
            
        }
        
    }

    cout << dp[N][K] << endl;
    return 0;
    
}