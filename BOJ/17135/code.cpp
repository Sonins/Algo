#include <iostream>
#include <vector>

using namespace std;

bool tile[20][20];
bool tile_original[20][20];
bool visit[20];
int N, M, D, cnt;

int dist(int x1, int y1, int x2, int y2) {
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

void attack(int a1, int a2, int a3) {
    int min;
    pair<int, int> min_idx;
    pair<int, int> idx[3];
    int archer[3];
    archer[0] = a1;
    archer[1] = a2;
    archer[2] = a3;

    for (int a = 0; a < 3; a++) {
        min = D + 1;
        min_idx.first = -1;
        min_idx.second = -1;
        for (int i = N - 1; i >= 0; i--) {
            for (int j = 0; j < M; j++) {
                if (tile[i][j]) {
                    if (dist(i, j, N, archer[a]) < min ||
                        (dist(i, j, N, archer[a]) == min && j < min_idx.second)) {
                        min = dist(i, j, N, archer[a]);
                        min_idx.first = i;
                        min_idx.second = j;
                    }
                }
            }
        }
        idx[a] = min_idx;
    }

    for (int i = 0; i < 3; i++) {
        if (idx[i].first == -1)
            continue;

        if (tile[idx[i].first][idx[i].second]) {
            cnt++;
            tile[idx[i].first][idx[i].second] = false;
        }
    }
}

void enemy_move() {
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            tile[i + 1][j] = tile[i][j];
            tile[i][j] = false;
        }
    }
}

int main() {
    cin >> N >> M >> D;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> tile_original[i][j];
    }

    int max = 0;
    int max_idx[3];
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            for (int k = j + 1; k < M; k++) {
                copy(&tile_original[0][0], &tile_original[0][0] + 400, &tile[0][0]);

                for (int phase = 0; phase < N; phase++) {
                    attack(i, j, k);
                    enemy_move();
                }

                if (cnt > max) {
                    max = cnt;
                }
                cnt = 0;
            }
        }
    }

    cout << max << endl;
    return 0;
}