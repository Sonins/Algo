#include <cstring>
#include <iostream>
#define MAX 7000
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
}

int main() {
    int N;
    cin >> N;

    for (size_t i = 0; i < N; i++)
        memset(arr[i], ' ', (N + i) * sizeof(char));

    star(0, 0, N);

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 1; j < N - i; j++)
            cout << ' ';

        cout << arr[i] << '\n';
    }
    return 0;
}