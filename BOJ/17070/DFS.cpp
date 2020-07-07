#include <iostream>
#include <queue>

using namespace std;

bool house[20][20];
int N;

bool hor_check(pair<int, int> p) {
    return p.second + 1 < N && !house[p.first][p.second + 1];
}

bool ver_check(pair<int, int> p) {
    return p.first + 1 < N && !house[p.first + 1][p.second];
}

bool dia_check(pair<int, int> p) {
    return hor_check(p) && ver_check(p) && !house[p.first + 1][p.second + 1];
}

int dfs(pair<int, int> p, int mode) {
    if (p.first == N - 1 && p.second == N - 1)
        return 1;

    int ret = 0;

    if (hor_check(p) && (mode == 0 || mode == 2))
        ret += dfs(make_pair(p.first, p.second + 1), 0);

    if (ver_check(p) && (mode == 1 || mode == 2))
        ret += dfs(make_pair(p.first + 1, p.second), 1);

    if (dia_check(p))
        ret += dfs(make_pair(p.first + 1, p.second + 1), 2);

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++)
            cin >> house[i][j];
    }

    cout << dfs(make_pair(0, 1), 0) << '\n';
    return 0;
}