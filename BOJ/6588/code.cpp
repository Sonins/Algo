#include <iostream>
#include <cstring>
#define MAX 1000010
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    bool is_prime[MAX];
    int cnt = 0;
    
    memset(is_prime, true, sizeof(is_prime));

    for (size_t i = 2; i * i < MAX; i++) {
        if (is_prime[i]) {
            for (size_t j = i * i; j < MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    int N;

    while (true) {
        cin >> N;

        if (!N)
            break;

        for (size_t i = 3; i <= N / 2; i++) {
            if (is_prime[i] && is_prime[N - i]) {
                cout << N << " = " << i << " + " << N - i << '\n';
                break;
            }
        }
    }
    return 0;
}