#include <iostream>
#include <vector>
#include <stack>
#include <vector>
#include <string.h>

#define MAX 100010
using namespace std;

int delay[MAX];
int before[MAX];
int dep[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int T, N, K, W;

    cin >> T;
    while(T--) {
        memset(before, 0, sizeof(int) * MAX);
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> delay[i];
        }

        int parent, child;

        vector<int> edge[MAX];
        for (int i = 0; i < K; i++) {
            cin >> parent >> child;
            edge[parent].push_back(child);
            dep[child]++;
        }
        cin >> W;

        stack<int> st;
        for (int i = 1; i <= N; i++) {
            if (dep[i] == 0) st.push(i);
        }

        while (!st.empty()) {
            int cur = st.top();
            st.pop();

            for (auto i : edge[cur]) {
                before[i] = max(before[i], before[cur] + delay[cur]);
                dep[i]--;
                if (dep[i] == 0) st.push(i);
            }
        }
        cout << before[W] + delay[W] << '\n';
    }

}