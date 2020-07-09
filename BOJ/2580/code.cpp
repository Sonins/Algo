#include <string.h>

#include <cstdio>
#include <vector>

using namespace std;

bool row[9][10], col[9][10], sq[9][10];
int sdoku[9][9];
vector<pair<int, int> > blank;

int idx_to_sq(int x, int y) {
    return x / 3 * 3 + y / 3;
}

bool DFS(int pos) {
    if (pos == blank.size())
        return true;

    bool ret = false;

    int x = blank[pos].first;
    int y = blank[pos].second;

    for (int i = 1; i <= 9; i++) {
        if (!row[x][i] || !col[y][i] || !sq[idx_to_sq(x, y)][i])
            continue;

        ret = true;

        sdoku[x][y] = i;
        row[x][i] = false;
        col[y][i] = false;
        sq[idx_to_sq(x, y)][i] = false;

        ret = DFS(pos + 1);

        if (ret)
            break;
        else {
            sdoku[x][y] = 0;
            row[x][i] = true;
            col[y][i] = true;
            sq[idx_to_sq(x, y)][i] = true;
        }
    }
    return ret;
}

int main() {
    memset(row, 1, sizeof(row));
    memset(col, 1, sizeof(col));
    memset(sq, 1, sizeof(sq));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &sdoku[i][j]);
            if (!sdoku[i][j])
                blank.push_back(make_pair(i, j));
            else {
                row[i][sdoku[i][j]] = false;
                col[j][sdoku[i][j]] = false;
                sq[idx_to_sq(i, j)][sdoku[i][j]] = false;
            }
        }
    }

    DFS(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            printf("%d ", sdoku[i][j]);
        printf("\n");
    }

    return 0;
}
