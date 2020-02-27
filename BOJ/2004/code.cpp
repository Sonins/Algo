#include <iostream>
using namespace std;
int two;
int five;

void count(int k, int diff) {
    int ii;
    ii = k;
    while (ii >= 2) {
        ii /= 2;
        two += ii * diff;
    }
    ii = k;
    while (ii >= 5) {
        ii /= 5;
        five += ii * diff;
    }

}

int main() {
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    count(N, 1);
    count(M, -1);
    count(N - M, -1);
    cout << (two > five ? five : two) << '\n';
    return 0;
}