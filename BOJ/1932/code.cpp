#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<vector<int>> tri;
    for (int i = 0; i < N; i++) {
        vector<int> row(i + 1);
        for (int j = 0; j <= i; j++) {
            scanf("%d", &row[j]);
        }
        tri.push_back(row);
    }

    for (int i = 1; i < N; i++) {
        tri[i][0] = tri[i - 1][0] + tri[i][0];
        tri[i][i] = tri[i - 1][i - 1] + tri[i][i];
        for (int j = 1; j < i; j++) {
            tri[i][j] = max<int>(tri[i - 1][j - 1], tri[i - 1][j]) + tri[i][j];
        }
    }

    int ans = 0;

    for (auto i : tri[N - 1]) {
        
        if (ans < i) ans = i;
    }
    printf("%d\n", ans);
    return 0;
}