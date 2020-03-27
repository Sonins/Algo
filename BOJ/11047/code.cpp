#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> v(N);

    for (vector<int>::iterator ii = v.begin(); ii != v.end(); ii++)
        cin >> *ii;

    int ans = 0;
    int div;

    for (int i = v.size() - 1; i >= 0; i--) {
        div = K / v[i];
        ans += div;
        K -= div * v[i];
    }

    cout << ans << '\n';
    return 0;
}