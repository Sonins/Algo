#include <iostream>
#include <queue>
#include <cstring>

#define MAX 101
using namespace std;

bool found[MAX][MAX];
bool map[MAX][MAX];
int dist[MAX][MAX];

bool check(int N, int M, int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int main() {
    int N, M;
    cin >> M >> N;
    char s[MAX];
    for (size_t i = 0; i < N; i++) {
        cin >> s;
        for (size_t j = 0; j < M; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dist[i][j] = __INT32_MAX__;
        }
    }

    int offx[4] = {0, 1, 0, -1};
    int offy[4] = {1, 0, -1, 0};
    int x, y;

    struct Compare {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return dist[a.first][a.second] > dist[b.first][b.second];
        }
    };

    priority_queue < pair<int, int>, vector<pair<int, int> >, Compare> pq;
    pair<int, int> cur;
    dist[0][0] = 0;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();

        if (found[cur.first][cur.second])
            continue;
        
        if (cur.first == N - 1 && cur.second == M - 1)
            break;
        
        found[cur.first][cur.second] = true;

        for (size_t i = 0; i < 4; i++)
        {
            x = cur.first + offx[i];
            y = cur.second + offy[i];
            if (!found[x][y] && check(N, M, x, y)) {
                dist[x][y] = min(dist[x][y], dist[cur.first][cur.second] + map[x][y]);
                pq.push(make_pair(x, y));
            }
        }   
        
    }

    cout << dist[N - 1][M - 1] << '\n';
    return 0;
}