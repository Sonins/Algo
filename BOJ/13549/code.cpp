#include <algorithm>
#include <iostream>
#include <queue>
#define MAX 100010

using namespace std;

bool visit[MAX];

int main() {
    int N, K;
    cin >> N >> K;
    queue<pair<int, int> > q;

    if (N > 0) {
        for (size_t i = N; i < MAX; i *= 2) {
            q.push(make_pair(i, 0));
            visit[i] = true;
        }
        q.push(make_pair(N - 1, 1));
        visit[N - 1] = true;
    }

    q.push(make_pair(N + 1, 1));
    visit[N + 1] = true;

    pair<int, int> cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (cur.first == K) {
            cout << cur.second << '\n';
            break;
        }

        if (cur.first * 2 < MAX) {
            if (!visit[cur.first * 2]) {
                q.push(make_pair(cur.first * 2, cur.second));
                visit[cur.first * 2] = true;
            }
        }

        if (cur.first + 1 < MAX) {
            if (!visit[cur.first + 1]) {
                q.push(make_pair(cur.first + 1, cur.second + 1));
                visit[cur.first + 1] = true;
            }
        }

        if (cur.first > 0) {
            if (!visit[cur.first - 1]) {
                q.push(make_pair(cur.first - 1, cur.second + 1));
                visit[cur.first - 1] = true;
            }
        }
    }

    return 0;
}