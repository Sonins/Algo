#include <iostream>
#include <queue>

using namespace std;

bool house[20][20];

bool hor_check(pair<int, int> p, int N) {
    return p.second + 1 < N && !house[p.first][p.second + 1];
}

bool ver_check(pair<int, int> p, int N) {
    return p.first + 1 < N && !house[p.first + 1][p.second];
}

bool dia_check(pair<int, int> p, int N) {
    return hor_check(p, N) && ver_check(p, N) && !house[p.first + 1][p.second + 1];
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++)
            cin >> house[i][j];
    }

    queue<pair<int, int> > q;
    q.push(make_pair(0, 1));
    queue<int> type;  // 0 hor 1 ver 2 dia
    type.push(0);
    pair<int, int> cur;
    int tcur;
    int ans = 0;
    while (!q.empty()) {
        cur = q.front();
        tcur = type.front();
        q.pop();
        type.pop();

        if (cur.first == N - 1 && cur.second == N - 1) {
            ans++;
            continue;
        }

        if (tcur == 0 || tcur == 2) {
            if (hor_check(cur, N)) {
                q.push(make_pair(cur.first, cur.second + 1));
                type.push(0);
            }
        }

        if (tcur == 1 || tcur == 2) {
            if (ver_check(cur, N)) {
                q.push(make_pair(cur.first + 1, cur.second));
                type.push(1);
            }
        }

        if (dia_check(cur, N)) {
            q.push(make_pair(cur.first + 1, cur.second + 1));
            type.push(2);
        }
    }
    cout << ans << '\n';
    return 0;
}