#include <iostream>
#define MAX 6561
using namespace std;

char arr[MAX][MAX];

void punch(int x, int y, int n) {
    if (n == 1)
        return;

    for (size_t i = x + n / 3; i < x + 2 * (n / 3); i++) {
        for (size_t j = y + n / 3; j < y + 2 * (n / 3); j++)
            arr[i][j] = ' ';
    }

    for (size_t i = 0; i < n; i += n / 3) {
        for (size_t j = 0; j < n; j += n / 3)
            punch(x + i, y + j, n / 3);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++)
            arr[i][j] = '*';
    }
    punch(0, 0, N);
    
    for (size_t i = 0; i < N; i++)
        cout << arr[i] << '\n';
    
    return 0;
}