#include <iostream>
#include <algorithm>
#define MAX 1010
using namespace std;
int main() {
    int N;
    cin >> N;

    int arr[MAX];
    int dp[MAX] = {0};

    for (size_t i = 0; i < N; i++)
        cin >> arr[i + 1];
    
    dp[1] = arr[1];

    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j < i; j++) {
            if (dp[j] + arr[i] > dp[i] && arr[i] > arr[j])
                dp[i] = dp[j] + arr[i];
        }
        if (!dp[i])
            dp[i] = arr[i];
    }
    
    int _max = -0x7fffffff;

    for (size_t i = 1; i <= N; i++)
        _max = max(_max, dp[i]);
    
    cout << _max << endl;
    return 0;
}