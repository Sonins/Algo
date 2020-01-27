#include <iostream>
using namespace std;
long long int count[2][2];
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    count[1][1] = 1;
    for (size_t i = 2; i <= N; i++) {
        count[i % 2][0] = count[(i - 1) % 2][0] + count[(i - 1) % 2][1];
        count[i % 2][1] = count[(i - 1) % 2][0];
    }
    cout << count[N % 2][0] + count[N % 2][1] << endl;
    
    return 0;
}
