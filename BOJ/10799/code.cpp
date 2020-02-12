#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    stack<bool> s;
    string str;
    int answer = 0;
    cin >> str;
    
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == '(') {
            s.push(true);
        } else if (str[i - 1] == '(') {
            s.pop();
            answer += s.size();
        } else {
            s.pop();
            answer++;
        }
    }
    
    cout << answer << '\n';
    return 0;
}