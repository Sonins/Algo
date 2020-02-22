#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> v;
    for (size_t i = 1; i <= N; i++)
        v.push_back(i);
    
    int cur = K - 1;

    cout << "<";
    while (N-- > 0) {
        cout << v[cur];
        if (N == 0) {
            cout << ">\n";
            return 0;
        }
        cout << ", ";
        v.erase(v.begin() + cur);
        cur = (cur + K - 1) % N;
    }
    return 0;
}