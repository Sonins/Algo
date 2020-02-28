#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, V;
    cin >> N >> M >> V;

    vector<int> edges[1010];
    bool visited[1010];
    
    for (size_t i = 1; i <= N; i++)
        visited[i] = false;

    int x, y;
    for (size_t i = 0; i < M; i++) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    
    for (size_t i = 1; i <= N; i++)
        sort(edges[i].begin(), edges[i].end());
    

    vector<int> s; //stack;
    s.push_back(V);
    int cur;
    while (!s.empty()) {
        cur = s.back();
        s.pop_back();
        if(!visited[cur]) {
            cout << cur << " ";
            visited[cur] = true;
        }
        for (int i = edges[cur].size() - 1; i >= 0; i--) {
            if (!visited[edges[cur][i]])
                s.push_back(edges[cur][i]);
        }
    }
    cout << '\n';

    queue<int> q;

    for (size_t i = 1; i <= N; i++)
        visited[i] = false;
    
    q.push(V);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (!visited[cur]) {
            cout << cur << " ";
            visited[cur] = true;
        }

        for (size_t i = 0; i < edges[cur].size(); i++) {   
            if (!visited[edges[cur][i]])
                q.push(edges[cur][i]);
        }
    }
    cout << '\n';
    return 0;
}