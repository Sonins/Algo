#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector<string> v;
    for (size_t i = 0; i < s.size(); i++)
        v.push_back(s.substr(i, s.size()));
    sort(v.begin(), v.end());
    for (auto i : v)
        cout << i << '\n';
    return 0;
}