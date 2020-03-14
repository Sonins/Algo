#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    set<int> s;
    int num;

    for (size_t i = 0; i < N; i++) {
        cin >> num;
        s.insert(num);
    }

    cin >> M;

    for (size_t i = 0; i < M; i++) {
        cin >> num;
        if (s.find(num) != s.end())
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
    cout << '\n';
    return 0;
}