#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int result = 0;
    getline(cin, s);
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
        result += s[i] - '0';
    cout << result << endl;
    return 0;
}