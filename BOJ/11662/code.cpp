#include <cmath>
#include <iostream>
using namespace std;

typedef long double ld;

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

ld dist_per_time(ld t, ld coor[4][2]) {
    ld x1, x2, y1, y2;
    
    x1 = coor[0][0] + t * (coor[1][0] - coor[0][0]);
    x2 = coor[2][0] + t * (coor[3][0] - coor[2][0]);
    y1 = coor[0][1] + t * (coor[1][1] - coor[0][1]);
    y2 = coor[2][1] + t * (coor[3][1] - coor[2][1]);

    return dist(x1, y1, x2, y2);
}

int main() {
    ld coor[4][2];
    cout.precision(12);
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 2; j++)
            cin >> coor[i][j];
    }

    ld L = 0, R = 1;
    while (L < R) {
        if (dist_per_time(L, coor) < dist_per_time(R, coor))
            R = (L + R) / 2;
        else
            L = (L + R) / 2;
        if (R - L < 0.00000000001)
            break;
    }

    if (dist_per_time(L, coor) < dist_per_time(R, coor))
        cout << dist_per_time(L, coor) << '\n';
    else
        cout << dist_per_time(R, coor) << '\n';
    
    return 0;
}