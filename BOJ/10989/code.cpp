#include <iostream>
#define MAX 10010
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int arr[MAX];
    int N;
    cin >> N;
    int num;
    
    for (size_t i = 0; i < MAX; i++)
        arr[i] = 0;
    
    for (size_t i = 0; i < N; i++)
    {
        cin >> num;
        arr[num]++;
    }

    for (size_t i = 1; i < MAX; i++)
    {
        for (size_t j = 0; j < arr[i]; j++)
        {
            cout << i << '\n';
        }
    }
    return 0;
}