#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (size_t i = 0; i < N; i++)
        arr[i] = i + 1;
    
    vector<int>::iterator ii = arr.begin();
    cout << '<';
    while (!arr.empty()) {
        for (size_t i = 0; i < K - 1; i++) {
            if (ii == arr.end())
                ii = arr.begin();
            ii++;
        }
        if (ii == arr.end())
            ii = arr.begin();
        cout << *ii;
        if (arr.size() > 1)
            cout << ", ";
        ii = arr.erase(ii);
    }
    cout << '>' << '\n';
    return 0;
}