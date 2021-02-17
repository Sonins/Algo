#include <iostream>

using namespace std;

int count[6];

void erase(int x, int y, int n, bool arr[10][10]) {
    for (int i = x - n + 1; i <= x; i++) {
        for (int j = y - n + 1; j <= y; j++) {
            arr[i][j] = false;
        }
    }
}

void _fill(int x, int y, int n, bool arr[10][10]) {
    for (int i = x - n + 1; i <= x; i++) {
        for (int j = y - n + 1; j <= y; j++) {
            arr[i][j] = true;
        }
    }
}

bool all_covered(bool paper[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (paper[i][j])
                return false;
        }
    }
    return true;
}

bool can_paste(bool paper[10][10], int x, int y, int n) {
    if (x - n + 1 < 0 || y - n + 1 < 0)
        return false;
    
    for (int i = x - n + 1; i <= x; i++) {
        for (int j = y - n + 1; j <= y; j++) {
            if (!paper[i][j])
                return false;
        }
    }
    return true;
}

int dfs(bool paper[10][10], int cnt) {
    if (all_covered(paper))
        return cnt;

    int x, y;
    for (int i = 9; i >= 0; i--) {
        for (int j = 9; j >= 0; j--) {
            if (paper[i][j]) {
                x = i;
                y = j;
                i = -1;
                j = -1;
            }
        }
    }

    int ans = __INT32_MAX__ / 2;

    for (int n = 5; n > 0; n--) {
        if (count[n] == 0)
            continue;
        if (!can_paste(paper, x, y, n))
            continue;
        
        erase(x, y, n, paper);
        count[n]--;
        ans = min(ans, dfs(paper, cnt + 1));
        count[n]++;
        _fill(x, y, n, paper);
    }

    return ans;
}

int main() {
    bool paper[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> paper[i][j];
        }
    }

    for (int i = 1; i <= 5; i++)
        count[i] = 5;

    int ans = dfs(paper, 0);

    if (ans != __INT32_MAX__ / 2)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}