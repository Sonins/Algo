#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> g[20010];
int mark_num[20010];
string ans;

void DFS(int n) {
    if (ans == "NO")
        return;

    for (auto i : g[n]) {
        if (!mark_num[i]) {
            mark_num[i] = mark_num[n] + 1;
            DFS(i);
        } else if (!((mark_num[i] - mark_num[n]) % 2)) {
            ans = "NO";
            break;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, v, e;
    int x, y;
    cin >> t;
    for (size_t T = 0; T < t; T++) {
        cin >> v >> e;
        for (size_t i = 1; i <= v; i++) {
            mark_num[i] = 0;
            g[i].clear();
        }
        
        for (size_t i = 0; i < e; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
    
        ans = "YES";
        for (size_t i = 1; i <= v; i++) {
            if (!mark_num[i]) {
                mark_num[i] = 1;
                DFS(i);
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}