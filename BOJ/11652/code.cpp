#include <iostream>
#include <algorithm>
#define MAX 1000010
using namespace std;

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    ll arr[MAX];
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i + 1];
    }
    sort(arr + 1, arr + N + 1);
    int count = 0;
    ll before = 1;
    int maxcount = 0;
    ll maxnum;
    for (size_t i = 0; i < N; i++)
    {
        if (arr[i + 1] != before) {
            if (maxcount < count) {
                maxcount = count;
                maxnum = before;
            }
            count = 0;
            before = arr[i + 1];
        }
        count++;
    }
    if (maxcount < count) {
        maxcount = count;
        maxnum = before;
    }
    cout << maxnum << '\n';
    return 0;
}