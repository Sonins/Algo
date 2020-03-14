#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 500020
using namespace std;

int arr[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    for (size_t i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    int before;
    int cnt = 0;
    before = arr[0];
    vector<pair<int, int> > v;
    for (size_t i = 0; i < N; i++) {
        if (arr[i] != before) {
            v.push_back(make_pair(before, cnt));
            cnt = 0;
            before = arr[i];
        }
        cnt++;
    }
    v.push_back(make_pair(before, cnt));
    cin >> M;

    int num;
    int L, R;
    int mid;
    int count;
    for (size_t i = 0; i < M; i++) {
        cin >> num;
        L = 0;
        R = v.size();
        count = 0;
        while (L < R) {
            mid = (L + R) / 2;
            if (v[mid].first > num)
                R = mid;
            else if (v[mid].first < num)
                L = mid + 1;
            else {
                count = v[mid].second;
                break;
            }
        }
        cout << count << " ";
    }
    cout << '\n';
    return 0;
}