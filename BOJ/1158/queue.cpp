#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= N; i++)
        q.push(i);
    
    int cnt = 0;
    while (!q.empty()) {
        cnt++;
        if (cnt == K) {
            ans.push_back(q.front());
            cnt = 0;
        }
        else
            q.push(q.front());
        q.pop();
    }
    cout << "<";
    for (auto i : ans) {
        if (i != ans[ans.size() - 1])
            cout << i << ", ";
        else
            cout << i;
    }
    cout << ">\n";
    return 0;
}