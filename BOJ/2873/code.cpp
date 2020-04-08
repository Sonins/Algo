#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int R, C;
    cin >> R >> C;
    int arr[1010][1010];

    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++)
            cin >> arr[i][j];
    }

    int min = __INT32_MAX__;
    int idx[2];

    for (size_t i = 0; i < R; i++) {
        for (size_t j = 0; j < C; j++) {
            if ((i % 2) ^ (j % 2) && arr[i][j] < min) {
                min = arr[i][j];
                idx[0] = i;
                idx[1] = j;
            }
        }
    }

    int leftrow = 0;
    int leftcol = 0;
    if (!(R % 2) && !(C % 2)) {
        while (leftrow <= idx[0] - 2) {
            for (size_t i = 1; i < C; i++)
                cout << 'R';
            cout << 'D';
            for (size_t i = 1; i < C; i++)
                cout << 'L';
            cout << 'D';
            leftrow += 2;
        }

        while (leftcol < C - 1) {
            if (leftcol < idx[1]) {
                if (leftcol % 2)
                    cout << "UR";
                else if (!(leftcol % 2))
                    cout << "DR";
            } else if (leftcol > idx[1]) {
                if (leftcol % 2)
                    cout << "DR";
                else if (!(leftcol % 2))
                    cout << "UR";
            } else {
                cout << 'R';
            }
            leftcol++;
        }
        leftrow += 2;
        
        if (leftrow < R)
            cout << "DD";
        else if (idx[1] == C - 2)
            cout << 'D';

        while (leftrow < R) {
            for (size_t i = 1; i < C; i++)
                cout << 'L';
            cout << 'D';
            for (size_t i = 1; i < C; i++)
                cout << 'R';
            if (leftrow < R - 2)
                cout << 'D';
            leftrow += 2;
        }
        cout << '\n';
    } else {
        if (R % 2) {
            for (size_t r = 0; r < R - 2; r += 2) {
                for (size_t i = 1; i < C; i++)
                    cout << 'R';
                cout << 'D';
                for (size_t i = 1; i < C; i++)
                    cout << 'L';
                cout << 'D';
            }
            for (size_t i = 1; i < C; i++)
                cout << 'R';
            cout << '\n';
        } else {
            for (size_t c = 0; c < C - 2; c += 2) {
                for (size_t i = 1; i < R; i++)
                    cout << 'D';
                cout << 'R';
                for (size_t i = 1; i < R; i++)
                    cout << 'U';
                cout << 'R';
            }
            for (size_t i = 1; i < R; i++)
                cout << 'D';
            cout << '\n';
        }
    }

    return 0;
}