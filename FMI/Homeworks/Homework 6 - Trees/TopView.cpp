#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

struct Node {
    int data;
    int hd;
    Node* left;
    Node* right;
};

Node* root;

unordered_map <int,Node*> indexes;

void print() {
    map <int, int> m;
    queue <Node*> q;
    Node* node = root;
    q.push(node);
    node->hd = 0;
    while(!q.empty()) {
        node = q.front();
        int hd = node->hd;
        if (m.find(hd)==m.end()) {
            m[hd] = node->data;
        }
        if (node->left) {
            node->left->hd = hd-1;
            q.push(node->left);
        }
        if (node->right) {
            node->right->hd = hd+1;
            q.push(node->right);
        }
        q.pop();
    }
    for (auto i = m.begin(); i!=m.end(); i++) {
        cout << i->second << " ";
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        indexes[i] = new Node;
        indexes[i]->data = i;
    }
    root = indexes[0];
    int left,right;
    for (int i=0; i<n; i++) {
        cin >> left >> right;
        indexes[i]->left = indexes[left];
        indexes[i]->right = indexes[right];
    }
    print();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}
