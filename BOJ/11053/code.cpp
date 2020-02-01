#include <iostream>
#include <algorithm>
#define MAX 1010
using namespace std;
int main() {
    int N;
    cin >> N;
    int arr[MAX];
    int dp[MAX] = {0};

    for (size_t i = 1; i <= N; i++)
        cin >> arr[i];
    
    dp[1] = 1;

    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j < i; j++) {
            if (dp[j] + 1 > dp[i] && arr[i] > arr[j])
                dp[i] = dp[j] + 1;
        }
        if (!dp[i])
            dp[i] = 1;
    }

    int _max = -__INT32_MAX__;

    for (size_t i = 1; i <= N; i++)
        _max = max(_max, dp[i]);
    
    cout << _max << endl;
    return 0;
}