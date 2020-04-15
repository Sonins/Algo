#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#define MAX 10000
using namespace std;

int power_10[4] = {1, 10, 100, 1000};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int A, B, T;
    cin >> T;

    for (size_t t = 0; t < T; t++) {
        cin >> A >> B;
        queue<int> q;
        int before[MAX];
        char word[MAX];
        int cur;
        string result;
        memset(before, 0, sizeof(before));
        memset(word, 0, sizeof(word));
        q.push(A);
        while (!q.empty()) {
            cur = q.front();
            q.pop();

            int DSLR[4];
            char dslr[4] = {'D', 'S', 'L', 'R'};
            DSLR[0] = (cur * 2) % MAX;
            DSLR[1] = cur ? cur - 1 : 9999;
            DSLR[2] = cur / 1000 + (cur % 1000) * 10;
            DSLR[3] = (cur % 10) * 1000 + cur / 10;

            for (size_t i = 0; i < 4; i++) {
                if (DSLR[i] == B) {
                    result.push_back(dslr[i]);
                    while (cur != A) {
                        result.push_back(word[cur]);
                        cur = before[cur];
                    }
                    reverse(result.begin(), result.end());
                    cout << result << '\n';
                    break;
                }
            }

            if (!result.empty())
                break;

            if (!word[DSLR[0]]) {
                q.push(DSLR[0]);
                before[DSLR[0]] = cur;
                word[DSLR[0]] = 'D';
            }

            if (!word[DSLR[1]]) {
                q.push(DSLR[1]);
                before[DSLR[1]] = cur;
                word[DSLR[1]] = 'S';
            }

            if (!word[DSLR[2]]) {
                q.push(DSLR[2]);
                before[DSLR[2]] = cur;
                word[DSLR[2]] = 'L';
            }

            if (!word[DSLR[3]]) {
                q.push(DSLR[3]);
                before[DSLR[3]] = cur;
                word[DSLR[3]] = 'R';
            }
        }
    }
    return 0;
}