#include <iostream>
#define MAX 100010
using namespace std;
int arr[MAX];
int main() {
    ios::sync_with_stdio(false);
    int N, q;
    cin >> N;
    int plank;
    int over_8 = 0, over_6 = 0, over_4 = 0, over_2 = 0;
    for (size_t i = 0; i < N; i++) {
        cin >> plank;
        arr[plank]++;
    }
    for (size_t i = 0; i < N; i++) {
        if (arr[i] >= 8)
            over_8++;
        if (arr[i] >= 6)
            over_6++;
        if (arr[i] >= 4)
            over_4++;
        if (arr[i] >= 2)
            over_2++;
    }

    cin >> q;
    char pref;
    for (size_t i = 0; i < q; i++) {
        cin >> pref >> plank;
        if (pref == '+') {
            if (arr[plank] == 1)
                over_2++;
            if (arr[plank] == 3)
                over_4++;

            if (arr[plank] == 5)
                over_6++;

            if (arr[plank] == 7)
                over_8++;

            arr[plank]++;
        } else {
            if (arr[plank] == 2)
                over_2--;

            if (arr[plank] == 4)
                over_4--;

            if (arr[plank] == 6)
                over_6--;

            if (arr[plank] == 8)
                over_8--;

            arr[plank]--;
        }

        if ((over_4 >= 1 && over_2 >= 3) || (over_6 >= 1 && over_2 >= 2) || (over_4 >= 2) || (over_8 >= 1))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}
