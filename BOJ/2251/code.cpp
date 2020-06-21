#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool visit[201][201][201];
vector<int> size(3);

vector<int> pour(vector<int> w, int a, int b) {
    a--; b--;
    if (w[a] == 0)
        return w;

    if (w[a] + w[b] < size[b]) {
        w[b] += w[a];
        w[a] = 0;
    } 
    else {
        w[a] -= size[b] - w[b];
        w[b] = size[b];
    }
    return w;
}

int main() {
    ios::sync_with_stdio(false);
    vector<int> water(3, 0);
    for (auto &&i : size)
        cin >> i;

    water[2] = size[2];

    vector<int> cur(3);
    queue<vector<int> > q;
    visit[water[0]][water[1]][water[2]] = true;
    q.push(water);
    
    vector<int> perm{1, 2, 3};
    vector<int> ans;
    while (!q.empty()) {
        water = q.front();
        q.pop();

        if (water[0] == 0)
            ans.push_back(water[2]);
        
        while (next_permutation(perm.begin(), perm.end())) {
            cur = pour(water, perm[0], perm[1]);
            if (!visit[cur[0]][cur[1]][cur[2]]) {
                visit[cur[0]][cur[1]][cur[2]] = true;
                q.push(cur);
            }
        }
    }
    sort(ans.begin(), ans.end());
    
    for (auto &&i : ans)
        cout << i << ' ';
    cout << '\n';
    return 0;
}