#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 100010
using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<int> sqrs;
    int dp[MAX] = {0};


    for (size_t i = 1; i <= sqrt(MAX); i++)
        sqrs.push_back(i * i);
        
    for (size_t i = 1; i <= N; i++)
    {
        dp[i] = __INT32_MAX__;
        for (size_t j = 1; j <= sqrt(i); j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);   
        }
    }
    cout << dp[N] << endl;
    
    return 0;
}
