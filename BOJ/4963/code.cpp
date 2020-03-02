#include <iostream>
#define MAX 60
using namespace std;

bool g[MAX][MAX];
bool visit[MAX][MAX];

void DFS_visit(int i, int j);

void DFS(int i, int j) {
    visit[i][j] = true;
    DFS_visit(i + 1, j);      // ↑
    DFS_visit(i + 1, j - 1);  // ↖
    DFS_visit(i, j - 1);      // ←
    DFS_visit(i - 1, j - 1);  // ↙
    DFS_visit(i - 1, j);      // ↓
    DFS_visit(i - 1, j + 1);  // ↘
    DFS_visit(i, j + 1);      // →
    DFS_visit(i + 1, j + 1);  // ↗
}

void DFS_visit(int i, int j) {
    if (i > 0 && i < MAX && j > 0 && j < MAX && g[i][j] && !visit[i][j])
        DFS(i, j);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int w, h;
    cin >> w >> h;
    int cnt;
    while (w != 0 || h != 0) {
        cnt = 0;
        for (size_t i = 1; i <= h; i++) {
            for (size_t j = 1; j <= w; j++) {
                cin >> g[i][j];
                visit[i][j] = false;
            }
        }

        for (size_t i = 1; i <= h; i++) {
            for (size_t j = 1; j <= w; j++) {
                if (!visit[i][j] && g[i][j]) {
                    DFS(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
        cin >> w >> h;
    }
}