#include <stdio.h>
#define MAX 51
using namespace std;

bool g[MAX][MAX];
const int x[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int y[] = {0, -1, -1, -1, 0, 1, 1, 1};

void DFS_visit(int i, int j);

void DFS(int i, int j) {
    g[i][j] = false;
    for (size_t t = 0; t < 8; t++)
        DFS_visit(i + x[t], j + y[t]);
    
}

void DFS_visit(int i, int j) {
    if (i > 0 && i < MAX && j > 0 && j < MAX && g[i][j])
        DFS(i, j);
}

int main() {
    int w, h;
    scanf("%d %d", &w, &h);
    int cnt;
    while (w != 0 || h != 0) {
        cnt = 0;
        for (size_t i = 1; i <= h; i++) {
            for (size_t j = 1; j <= w; j++)
                scanf("%1d", &g[i][j]);
        }

        for (size_t i = 1; i <= h; i++) {
            for (size_t j = 1; j <= w; j++) {
                if (g[i][j]) {
                    DFS(i, j);
                    cnt++;
                }
            }
        }

        printf("%d\n", cnt);
        scanf("%d %d", &w, &h);
    }
}