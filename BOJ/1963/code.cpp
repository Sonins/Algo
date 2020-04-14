#include <cstring>
#include <iostream>
#include <queue>
#define MIN 1000
#define MAX 10000
using namespace std;
bool is_prime[MAX];
int power_10[4] = {1, 10, 100, 1000};
int to_digit(int N, int k) {
    switch (k) {
        case 0:
            return N % 10;
        case 1:
            return ((N / 10) % 10) * 10;
        case 2:
            return ((N / 100) % 10) * 100;
        case 3:
            return (N / 1000) * 1000;
        default:
            break;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    memset(is_prime, true, sizeof(is_prime));

    for (size_t i = 4; i < MAX; i += 2)
        is_prime[i] = false;

    for (size_t i = 3; i * i < MAX; i++) {
        if (!is_prime[i])
            continue;

        for (size_t j = 2 * i; j < MAX; j += i)
            is_prime[j] = false;
    }

    int T;
    cin >> T;
    int s, e;
    for (size_t t = 0; t < T; t++) {
        cin >> s >> e;
        queue<int> q;
        int cur;
        int cnt[MAX];
        int cand;
        memset(cnt, 0, sizeof(cnt));
        q.push(s);
        cnt[s] = 1;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            if (cur == e) {
                cout << cnt[cur] - 1 << '\n';
                break;
            }
            
            for (size_t i = 0; i < 4; i++) {
                for (size_t j = 0; j < 10; j++) {
                    cand = cur - to_digit(cur, i) + j * power_10[i];
                    if (is_prime[cand] && !cnt[cand] && cand > 1000) {
                        q.push(cand);
                        cnt[cand] = cnt[cur] + 1;
                    }
                }
            }
        }

        if (cur != e)
            cout << "Impossible" << '\n';
    }
    return 0;
}