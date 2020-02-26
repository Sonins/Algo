#include <iostream>
#include <cstring>
#define MAX 3500
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int N;
    cin >> N;
    bool is_prime[MAX];
    memset(is_prime, true, sizeof(is_prime));

    is_prime[1] = false;
    for (size_t i = 2; i * i <= MAX; i++) {
        if (is_prime[i]) {
            for (size_t j = i * i; j < MAX; j += i)
                is_prime[j] = false;
        }
    }

    bool changed = 0;
    while (true) {
        for (size_t i = 2; i < MAX; i++) {
            if (is_prime[i] && !(N % i)) {
                cout << i << '\n';
                N = N / i;
                changed = true;
                break;
            }
        }

        if (N == 1)
            break;

        if (N > MAX && !changed) {
            cout << N << '\n';
            break;
        }

        changed = false;
    }
    return 0;
}