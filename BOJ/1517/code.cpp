#include <iostream>
#include <vector>
#define MAX 500010
using namespace std;
int arr[MAX];
long long cnt;

void merge(int st, int mid, int en) {
    vector<int> V;
    int i = 0, j = 1;

    while (i <= mid - st && j <= en - mid) {
        if (arr[st + i] > arr[mid + j]) {
            V.push_back(arr[mid + j]);
            j++;
            cnt += mid - (st + i) + 1;
        } else {
            V.push_back(arr[st + i]);
            i++;
        }
    }

    for (size_t left = st + i; left <= mid; left++)
        V.push_back(arr[left]);
    
    for (size_t right = mid + j; right <= en; right++)
        V.push_back(arr[right]);
    
    for (size_t idx = st; idx <= en; idx++)    
        arr[idx] = V[idx - st];
    
}

void mergesort(int st, int en) {
    if (st == en)
        return;
    if (en == st + 1) {
        if (arr[en] < arr[st]) {
            swap(arr[en], arr[st]);
            cnt++;
        }
        return;
    }
    int mid = (st + en) / 2;
    mergesort(st, mid);
    mergesort(mid + 1, en);
    merge(st, mid, en);
}

int main() {
    int N;
    cin >> N;

    for (size_t i = 0; i < N; i++)
        cin >> arr[i];
    
    mergesort(0, N - 1);

    cout << cnt << '\n';
    return 0;
}