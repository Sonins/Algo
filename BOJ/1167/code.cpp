#include <iostream>
#include <stack>
#include <vector>
#define MAX 100010

using namespace std;

vector<pair<int, int> > e[MAX];
int cu_weight[MAX];

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

    stack<int> s;
    s.push(1);
    cu_weight[1] = 1;
    int max_weight = 0, max_node;
    int cur;
    while (!s.empty()) {
        cur = s.top();
        s.pop();
        for (size_t i = 0; i < e[cur].size(); i++) {
            if (!cu_weight[e[cur][i].first]) {
                s.push(e[cur][i].first);
                cu_weight[e[cur][i].first] = cu_weight[cur] + e[cur][i].second;
                if (max_weight < cu_weight[e[cur][i].first]) {
                    max_weight = cu_weight[e[cur][i].first];
                    max_node = e[cur][i].first;
                }
            }
        }
    }

    s.push(max_node);
    max_weight = 0;

    for (size_t i = 0; i < MAX; i++)
        cu_weight[i] = 0;

    cu_weight[max_node] = 1;
    while (!s.empty()) {
        cur = s.top();
        s.pop();
        for (size_t i = 0; i < e[cur].size(); i++) {
            if (!cu_weight[e[cur][i].first]) {
                s.push(e[cur][i].first);
                cu_weight[e[cur][i].first] = cu_weight[cur] + e[cur][i].second;
                if (max_weight < cu_weight[e[cur][i].first]) {
                    max_weight = cu_weight[e[cur][i].first];
                    max_node = e[cur][i].first;
                }
            }
        }
    }
    cout << max_weight - 1 << '\n';
    return 0;
}