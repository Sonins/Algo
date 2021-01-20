#include <iostream>
#include <algorithm>

#define MAX 4002

using namespace std;

int AB[MAX * MAX];
int CD[MAX * MAX];
int arr[MAX][4];

int main() {
    int N;
    ios::sync_with_stdio(false);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            AB[i * N + j] = arr[i][0] + arr[j][1];
            CD[i * N + j] = -1 * (arr[i][2] + arr[j][3]);
        }
    }
    
    sort(AB, AB + N * N);
    sort(CD, CD + N * N);

    long long int cnt = 0;

    int ABp = 0;
    int CDp = 0;
    int ABcnt = 0;
    int CDcnt = 0;

    while (ABp < N * N && CDp < N * N) {
        int ABval = AB[ABp];
        int CDval = CD[CDp];
        if (ABval < CDval) {
            while (AB[ABp] == ABval && ABp < N * N) ABp++;
            continue;
        }

        if (ABval > CDval) {
            while (CD[CDp] == CDval && CDp < N * N) CDp++;
            continue;
        }

        while (AB[ABp] == ABval && ABp < N * N) {
            ABp++;
            ABcnt++;
        }
    
        while (CD[CDp] == CDval && CDp < N * N) {
            CDp++;
            CDcnt++;
        }
        cnt += (long long int) ABcnt * CDcnt;
        ABcnt = 0;
        CDcnt = 0;
    }

    cout << cnt << endl;
    return 0;
}

/**
 * long long int에 int 연산을 더할때 캐스팅 꼭 해줄것
*/