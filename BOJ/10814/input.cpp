#include <iostream>
#include <string>
#include <random>
#define MAX 100000

using namespace std;

int main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    static const char character[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    string randomstring;
    int N = MAX;
    cout << N << '\n';
    for (size_t i = 0; i < N; i++)
    {
        for (size_t i = 0; i < (rand() % 10) + 4; i++)
        {
            randomstring.push_back(character[rand() % sizeof(character) - 1]);
        }
        
        cout << rand() % 100 << ' ' << randomstring << '\n';
        randomstring.clear();
    }
    return 0;
}