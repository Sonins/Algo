#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    vector<int> v;
    int digit = 0;
    if (s.size() % 3 == 2) {
        digit += s[0] == '1' ? 2 : 0;
        digit += s[1] == '1' ? 1 : 0;
        v.push_back(digit);
        s = s.substr(2);
    } else if (s.size() % 3 == 1) {
        digit += s[0] == '1' ? 1 : 0;
        v.push_back(digit);
        s = s.substr(1);
    }

    for (size_t i = 0; i < s.size(); i += 3) {
        digit = 0;
        digit += s[i] == '1' ? 4 : 0;
        digit += s[i + 1] == '1' ? 2 : 0;
        digit += s[i + 2] == '1' ? 1 : 0;
        v.push_back(digit);
    }
    
    for (auto i : v)
        cout << i;
    cout << '\n';
    return 0;
}