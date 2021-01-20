#include <iostream>
#include <unordered_map>

using namespace std;

int arr[4010][4];

int main() {
    int N;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }

    unordered_map<int, int> map;
    int sum;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum = arr[i][0] + arr[j][1];
            if (map.find(sum) != map.end()) {
                map.find(sum)->second++;
            } else {
                map.insert(make_pair(sum, 1));
            }
        }
    }

    long long int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum = arr[i][2] + arr[j][3];
            if (map.find(-1 * sum) != map.end()) {
                cnt += map.find(-1 * sum)->second;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}