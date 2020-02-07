#include <iostream>
#include <algorithm>
#define MAX 100010

using namespace std;

bool compare (pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pair<int, int> dot[MAX];
    int N;
    cin >> N;
    int x, y;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        cin >> y;
        dot[i + 1] = make_pair(x, y);
    }
    sort(dot + 1, dot + N + 1, compare);
    
    for (size_t i = 0; i < N; i++)
    {
        cout << dot[i + 1].first << " " << dot[i + 1].second << '\n';
    }
    
    
    return 0;
}
