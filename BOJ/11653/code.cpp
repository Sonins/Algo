#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int N;
    cin >> N;
    
    for (size_t i = 2; i * i < 10000000; i++)
    {
        while (N % i == 0) {
            cout << i << '\n';
            N /= i;
        }
    }
    
    if (N > 1)
        cout << N << '\n';

    return 0;
}