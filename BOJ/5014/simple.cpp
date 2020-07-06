#include <iostream>
using namespace std;

int main() {
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    for (size_t r = 0; r < F && S <= F && S > 0; r++) {
        if (S == G) {
            cout << r << '\n';
            return 0;
        }

        if (S < G && S + U <= F)
            S += U;
        else
            S -= D;
    }

    cout << "use the stairs" << '\n';
    return 0;
}