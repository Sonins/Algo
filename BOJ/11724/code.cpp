#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> g[1010];
bool visited[1010];

int compo_size(int n) {
    queue<int> q;
    int cur;
    int count = 0;
    
    q.push(n);
    visited[n] = true;
    while (!q.empty()) {
        cur = q.front();
        count++;
        q.pop();
        for (size_t i = 0; i < g[cur].size(); i++) {
            if (!visited[g[cur][i]]) {
                q.push(g[cur][i]);
                visited[g[cur][i]] = true;
            } 
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;

    int u, v;
    for (size_t i = 0; i < M; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    int remained_size = N;
    int cnt = 0;
    int start;
    while (remained_size) {
        for (size_t i = 1; i <= N; i++) {
            if (!visited[i]) {
                remained_size -= compo_size(i);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}