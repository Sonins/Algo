#include <iostream>
#define MAX 70
using namespace std;
int arr[MAX][MAX];

void comp(int x, int y, int n) {
    if (n == 1) {
        cout << arr[x][y];
        return;
    }

    bool allsame = true;
    bool before = arr[x][y];
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (before != arr[x + i][y + j])
                allsame = false;
        }
    }
    if (allsame)
        cout << arr[x][y];
    else {
        cout << "(";
        for (size_t i = 0; i < n; i += n / 2) {
            for (size_t j = 0; j < n; j += n / 2)
                comp(x + i, y + j, n / 2);
        }
        cout << ")";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    char s[MAX];
    for (size_t i = 0; i < N; i++) {
        cin >> s;
        for (size_t j = 0; j < N; j++)
            arr[i][j] = s[j] - '0';
    }

    comp(0, 0, N);
    cout << '\n';
    return 0;
}