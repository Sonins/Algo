#include <iostream>
#include <cstring>

using namespace std;

int arr[41], N, S, sum[4000100];
long long int cnt;

int normalize(int i) {
    return i + 2000000;
}

void firstDFS(int i, int s) {
    if (i == N / 2)
        return;

    sum[normalize(s + arr[i])]++;
    firstDFS(i + 1, s);
    firstDFS(i + 1, s + arr[i]); 
}

void secondDFS(int i, int s) {
    if (i == N)
        return;

    int idx = normalize(S - (s + arr[i]));
    if (idx >= 0 && idx <= normalize(2000000)) cnt += sum[idx];
    secondDFS(i + 1, s);
    secondDFS(i + 1, s + arr[i]);
}

int main() {
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    memset(sum, 0, sizeof(sum));
    sum[normalize(0)]++;
    firstDFS(0, 0);
    cnt += sum[normalize(S)];
    secondDFS(N / 2, 0);

    if (S == 0)
    // if S == 0, there is empty set counted in answer.
        cnt--;
    
    cout << cnt << endl;
    return 0;
}

/**
 * cnt 크기가 int 범위를 넘어설 수도 있다는 것을 고려하지 않았음. (i.e. 40 0 \n 0 * 40 이 input 일때)
 * 공집합이 카운트 됐다는것도 고려 안함
*/