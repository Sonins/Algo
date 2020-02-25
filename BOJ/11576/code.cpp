#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int A, B;
    cin >> A >> B;
    int m;
    cin >> m;
    int num;
    vector<int> v;
    for (size_t i = 0; i < m; i++) {
        cin >> num;
        v.push_back(num);
    }

    int digit = 1;
    int number = 0;

    for (vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); i++) {
        number += digit * (*i);
        digit *= A;
    }

    v.clear();

    if (number == 0) {
        cout << 0 << '\n';
        return 0;
    }

    while (number != 0) {
        v.push_back(number % B);
        number /= B;
    }

    for (vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); i++)
        cout << *i << ' ';
    
    cout << '\n';
    return 0;
}