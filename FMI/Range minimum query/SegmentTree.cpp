#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

long long arr[1000010], lazy[1000010];
int n,m;

struct Node {
    Node* left, *right;
    int from, to;
    long long value;
    long long lazy;

    Node(int from = 0, int to = 0, long long value = 0,Node* left = NULL, Node* right = NULL, long long lazy = 0) 
    : left(left), right(right), from(from), to(to), value(value), lazy(lazy)
    {}
};

Node* root;

Node* buildUtill(int start, int end) {
    if (start==end) {
        return new Node(start,end,arr[start]);
    }

    Node* node = new Node;
    int mid = (start+end)/2;
    
    node->left = buildUtill(start, mid);
    node->right = buildUtill(mid+1, end);

    node->from = start;
    node->to = end;

    if (start==end) {
        node->value = arr[start];
    }
    else {
        node->value = min(node->left->value, node->right->value);
    }

    return node;
}

void build() {
    root = buildUtill(0,n-1);
}

void input() {
    cin >> n >> m;
    
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
}

void print() {
    queue <Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        if (node->left) { 
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
}

long long getMinUtill(Node* node, int from, int to) {
    if (node->lazy>0) {
        node->value+=node->lazy;
        if (node->left && node->right) {
            node->left->lazy+=node->lazy;
            node->right->lazy+=node->lazy;
        }
        node->lazy = 0;
    }

    if (node->to < from || node->from > to) {
        return LLONG_MAX;
    }

    if (node->from >= from && node->to <= to) {
        return node->value;
    }

    long long minLeft = getMinUtill(node->left,from,to);
    long long minRight =  getMinUtill(node->right,from,to);
    
    return min(minLeft,minRight);
}

long long getMin(int from, int to) {
    return getMinUtill(root,from,to);
}

void updateUtill(Node* node, int from, int to, long long add) {

    if (node->lazy>0) {
        node->value+=node->lazy;
        if (node->left && node->right) {
            node->left->lazy+=node->lazy;
            node->right->lazy+=node->lazy;
        }
        node->lazy = 0;
    }

    if (node->to < from || node->from > to) {
        return;
    }

    if (node->from >= from && node->to <= to) {
        node->lazy+=add;
        if (node->lazy>0) {
            node->value+=node->lazy;
            if (node->left && node->right) {
                node->left->lazy+=node->lazy;
                node->right->lazy+=node->lazy;
            }
            node->lazy = 0;
        }
        return;
    }
    
    updateUtill(node->left,from,to,add);
    updateUtill(node->right,from,to,add);
    node->value = min(node->left->value,node->right->value);
}

void update(int from, int to, long long add) {
    updateUtill(root,from,to,add);
}

void process() {
    for (int i=0; i<m; i++) {
        int op;
        cin >> op;

        if (op==1) {
            int from, to;
            cin >> from >> to;
            cout << getMin(from,to) << "\n";
        } else if (op==2) {
            int index, add;
            cin >> index >> add;
            update(index,index,add);
        } else if (op==3) {
            int from, to, add;
            cin >> from >> to >> add;
            update(from,to,add);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    build();
    process();
}