#include <iostream>
#include <list>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, K;
    cin >> N >> K;
    list<int> li;
    for (size_t i = 1; i <= N; i++)
        li.push_back(i);
    list<int>::iterator ii = li.begin();
    cout << "<";
    
    while(li.size() != 1) {
        for (size_t i = 0; i < K - 1; i++) {
            ii++;
            if (ii == li.end())
                ii = li.begin();
        }
        cout << *ii << ", ";
        ii = li.erase(ii);
        if (ii == li.end())
            ii = li.begin();
    }    
    cout << *ii << ">\n";
    return 0;
}