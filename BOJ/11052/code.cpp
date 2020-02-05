#include <iostream>
#include <algorithm>
#define MAX 1010

using namespace std;

int main() {
    int N;
    cin >> N;
    int arr[MAX];
    for (size_t i = 0; i < N; i++)
        cin >> arr[i + 1];
    int dp[MAX] = {0};
    dp[1] = arr[1];

    for (size_t i = 2; i <= N; i++) {
        for (size_t j = 1; j <= i; j++)
            dp[i] = max(dp[i], dp[i - j] + arr[j]);
    }
    
    cout << dp[N] << endl;
    return 0;
}