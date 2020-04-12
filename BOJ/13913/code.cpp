#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define MAX 100010

using namespace std;

bool visit[MAX];

int main() {
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;

    if (K < N) {
        cout << N - K << '\n';
        for (int i = N; i >= K; i--)
            cout << i << ' ';
        cout << '\n';
        return 0;
    }

    queue<pair<int, int> > q;
    pair<int, int> cur;
    int pos, time, idx;
    int before[MAX];
    vector<int> order;

    visit[N] = true;
    q.push(make_pair(N, 0));

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        pos = cur.first;
        time = cur.second;
        
        if (pos == K) {
            cout << time << '\n';
            idx = pos;

            while (idx != N) {
                order.push_back(idx);
                idx = before[idx];
            }
            cout << N << ' ';
            for (int i = order.size() - 1; i >= 0; i--)
                cout << order[i] << ' ';
            
            cout << '\n';
            break;
        }

        if (pos * 2 < MAX) {
            if (!visit[pos * 2]) {
                q.push(make_pair(pos * 2, time + 1));
                before[pos * 2] = pos;
                visit[pos * 2] = true;
            }
        }

        if (pos + 1 < MAX) {
            if (!visit[pos + 1]) {
                q.push(make_pair(pos + 1, time + 1));
                before[pos + 1] = pos;
                visit[pos + 1] = true;
            }
        }

        if (pos > 0) {
            if (!visit[pos - 1]) {
                q.push(make_pair(pos - 1, time + 1));
                before[pos - 1] = pos;
                visit[pos - 1] = true;
            }
        }
    }

    return 0;
}