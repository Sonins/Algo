#include <iostream>
#include <string>
#define MAX 100010

using namespace std;
pair<int, string> arr[MAX];
pair<int, string> sorted[MAX];

void merge(int start, int mid, int end) {
    int leftpart = start;
    int rightpart = mid + 1;
    int index = start;
    while (leftpart <= mid && rightpart <= end) {
        if (arr[leftpart].first <= arr[rightpart].first) {
            sorted[index++] = make_pair(arr[leftpart].first, arr[leftpart].second);
            leftpart++;
        } else {
            sorted[index++] = make_pair(arr[rightpart].first, arr[rightpart].second);
            rightpart++;
        }
    }

    for (size_t i = leftpart; i <= mid; i++) {
        sorted[index++] = arr[i];
    }

    for (size_t i = rightpart; i <= end; i++) {
        sorted[index++] = arr[i];
    }
    
    for (size_t i = start; i <= end; i++) {
        arr[i] = sorted[i];
    }
    
}

void mergesort(int l, int r) {
    int mid = (l + r) / 2;
    if (l < r) {
        mergesort(l, mid);
        mergesort(mid + 1, r);
        merge(l, mid, r);    
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    int age;
    string name;
    for (size_t i = 0; i < N; i++)
    {
        cin >> age >> name;
        arr[i + 1] = make_pair(age, name);
    }
    
    mergesort(1, N);

    for (size_t i = 0; i < N; i++)
    {
        cout << arr[i + 1].first << " " << arr[i + 1].second << '\n';
    }
    return 0;

}