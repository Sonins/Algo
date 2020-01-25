#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (size_t i = N; i > 0; i--) {
        for (size_t j = 0; j < N - i; j++)
            cout << ' ';
        
        for (size_t j = i; j > 0; j--)
            cout << '*';
        cout << endl;
    }
    return 0;
}