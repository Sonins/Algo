#include <iostream>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    int N, M;

    cin >> N >> M;

    stack<vector<int>> s;
    s.push({});
    vector<int> seq;
    bool visit[10] = {0, };

    while (!s.empty()) {
        seq = s.top();
        s.pop();

        if (seq.size() == M) {
            for (auto i : seq)
                cout << i << " ";
            cout << "\n";
        }

        memset(visit, 0, 10 * sizeof(bool));
        for (auto i : seq) {
            visit[i] = true;
        }

        for (int j = N; j > 0; j--) {
            if (!visit[j]) {
                s.push(seq);
                s.top().push_back(j);
            }
        }

        if (seq.size() >= 1) {
            visit[seq.back()] = false;
        }
        
    }
    return 0;

}