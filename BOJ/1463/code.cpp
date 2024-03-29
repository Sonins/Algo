#include <iostream>
#include <algorithm>
#define MAX 1000010
using namespace std;
int memo[MAX];
int main() {
    int N;
    cin >> N;
    memo[2] = 1;
    memo[3] = 1;
    for (int i = 4; i <= N; i++) {
        memo[i] = memo[i - 1] + 1;
        if (i % 3 == 0)
            memo[i] = min(memo[i / 3] + 1, memo[i]);
        if (i % 2 == 0)
            memo[i] = min(memo[i / 2] + 1, memo[i]);
        
    }
    cout << memo[N] << '\n';
    return 0;
}