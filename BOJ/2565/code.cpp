#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

int main() {
    vector<int> l(2);
    vector<vector<int>> lines;
    vector<int> lis;
    int N;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &l[0], &l[1]);
        lines.push_back(l);
    }
    
    sort(lines.begin(), lines.end(), compare);

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(lis.begin(), lis.end(), lines[i][1]);
        if (it == lis.end()) {
            lis.push_back(lines[i][1]);
        } else {
            *it = lines[i][1];
        }
    }

    printf("%d\n", N - lis.size());
    return 0;
}