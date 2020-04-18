#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

const int power_10[9] = {100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};

int main() {
    ios::sync_with_stdio(false);
    int start = 0, num;
    unordered_map<int, bool> visit;

    for (size_t i = 0; i < 9; i++) {
        cin >> num;
        start += num * power_10[i];
    }

    const int dest = 123456780;

    if (start == dest) {
        cout << 0 << '\n';
        return 0;
    }

    queue<int> q;
    int cur, temp;
    int zero_idx, qsize, cnt = 0;
    int offset[4] = {-1, 1, 3, -3};
    int pos;
    q.push(start);
    visit[start] = true;
    while (!q.empty()) {
        qsize = q.size();
        while (qsize--) {
            cur = q.front();
            q.pop();
            for (size_t i = 0; i < 9; i++) {
                if (!((cur / power_10[i]) % 10))
                    zero_idx = i;
            }

            for (size_t i = 0; i < 4; i++) {
                pos = zero_idx + offset[i];
                if (pos < 9 && pos >= 0 && (pos % 3 == zero_idx % 3 || pos / 3 == zero_idx / 3)) {
                    temp = cur;
                    temp += ((temp / power_10[pos]) % 10) * power_10[zero_idx];
                    temp -= ((temp / power_10[pos]) % 10) * power_10[pos];

                    if (temp == dest) {
                        cout << cnt + 1 << '\n';
                        return 0;
                    }

                    if (!visit[temp]) {
                        q.push(temp);
                        visit[temp] = true;
                    }
                }
            }
        }
        cnt++;
    }
    cout << -1 << '\n';
    return 0;
}
