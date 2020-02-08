#include <iostream>
#include <string>
#include <algorithm>
#define MAX 100010

using namespace std;

typedef struct {
    string name;
    int kor;
    int eng;
    int mat;
} stu;

bool compare (stu a, stu b) {
    if (a.kor == b.kor) {
        if (a.eng == b.eng) {
            if (a.mat == b.mat)
                return a.name < b.name;
            else
                return a.mat > b.mat;
        } else
            return a.eng < b.eng;
    } else
        return a.kor > b.kor;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    stu arr[MAX];
    int N;
    cin >> N;
    string n;
    int k, e, m;
    stu s;
    for (size_t i = 0; i < N; i++)
    {
        cin >> n >> k >> e >> m;
        s.name = n;
        s.kor = k;
        s.eng = e;
        s.mat = m;
        arr[i + 1] = s; 
    }

    sort(arr + 1, arr + N + 1, compare);

    for (size_t i = 0; i < N; i++)
        cout << arr[i + 1].name << '\n';

    return 0;
}