#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int two = 0, five = 0;
    int N;
    int ii;
    cin >> N;
    for (size_t i = 1; i <= N; i++)
    {
        ii = i;
        while (ii % 2 == 0) {
            two++;
            ii /= 2;
        }
        ii = i;
        while (ii % 5 == 0) {
            five++;
            ii /= 5;
        }
    }

    cout << (two > five ? five : two) << '\n';
    return 0;
}