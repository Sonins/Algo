#include <stdio.h>
#include <queue>
using namespace std;

bool maze[101][101];

bool can_go(int i, int j, int n, int m) {
    return i > 0 && i <= n && j > 0 && j <= m && maze[i][j];
}

const int xoff[] = {1, 0, -1, 0};
const int yoff[] = {0, 1, 0, -1};

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    char s[101];

    for (size_t i = 1; i <= N; i++) {
        scanf("%s", s);
        for (size_t j = 0; j < M; j++)
            maze[i][j + 1] = s[j] - '0';
    }

    queue<pair<int, int> > q;
    q.push(make_pair(1, 1));

    pair<int, int> cur;
    int tile = 0;
    int qsize;
    int x, y;
    while (!q.empty()) {
        tile++;
        qsize = q.size();
        for (size_t Q = 0; Q < qsize; Q++) {
            cur = q.front();
            if (cur.first == N && cur.second == M) {
                printf("%d\n", tile);
                return 0;
            }

            q.pop();

            for (size_t i = 0; i < 4; i++) {
                x = cur.first + xoff[i];
                y = cur.second + yoff[i];
                if (can_go(x, y, N, M)) {
                    q.push(make_pair(x, y));
                    maze[x][y] = 0;
                }
            }
        }
    }
    return 0;
}