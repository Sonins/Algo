#include <iostream>
#include <vector>
#include <stack>
#define MAX 300000
using namespace std;

int g[MAX];
bool visit[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, P;
    cin >> A >> P;
    int cur = A;
    int tmp;
    int num;
    while (!g[cur]) {
        tmp = cur;
        while (tmp) {
            num = 1;
            for (size_t i = 0; i < P; i++)
                num *= tmp % 10;
            g[cur] += num;
            tmp /= 10;
        }
        cur = g[cur];
    }

    cur = A;
    while (!visit[cur]) {
        visit[cur] = true;
        cur = g[cur];
    }
    
    g[cur] = cur;

    for (size_t i = 0; i < MAX; i++)
        visit[i] = false;

    int count = 0;

    cur = A;
    while (g[cur] != cur) {
        cur = g[cur];
        count++;
    }
    cout << count << '\n';
    return 0;
}