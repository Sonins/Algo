#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int num;
    vector<int> A;
    vector<int> B;
    vector<int> sorted;

    for (size_t i = 0; i < N; i++) {
        cin >> num;
        A.push_back(num);
    }

    for (size_t i = 0; i < M; i++) {
        cin >> num;
        B.push_back(num);
    }

    while (!A.empty() && !B.empty()) {
        if (A.back() > B.back()) {
            sorted.push_back(A.back());
            A.pop_back();
        } else {
            sorted.push_back(B.back());
            B.pop_back();
        }
    }

    while (!A.empty()) {
        sorted.push_back(A.back());
        A.pop_back();
    }

    while (!B.empty()) {
        sorted.push_back(B.back());
        B.pop_back();
    }

    for (int i = sorted.size() - 1; i >= 0; i--)
        cout << sorted[i] << " ";
        
    cout << '\n';
    return 0;
}