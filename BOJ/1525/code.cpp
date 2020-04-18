#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

const int power_10[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

bool arr_same(vector<int> src, const int dest[9]) {
    for (size_t i = 0; i < 9; i++) {
        if (src[i] != dest[i])
            return false;
    }
    return true;
}

int to_idx(vector<int> arr) {
    int idx = 0;
    for (size_t i = 0; i < 9; i++)
        idx += arr[i] * power_10[i];
    return idx;
}


int main() {
    ios::sync_with_stdio(false);
    vector<int> arr(9);
    map<int, bool> visit;

    for (size_t i = 0; i < 9; i++)
        cin >> arr[i];

    const int dest[9] = {1, 2, 3, 4, 5, 6, 7, 8, 0};

    if (arr_same(arr, dest)) {
        cout << 0 << '\n';
        return 0;
    }

    queue<vector<int> > q;
    vector<int> cur;
    vector<int> temp;
    int zero_idx, qsize, cnt = 0;
    q.push(arr);
    visit[to_idx(arr)] = true;
    while (!q.empty()) {
        qsize = q.size();
        while (qsize--) {
            cur = q.front();
            q.pop();
            for (size_t i = 0; i < 9; i++) {
                if (!cur[i])
                    zero_idx = i;
            }

            if (zero_idx % 3 <= 1) {
                temp = cur;
                swap(temp[zero_idx], temp[zero_idx + 1]);
                if (arr_same(temp, dest)) {
                    cout << cnt + 1 << '\n';
                    return 0;
                }
                if (!visit[to_idx(temp)]) {
                    q.push(temp);
                    visit[to_idx(temp)] = true;
                }
            }

            if (zero_idx % 3 >= 1) {
                temp = cur;
                swap(temp[zero_idx - 1], temp[zero_idx]);
                if (arr_same(temp, dest)) {
                    cout << cnt + 1 << '\n';
                    return 0;
                }
                if (!visit[to_idx(temp)]) {
                    q.push(temp);
                    visit[to_idx(temp)] = true;
                }
            }

            if (zero_idx / 3 <= 1) {
                temp = cur;
                swap(temp[zero_idx], temp[zero_idx + 3]);
                if (arr_same(temp, dest)) {
                    cout << cnt + 1 << '\n';
                    return 0;
                }
                if (!visit[to_idx(temp)]) {
                    q.push(temp);
                    visit[to_idx(temp)] = true;
                }
            }

            if (zero_idx / 3 >= 1) {
                temp = cur;
                swap(temp[zero_idx - 3], temp[zero_idx]);
                if (arr_same(temp, dest)) {
                    cout << cnt + 1 << '\n';
                    return 0;
                }
                if (!visit[to_idx(temp)]) {
                    q.push(temp);
                    visit[to_idx(temp)] = true;
                }
            }
        }
        cnt++;
    }
    cout << -1 << '\n';
    return 0;
}
