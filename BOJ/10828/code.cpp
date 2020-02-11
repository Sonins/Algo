#include <iostream>
#include <string>
#define MAX 10000
using namespace std;

class stack {
    private:
    int arr[MAX];
    int _top = -1;

    public:

    void push(int n) {
        arr[++_top] = n;
    }

    void pop() {
        if (_top >= 0)
            cout << arr[_top--] << '\n';
        else
            cout << -1 << '\n';
    }

    void size() {
        cout << _top + 1 << '\n';
    }

    void empty() {
        if (_top == -1)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    void top() {
        if (_top == -1)
            cout << -1 << '\n';
        else
            cout << arr[_top] << '\n';
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    stack s;
    string com;
    int num;
    for (size_t i = 0; i < N; i++)
    {
        cin >> com;
        if (com == "push") {
            cin >> num;
            s.push(num);
        } else if (com == "pop") {
            s.pop();
        } else if (com == "size") {
            s.size();
        } else if (com == "empty") {
            s.empty();
        } else if (com == "top") {
            s.top();
        }
    }
    return 0;
}