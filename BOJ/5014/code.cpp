#include <iostream>
#include <queue>
#define MAX 1000010
using namespace std;

bool dp[MAX];

int main() {
    ios::sync_with_stdio(false);
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    if (S == G) {
        cout << 0 << '\n';
        return 0;
    }

    queue<int> q;
    q.push(S);

    int cur;
    int qsz;
    int move = 0;
    while (!q.empty()) {
        qsz = q.size();
        for (size_t i = 0; i < qsz; i++) {
            cur = q.front();
            q.pop();

            if (U && cur + U <= F && !dp[cur + U]) {
                dp[cur + U] = dp[cur] + 1;
                q.push(cur + U);
            }

            if (D && cur - D > 0 && !dp[cur - D]) {
                dp[cur - D] = dp[cur] + 1;
                q.push(cur - D);
            }

            if (cur + U == G || cur - D == G) {
                cout << move + 1 << endl;
                return 0;
            }
        }
        move++;
    }

    cout << "use the stairs" << '\n';

    return 0;
}