#include <iostream>
#include <vector>
#define MAX 1010
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[MAX];
    vector<int> table;

    for (size_t i = 1; i <= N; i++)
        cin >> arr[N - i + 1];

    int idx;

    for (size_t i = 1; i <= N; i++)
    {
        idx = lower_bound(table.begin(), table.end(), arr[i]) - table.begin();
        if (idx == table.size())
            table.push_back(arr[i]);
        else
            table[idx] = arr[i];
    }

    cout << table.size() << endl;
    return 0;
    
}