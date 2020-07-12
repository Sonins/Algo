#include <iostream>
#define MAX 10000010
#define ulld unsigned long long

using namespace std;

ulld arr[MAX];

int main() {
    int T, N;
    ulld S;
    cin >> T;
    int low, high;
    ulld sum;
    for (size_t t = 0; t < T; t++) {
        cin >> N >> S;
        arr[0] = 0;
        for (size_t i = 1; i <= N; i++) {
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }
        
        low = 0;
        high = 1;
        while ((sum = arr[high] - arr[low]) != S && !(high == N && low == N)) {
            if (sum < S) {
                if (high != N)
                    high++;
                else
                    break;
            } else if (sum > S) {
                if (low < high)
                    low++;
                else if (high != N)
                    high++;
                else
                    break;
            }
        }
        if (sum == S)
            cout << low + 1 << " " << high << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}