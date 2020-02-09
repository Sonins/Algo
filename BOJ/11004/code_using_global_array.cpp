#include <iostream>
#include <algorithm>
#define MAX 5000010
using namespace std;
int arr[MAX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;

    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i + 1];
    }
    
    sort(arr + 1, arr + N + 1);
    
    cout << arr[K] << '\n';
    return 0;
}