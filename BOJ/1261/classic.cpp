#include <iostream>

#define MAX 101
using namespace std;

bool found[MAX][MAX];
bool map[MAX][MAX];
int dist[MAX][MAX];

pair<int, int> choose(int N, int M) {
    int min = __INT32_MAX__;
    pair<int, int> min_idx;

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) {
            if (min > dist[i][j] && !found[i][j]) {
                min = dist[i][j];
                min_idx.first = i;
                min_idx.second = j;
            }
        }
    }

    return min_idx;
}

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

    for (size_t i = 1; i < M; i++) {
        dist[0][i] = map[0][i];
        dist[0][i] += dist[0][i - 1];
    }

    for (size_t i = 1; i < N; i++) {
        dist[i][0] = map[i][0];
        dist[i][0] += dist[i - 1][0];
    }

    for (size_t i = 1; i < N; i++) {
        for (size_t j = 1; j < M; j++)
            dist[i][j] = (dist[i - 1][j] > dist[i][j - 1] ? dist[i][j - 1] : dist[i - 1][j]) + map[i][j];
    }

    found[0][0] = true;
    pair<int, int> idx;
    int offx[4] = {0, 1, 0, -1};
    int offy[4] = {1, 0, -1, 0};
    int x, y;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) {
            if (found[N - 1][M - 1])
                break;
            idx = choose(N, M);
            found[idx.first][idx.second] = true;

            for (size_t k = 0; k < 4; k++) {
                x = idx.first + offx[k];
                y = idx.second + offy[k];
                if (dist[x][y] > dist[idx.first][idx.second] + map[x][y] && check(N, M, x, y))
                    dist[x][y] = dist[idx.first][idx.second] + map[x][y];
            }
        }
    }
    cout << dist[N - 1][M - 1] << '\n';
    return 0;
}