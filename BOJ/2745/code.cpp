#include <iostream>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    string N;
    int B;
    cin >> N >> B;
    int arr[500];
    for (char i = 'A'; i <= 'Z'; i++) {
        arr[i] = i - 'A' + 10;
    }
    for (char i = '0'; i <= '9'; i++) {
        arr[i] = i - '0';
    }
    int result = 0;

    for (size_t i = 0; i < N.size(); i++) {
        result *= B;
        result += arr[N[i]];
    }
    cout << result << '\n';
    return 0;
}