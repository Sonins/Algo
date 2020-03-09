#include <iostream>
#include <queue>
#include <vector>
#define MAX 100010

using namespace std;

vector<int> e[MAX];
int parent[MAX];
int visit[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int x, y;

    for (size_t i = 0; i < N - 1; i++) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    visit[1] = true;
    
    int cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (auto i : e[cur]) {
            if (!visit[i]) {
                q.push(i);
                visit[i] = true;
                parent[i] = cur;
            }
        }
    }

    for (size_t i = 2; i <= N; i++)
        cout << parent[i] << '\n';

    return 0;
}