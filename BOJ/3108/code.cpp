#include <iostream>
#include <vector>
#define MAX 1010

using namespace std;

bool meet[MAX][MAX];
bool visit[MAX];

typedef struct {
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
} rec;

bool isMeet(rec r1, rec r2) {
    if (r1.y2 < r2.y1 || r2.y2 < r1.y1)
        return false;

    if (r1.x2 < r2.x1 || r2.x2 < r1.x1)
        return false;
    
    if (r1.x1 < r2.x1 && r1.x2 > r2.x2 && r1.y1 < r2.y1 && r1.y2 > r2.y2)
        return false;

    if (r2.x1 < r1.x1 && r2.x2 > r1.x2 && r2.y1 < r1.y1 && r2.y2 > r1.y2)
        return false;

    return true;
}

void DFS(int start, int N) {
    visit[start] = true;
    for (int i = 0; i <= N; i++) {
        if (meet[start][i] && !visit[i])
            DFS(i, N);
    }
}

int main() {
    ios::sync_with_stdio(false);
    vector<rec> v;
    rec r;
    int N, x1, y1, x2, y2;
    v.push_back(r);
    cin >> N;
    for (size_t i = 0; i < N; i++) {
        cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
        v.push_back(r);
    }

    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = i + 1; j < v.size(); j++) {
            if (isMeet(v[i], v[j])) {
                meet[i][j] = 1;
                meet[j][i] = 1;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i <= N; i++) {
        if (!visit[i]) {
            DFS(i, N);
            ans++;
        }
    }

    cout << ans - 1 << '\n';
    return 0;
}