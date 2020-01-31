#include <iostream>
#include <algorithm>
#define MAX 10010
using namespace std;

int max_3(int a, int b, int c) {
    return max(max(a, b), c);
}
int main() {
    int arr[MAX] = {0};
    int dp[MAX] = {0};
    int N;
    cin >> N;
    for (size_t i = 1; i <= N; i++)
        cin >> arr[i];
    
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max_3(arr[1] + arr[2], arr[1] + arr[3], arr[2] + arr[3]);

    for (size_t i = 4; i <= N; i++)
        dp[i] = max_3(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i], dp[i - 1]);
    
    cout << dp[N] << endl;
    return 0;
}