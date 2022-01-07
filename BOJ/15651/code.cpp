#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> v = {};
    stack<vector<int>> s;

    s.push(v);

    while (!s.empty()) {
        v = s.top();
        s.pop();

        if (v.size() == M)  {
            for (int i = 0; i < M; i++) {
                cout << v[i] << ' ';
            }
            cout << '\n';
            continue;
        }

        for (int i = N; i > 0; i--) {
            s.push(v);
            s.top().push_back(i);
        }
    }

    return 0;
}