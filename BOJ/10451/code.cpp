#include <iostream>
using namespace std;
int g[1010];
bool visited[1010];

void DFS(int n) {
    visited[n] = true;
    if (!visited[g[n]]) {
        DFS(g[n]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    int N;
    int x;
    int cnt = 0;
    cin >> T;
    for (size_t t = 0; t < T; t++) {
        cin >> N;
        cnt = 0;
        for (size_t i = 1; i <= N; i++) {
            g[i] = 0;
            visited[i] = false;
        }

        for (size_t i = 1; i <= N; i++) {
            cin >> x;
            g[i] = x;
        }

        for (size_t i = 1; i <= N; i++) {
            if (!visited[i]) {
                DFS(i);
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}
