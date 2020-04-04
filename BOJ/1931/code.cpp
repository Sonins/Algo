#include <algorithm>
#include <iostream>
#include <typeinfo>
#include <vector>
#define MAX 100010
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int> > x(N);

    for (size_t i = 0; i < N; i++)
        cin >> x[i].first >> x[i].second;

    sort(x.begin(), x.end(), compare);
    int ans = 0;
    int K = 0;
    for (size_t i = 0; i < N; i++) {
        if (x[i].first >= K) {
            ans++;
            K = x[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}