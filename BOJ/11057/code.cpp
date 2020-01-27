#include <iostream>
#define DIV 10007
using namespace std;
int count[1010][10];
int main() {
    int N, sum = 0;
    cin >> N;
    for (size_t i = 0; i < 10; i++)
        count[1][i] = 1;
    for (size_t i = 2; i <= N; i++) {
        for (size_t j = 0; j < 10; j++) {
            for (size_t k = 0; k <= j; k++) {
                count[i][j] += count[i - 1][k];   
                count[i][j] %= DIV;
            }
        }
    }
    for (size_t i = 0; i < 10; i++) {
        sum += count[N][i];
        sum %= DIV;
    }
    cout << sum << endl;
    return 0;
}