#include <iostream>
#include <string>
#define DIV 1000000
#define MAX 5010
using namespace std;
int main() {
    
    int arr[MAX] = {0};
    int dp[MAX] = {0};
    string s;
    
    cin >> s;
    
    for (size_t i = 0; i < s.size(); i++) {
        arr[i + 1] = s[i] - '0';
        if (arr[i + 1] < 0 || arr[i + 1] >= 10) {
            cout << '0' << endl;
            return 0;
        }
    }

    if (arr[1] == 0) {
        cout << '0' << endl;
        return 0;
    }

    dp[1] = 1;

    if (arr[2] == 0)
        dp[2] = 1;
    else if (arr[1] * 10 + arr[2] <= 26)
        dp[2] = 2;
    else
        dp[2] = 1;
    
    for (size_t i = 3; i <= s.size(); i++) {

        if (arr[i - 1] + arr[i] == 0) {
            cout << 0 << endl;
            return 0;
        }

        if (arr[i] == 0) {
            dp[i] = dp[i - 2];
            continue;
        }
        else
            dp[i] = dp[i - 1];

        if (10 < arr[i - 1] * 10 + arr[i] && arr[i - 1] * 10 + arr[i] <= 26) {
            dp[i] = (dp[i] + dp[i - 2]) % DIV;
        }
        
    }
    cout << dp[s.size()] << endl;
    return 0;
}