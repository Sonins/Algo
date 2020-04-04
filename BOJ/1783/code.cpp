#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    if (h >= 3 && w >= 7)
        cout << w - 2 << '\n';
    else if (h == 1)
        cout << 1 << '\n';
    else if (h == 2)
        cout << min(4, (w + 1) / 2) << '\n';
    else if (w <= 6)
        cout << min(4, w) << '\n';
    return 0;
}