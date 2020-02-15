#include <iostream>
#include <list>
using namespace std;

list<char> li;

void scan() {
    char c[100010];
    cin >> c;
    int idx = -1;
    while (c[++idx] != '\0')
        li.push_back(c[idx]);
}

void print() {
    for (list<char>::iterator i = li.begin(); i != li.end(); i++) {
        cout << *i;
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    scan();
    int N;
    cin >> N;
    char com;
    list<char>::iterator ii = li.end();
    for (size_t i = 0; i < N; i++) {
        cin >> com;
        switch (com) {
        case 'L':
            if (ii != li.begin())
                ii--;
            break;
        case 'D':
            if (ii != li.end())
                ii++;
            break;
        case 'B':
            if (ii != li.begin())
                ii = li.erase(--ii);
            break;
        case 'P':
            cin >> com;
            if (ii != li.end())
                li.insert(ii, com);
            else
                li.push_back(com);
            break;
        default:
            break;
        }
    }
    print();
    return 0;
}