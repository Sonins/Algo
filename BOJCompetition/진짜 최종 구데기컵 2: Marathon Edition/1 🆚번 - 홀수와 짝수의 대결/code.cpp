#include <cstring>
#include <iostream>
#include <vector>
#define MAX 10000010
using namespace std;

bool is_prime[MAX];
vector<int> v;
int arr[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    int N;

    memset(is_prime, true, sizeof(is_prime));

    for (size_t i = 4; i < MAX; i += 2)
        is_prime[i] = false;

    for (size_t i = 1; (1 << i) < MAX; i++)
        v.push_back(1 << i);

    for (size_t i = 3; i < MAX; i += 2) {
        if (!is_prime[i])
            continue;

        for (int j = i; j < MAX; j *= i)
            v.push_back(j);

        for (int j = 2 * i; j < MAX; j += i)
            is_prime[j] = false;
    }

    for (auto i : v) {
        for (size_t j = i; j <= MAX; j += i)
            arr[j]++;
    }

    int realodd = 0;
    int realeven = 0;
    int gameeven;
    int gameodd;
    for (size_t i = 1; i < MAX; i++) {
        if (!(arr[i] % 2))
            realeven++;
        else
            realodd++;
        gameeven = realodd;
        gameodd = realeven;
        if (gameeven >= gameodd)
            arr[i] = (int) 'O';
        else
            arr[i] = (int) 'E';
    }
        
    for (size_t t = 0; t < T; t++) {
        cin >> N;    
        cout << (char) arr[N] << '\n';
    }
    
    return 0;
}