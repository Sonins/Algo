#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    stack<int> s;
    string vps;
    for (size_t i = 0; i < N; i++)
    {
        cin >> vps;
        if (vps.size() % 2) {
            cout << "NO" << '\n';
            continue;
        }

        for (size_t j = 0; j < vps.size(); j++)
        {
            if (vps[j] == '(') {
                s.push(1);
            } else {
                if (s.empty()) {
                    cout << "NO" << '\n';
                    s.push(0);
                    break;
                }
                s.pop();
            }
        }

        if (s.empty())
            cout << "YES" << '\n';
        else if (s.top() == 1)
            cout << "NO" << '\n';

        while (!s.empty())
            s.pop();

    }
    return 0;
}