#include <algorithm>
#include <iostream>
#include <queue>
#define MAX 101
using namespace std;
int g[MAX][MAX];
int visit[MAX][MAX];

const int fx[] = {1, 0, -1, 0};
const int fy[] = {0, 1, 0, -1};

bool is_valid(int i, int j, int N) {
    return i > 0 && i <= N && j > 0 && j <= N;
}

void mark_island(int x, int y, int mark, int N) {
    visit[x][y] = true;
    g[x][y] = mark;
    for (size_t i = 0; i < 4; i++) {
        if (is_valid(x + fx[i], y + fy[i], N) && g[x + fx[i]][y + fy[i]] && !visit[x + fx[i]][y + fy[i]])
            mark_island(x + fx[i], y + fy[i], mark, N);
    }
}

bool is_boundary(int x, int y, int N) {
    bool result = true;
    for (size_t i = 0; i < 4; i++) {
        if (is_valid(x + fx[i], y + fy[i], N))
            result = result && g[x + fx[i]][y + fy[i]];
    }

    return !result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j <= N; j++)
            cin >> g[i][j];
    }

    int mark = 1;

    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j <= N; j++) {
            if (!visit[i][j] && g[i][j])
                mark_island(i, j, mark++, N);
        }
    }

    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j <= N; j++)
            visit[i][j] = false;
    }

    queue<pair<int, int> > q;

    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j <= N; j++) {
            if (g[i][j] && is_boundary(i, j, N))
                q.push(make_pair(i, j));
        }
    }

    pair<int, int> cur;
    int x, y;
    int qsize;
    int dist = 0;
    int ans = __INT32_MAX__;
    while (!q.empty()) {
        qsize = q.size();
        dist++;
        for (size_t Q = 0; Q < qsize; Q++) {
            cur = q.front();
            q.pop();
            for (size_t i = 0; i < 4; i++) {
                x = cur.first + fx[i];
                y = cur.second + fy[i];
                if (is_valid(x, y, N) && !g[x][y] && !visit[x][y]) {
                    visit[x][y] = dist;
                    g[x][y] = g[cur.first][cur.second];
                    q.push(make_pair(x, y));
                } else if (visit[x][y] && g[x][y] != g[cur.first][cur.second])
                    ans = min(ans, visit[x][y] + visit[cur.first][cur.second]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}