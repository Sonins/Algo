#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool visit[15];
char str[15];
int L, C;

void print() {
    int mo = 0;
    int ja = 0;
    for (size_t i = 0; i < C; i++) {
        if (visit[i]) {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
                mo++;
            else
                ja++;
        }
    }

    if (mo >= 1 && ja >= 2) {
        for (size_t i = 0; i < C; i++) {
            if (visit[i])
                cout << str[i];
        }
        cout << '\n';
    }

}

void dfs(int h, int idx) {
    if (h == L) {
        print();
        return;
    }

    for (size_t i = idx; i < C; i++) {
        if (!visit[i]) {
            visit[i] = true;
            dfs(h + 1, i);
            visit[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> L >> C;

    for (size_t i = 0; i < C; i++)
        cin >> str[i];

    sort(str, str + C);
    dfs(0, 0);

    return 0;
}