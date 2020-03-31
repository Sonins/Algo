#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    int N;
    
    for (size_t t = 0; t < T; t++) {
        cin >> N;
        if (N > 1)
            cout << 'O' << '\n';
        else
            cout << 'E' << '\n';
    }
    return 0;
}