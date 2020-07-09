#include <iostream>

using namespace std;

char table[21][21];
bool visit[255];
int R, C;

int dfs(int x, int y) {
    int offx[4] = {0, 1, 0, -1};
    int offy[4] = {1, 0, -1, 0};
    int cnt = 0;

    visit[table[x][y]] = true;

    if (x - 1 >= 0 && !visit[table[x - 1][y]]) cnt = max(dfs(x - 1, y), cnt);
    if (x + 1 < R && !visit[table[x + 1][y]]) cnt = max(dfs(x + 1, y), cnt);
    if (y - 1 >= 0 && !visit[table[x][y - 1]]) cnt = max(dfs(x, y - 1), cnt);
    if (y + 1 < C && !visit[table[x][y + 1]]) cnt = max(dfs(x, y + 1), cnt);

    visit[table[x][y]] = false;
    return cnt + 1;
}

int main() {
    scanf("%d", &R);
    scanf("%d", &C);
    for (size_t i = 0; i < R; i++)
        scanf("%s", &table[i]);

    printf("%d\n", dfs(0, 0));
    return 0;
}