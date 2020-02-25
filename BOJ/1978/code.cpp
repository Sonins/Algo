#include <iostream>
using namespace std;
bool arr[1010];
int main() {
    arr[1] = true;
    for (int i = 2; i <= 1000; i++) {
        if (arr[i])
            continue;
        
        for (int j = 2; j * j <= i; j++) {
            if (!(i % j)) {
                arr[i] = true;
                break;
            }
        }

        if (!arr[i]) {
            for (int j = 2 * i; j <= 1000; j += i)
                arr[j] = true;
        }
    }

    int result = 0;
    int N;
    cin >> N;
    int num;
    for (size_t i = 0; i < N; i++) {
        cin >> num;
        result += (arr[num] ^ 1);
    }
    cout << result << '\n';
    return 0;
}
