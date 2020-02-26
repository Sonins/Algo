#include <iostream>
#include <cstring>
#define MAX 1000010
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    bool is_prime[MAX];
    memset(is_prime, true, sizeof(is_prime));
    is_prime[1] = 0;
    is_prime[2] = true;
    for (int i = 4; i < MAX; i += 2)
        is_prime[i] = false;

    for (int i = 3; i < MAX; i += 2) {
        if (!is_prime[i])
            continue;
        
        for (int j = 3; j * j <= i; j += 2) {
            if (!(i % j)) {
                is_prime[i] = false;
                break;
            }
        }

        for (int j = 3 * i; j < MAX; j += 2 * i)
            is_prime[j] = false;
    }

    int M, N;
    cin >> M >> N;
    
    for (size_t i = M; i <= N; i++)
    {
        if (is_prime[i])
            cout << i << '\n';
    }
    return 0;
}