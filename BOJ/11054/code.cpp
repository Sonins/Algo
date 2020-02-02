#include <iostream>
#include <algorithm>
#define MAX 1010
using namespace std;
int main() {
    int N;
    cin >> N;
    int arr[MAX];
    int inc_dp[MAX] = {0};
    int dec_dp[MAX] = {0};
    int _max = -INT32_MAX;

    for (size_t i = 0; i < N; i++)
        cin >> arr[i + 1];
    
    inc_dp[1] = 1;
    dec_dp[N] = 1;

    for (size_t i = 1; i <= N; i++)
    {
        for (size_t j = 1; j < i; j++)
        {
            if (inc_dp[j] + 1 > inc_dp[i] && arr[i] > arr[j])
                inc_dp[i] = inc_dp[j] + 1;

            if (dec_dp[N - j + 1] + 1 > dec_dp[N - i + 1] && arr[N - i + 1] > arr[N - j + 1])
                dec_dp[N - i + 1] = dec_dp[N - j + 1] + 1;
        }
        if (!inc_dp[i])
            inc_dp[i] = 1;
        if (!dec_dp[N - i + 1])
            dec_dp[N - i + 1] = 1;
    }

    for (size_t i = 1; i <= N; i++)
        _max = max(_max, inc_dp[i] + dec_dp[i]);

    cout << _max - 1 << endl;
    return 0;
    
}