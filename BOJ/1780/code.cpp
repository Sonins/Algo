#include <iostream>
#include <vector>
#define MAX 2200
using namespace std;

int arr[MAX][MAX];
int result[3];  // 0 : -1 / 1 : 0 / 2 : 1

void count(int x, int y, int n) {
    if (n == 1) {
        result[arr[x][y] + 1]++;
        return;
    }

    int before = arr[x][y];
    bool allsame = true;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (before != arr[x + i][y + j]) {
                allsame = false;
            }
        }
    }

    if (allsame) {
        result[arr[x][y] + 1]++;
    } else {
        for (size_t i = 0; i < n; i += n / 3) {
            for (size_t j = 0; j < n; j += n / 3)
                count(x + i, y + j, n / 3);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N;
    cin >> N;

    int num;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++)
            cin >> arr[i][j];
    }
    count(0, 0, N);

    for (size_t i = 0; i < 3; i++)
        cout << result[i] << '\n';
        
    return 0;
}