#include <iostream>
#define MAX 1010
using namespace std;
int memo[MAX];
int main() {
    int N;
    cin >> N;
    memo[1] = 1;
    memo[2] = 3;
    for (size_t i = 3; i <= N; i++)
        memo[i] = (memo[i - 1] + 2 * memo[i - 2]) % 10007;
    cout << memo[N] << endl;
    return 0;
}