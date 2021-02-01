#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int A[1010];
int B[1010];

int main() {
    int T, N, M;
    cin >> T;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    cin >> M;
    for (int i = 1; i <= M; i++)
        cin >> B[i];
    
    unordered_map<int, int> map;
    for (int i = 1; i <= N; i++) {
        A[i] += A[i - 1];
        for (int j = 0; j < i; j++) {
            if (map.find(A[i] - A[j]) == map.end())
                map.insert(make_pair(A[i] - A[j], 1));
            else
                map.find(A[i] - A[j])->second++;
        }
    }

    long long int cnt = 0;
    for (int i = 1; i <= M; i++) {
        B[i] += B[i - 1];
        for (int j = 0; j < i; j++) {
            if (map.find(T - (B[i] - B[j])) != map.end())
                cnt += map.find(T - (B[i] - B[j]))->second;
        }
    }

    cout << cnt << '\n';
    return 0;
}

/**
 * 마찬가지로 int 배열 넘는것 없는지 확인 잘하기
*/