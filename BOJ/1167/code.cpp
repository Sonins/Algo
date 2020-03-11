#include <cstring>
#include <iostream>
#include <vector>
#define MAX 100010

using namespace std;

vector<pair<int, int> > e[MAX];
bool visit[MAX];

int farnode, far;

void DFS(int node, int cost) {
    if (visit[node])
        return;

    visit[node] = true;

    if (cost > far) {
        farnode = node;
        far = cost;
    }
    int next;
    int next_cost;
    for (size_t i = 0; i < e[node].size(); i++) {
        next = e[node][i].first;
        next_cost = cost + e[node][i].second;
        DFS(next, next_cost);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V;
    cin >> V;

    int u, v, w;
    for (size_t i = 0; i < V; i++) {
        cin >> u >> v;
        while (v != -1) {
            cin >> w;
            e[u].push_back(make_pair(v, w));
            e[v].push_back(make_pair(u, w));
            cin >> v;
        }
    }

    DFS(1, 0);

    memset(visit, false, sizeof(visit));
    far = 0;

    DFS(farnode, 0);

    cout << far << '\n';

    return 0;
}