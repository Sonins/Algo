#include <string.h>

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    stack<vector<int>> s;
    int N, M;
    cin >> N >> M;
    vector<int> v = {};
    s.push(v);

    while (!s.empty()) {
        v = s.top();
        s.pop();

        if (v.size() == M) {
            for (int i = 0; i < M; i++) {
                cout << v[i] << ' ';
            }
            cout << "\n";
            continue;
        }

        int limit = 0;
        if (!v.empty())
            limit = v.back();
            
        for (int i = N; i > limit; i--) {
            s.push(v);
            s.top().push_back(i);
        }
    }

    return 0;
}