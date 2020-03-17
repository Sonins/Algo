#include <iostream>
#define MAX 6561
using namespace std;

char arr[MAX][MAX];

void punch(int x, int y, int n, char c) {
    if (n == 1) {
        arr[x][y] = c;
        return;
    }

    char ch;

    for (size_t i = 0; i < n; i += n / 3) {
        for (size_t j = 0; j < n; j += n / 3) {
            if (i != n / 3 || j != n / 3)
                ch = c;
            else
                ch = ' ';
            punch(x + i, y + j, n / 3, ch);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int N;
    cin >> N;

    punch(0, 0, N, '*');

    for (size_t i = 0; i < N; i++)
        cout << arr[i] << '\n';

    return 0;
}