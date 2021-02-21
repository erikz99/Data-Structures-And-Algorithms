#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    vector <Node*> anc;
};

Node* root;
Node* map[1000000];
int countSubTree[1000000]={};
bool used[1000000];

void countNodes(int s, int e) {
    countSubTree[s] = 1;
    for (size_t i = 0; i<map[s]->anc.size(); i++) {
        int index = map[s]->anc[i]->data;
        if (used[index]) {
            continue;
        }
        countNodes(index,s);
        countSubTree[s]+=countSubTree[index];
        used[index] = true;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        map[i] = new Node;
        map[i]->data = i;
    }
    root = map[0];
    int parent,child;
    for (int i=0; i<n; i++) {
        cin >> parent >> child;
        map[parent]->anc.push_back(map[child]);
    }
    countNodes(0,-1);
    for (int i=0; i<n; i++) {
        cout << countSubTree[i] - 1 << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
