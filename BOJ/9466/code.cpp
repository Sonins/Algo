#include <cstring>
#include <iostream>
#define MAX 100010
using namespace std;

int g[MAX];
bool visit[MAX];
bool check[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, N;
    cin >> T;

    int cur, start;
    int cnt = 0;
    for (size_t t = 0; t < T; t++) {
        cin >> N;
        for (size_t i = 1; i <= N; i++) {
            cin >> g[i];
            visit[i] = false;
            check[i] = false;
        }
        cnt = 0;
        for (size_t i = 1; i <= N; i++) {
            cur = i;
            while (!check[cur] && !visit[cur]) {
                check[cur] = true;
                cur = g[cur];
            }

            if (visit[cur]) {
                cur = i;
                while (!visit[cur]) {
                    visit[cur] = true;
                    cur = g[cur];
                }
                continue;
            }

            start = cur;
            do {
                cnt++;
                cur = g[cur];
                
            } while (start != cur);
            cur = i;
            while (!visit[cur]) {
                visit[cur] = true;
                cur = g[cur];
            }
        }
        cout << N - cnt << '\n';
    }
    return 0;
}