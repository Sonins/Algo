#include <stdio.h>
#define MAX 1000010
using namespace std;

int sorted_arr[MAX];
int arr[MAX];

void merge(int start, int mid, int end) {
    int left = start;
    int right = mid + 1;
    int index = start;
    while (left <= mid && right <= end) {
        if (arr[left] < arr[right]) {
            sorted_arr[index] = arr[left];
            left++;
            index++;
        }
        else {
            sorted_arr[index] = arr[right];
            right++;
            index++;
        };
    }

    for (size_t i = left; i <= mid; i++) {
        sorted_arr[index++] = arr[i];
    }

    for (size_t i = right; i <= end; i++) {
        sorted_arr[index++] = arr[i];
    }

    for (size_t i = start; i <= end; i++)
        arr[i] = sorted_arr[i];
    
}

void mergesort(int start, int end) {
    int mid;
    if (start < end) {
        mid = (start + end) / 2;
        mergesort(start, mid);
        mergesort(mid + 1, end);
        merge(start, mid, end);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (size_t i = 0; i < N; i++)
        scanf("%d", &arr[i + 1]);
    
    mergesort(1, N);
    
    for (size_t i = 0; i < N; i++)
    {
        printf("%d ", arr[i + 1]);
    }
    printf("\n");
    
    return 0;
}