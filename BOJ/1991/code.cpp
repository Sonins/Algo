#include <iostream>
#include <map>
using namespace std;

class node {
   public:
    node* left = NULL;
    node* right = NULL;
    char key;
};

void print(node* ptr, int mode) {
    if (ptr == NULL)
        return;

    if (mode == 1) {
        cout << ptr->key;
        print(ptr->left, 1);
        print(ptr->right, 1);
    } else if (mode == 2) {
        print(ptr->left, 2);
        cout << ptr->key;
        print(ptr->right, 2);
    } else if (mode == 3) {
        print(ptr->left, 3);
        print(ptr->right, 3);
        cout << ptr->key;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    map<char, node*> subtrees;
    node* n = NULL;
    char root, left, right;

    for (size_t i = 0; i < N; i++) {
        cin >> root >> left >> right;
        n = new node;
        n->key = root;
        if (left != '.') {
            n->left = new node;
            n->left->key = left;
        }
        if (right != '.') {
            n->right = new node;
            n->right->key = right;
        }
        subtrees.insert(make_pair(n->key, n));
    }

    for (char c = 'A'; n = subtrees[c]; c++) {
        if (n->left != NULL) {
            left = n->left->key;
            if (subtrees.find(left) != subtrees.end()) {
                delete n->left;
                n->left = subtrees[left];
            }
        }
        if (n->right != NULL) {
            right = n->right->key;
            if (subtrees.find(right) != subtrees.end()) {
                delete n->right;
                n->right = subtrees[right];
            }
        }
    }

    n = subtrees['A'];

    for (size_t i = 1; i < 4; i++) {
        print(n, i);
        cout << '\n';
    }

    return 0;
}