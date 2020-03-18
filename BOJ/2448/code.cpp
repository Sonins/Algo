#include <iostream>
#define MAX 3072
using namespace std;
char arr[MAX][MAX];

void star(int x, int y, int N) {
    if (N == 3) {
        arr[x][y] = '*';
        arr[x + 1][y] = '*';
        arr[x + 1][y + 1] = ' ';
        arr[x + 1][y + 2] = '*';
        arr[x + 2][y] = '*';
        arr[x + 2][y + 1] = '*';
        arr[x + 2][y + 2] = '*';
        arr[x + 2][y + 3] = '*';
        arr[x + 2][y + 4] = '*';
        return;
    }

    star(x, y, N / 2);
    star(x + N / 2, y, N / 2);
    star(x + N / 2, y + N, N / 2);

    for (size_t i = N / 2; i < N; i++) {
        for (size_t j = 0; j < 2 * (N - i) - 1; j++)
            arr[x + i][y + 2 * i - N + 1 + j] = ' ';
    }
}

int main() {
    int N;
    cin >> N;
    star(0, 0, N);

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N - i; j++) {
            cout << " ";
        }

        cout << arr[i] << '\n';
    }
    return 0;
}