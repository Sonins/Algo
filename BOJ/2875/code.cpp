#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    int group = 0;

    if (N >= 2 * M) {
        N -= 2 * M;
        group += M;
        K -= N;
    } else {
        M -= N / 2;
        group += N / 2;
        N -= N / 2 * 2;
        K -= N + M;
    }
    N = 0;
    M = 0;

    while (K > 0) {
        group--;
        K -= 3;
    }

    cout << group << '\n';
    return 0;
}