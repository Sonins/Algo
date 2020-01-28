#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100010
using namespace std;
int memo[2][MAX];
int arr[2][MAX];
int main() {
    int N, T;
    cin >> T;
    for (size_t t = 0; t < T; t++) {
        cin >> N;
        memset(memo, 0, sizeof(memo));
        memset(arr, 0, sizeof(arr));
        for (size_t i = 0; i < 2; i++) {
            for (size_t j = 1; j <= N; j++)
                cin >> arr[i][j];
        }
        
        memo[0][1] = arr[0][1];
        memo[1][1] = arr[1][1];
        memo[0][2] = memo[1][1] + arr[0][2];
        memo[1][2] = memo[0][1] + arr[1][2];
        
        for (size_t i = 3; i <= N; i++) {
            memo[i % 2][i] = max(memo[(i - 1) % 2][i - 1], memo[(i - 1) % 2][i - 2]) + arr[i % 2][i];
            memo[(i - 1) % 2][i] = max(memo[i % 2][i - 1], memo[i % 2][i - 2]) + arr[(i - 1) % 2][i];
        }
        cout << max(memo[0][N], memo[1][N]) << endl;
    }
}