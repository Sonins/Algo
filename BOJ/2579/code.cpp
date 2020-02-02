#include <iostream>
#include <algorithm>
#define MAX 310
using namespace std;
int main() {
    int N;
    cin >> N;
    int arr[MAX];
    int dp[MAX] = {0};
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i + 1];
    }

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for (size_t i = 3; i <= N; i++)
    {
        dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
    }
    cout << dp[N] << endl;
    return 0;
}