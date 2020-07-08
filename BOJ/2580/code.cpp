#include <string.h>

#include <iostream>
#include <vector>

using namespace std;

int sdoku[9][9];

bool DFS(int x, int y) {
    bool ret = false;
    bool cand[10];
    memset(cand, 1, sizeof(cand));

    for (int i = 0; i < 9; i++) {
        if (sdoku[x][i])
            cand[sdoku[x][i]] = false;
        if (sdoku[i][y])
            cand[sdoku[i][y]] = false;
        if (sdoku[i / 3 + (x / 3) * 3][(i % 3) + (y / 3) * 3])
            cand[sdoku[i / 3 + (x / 3) * 3][(i % 3) + (y / 3) * 3]] = false;
    }

    for (int i = 0; i < 9; i++) {
        if (!cand[i + 1])
            continue;

        ret = true;
        sdoku[x][y] = i + 1;

        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                if (!sdoku[j][k]) {
                    if (!DFS(j, k)) {
                        ret = false;
                        break;
                    }
                }
            }
            if (!ret)
                break;
        }

        if (ret)
            break;
        else
            sdoku[x][y] = 0;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cin >> sdoku[i][j];
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (!sdoku[i][j])
                DFS(i, j);
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << sdoku[i][j] << " ";
        cout << '\n';
    }

    return 0;
}
