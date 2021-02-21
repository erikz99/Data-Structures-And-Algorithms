#include cmath
#include cstdio
#include vector
#include iostream
#include algorithm
#include queue
#include unordered_map
using namespace std;

struct Node {
    int data;
    vector Node anc;
};

Node root;
Node map[1000000];
bool used[1000000];
int timeIn[1000000];
int timeOut[1000000];
int counter = 0;

void dfs(int s) {
    timeIn[s] = counter++;
    for (size_t i = 0; imap[s]-anc.size(); i++) {
        int index = map[s]-anc[i]-data;
        if (used[index]) {
            continue;
        }
        dfs(index);
        used[index] = true;
    }
    timeOut[s] = counter++;
}

void solve() {
    int n;
    cin  n;
    for (int i=0; in; i++) {
        map[i] = new Node;
        map[i]-data = i;
    }
    root = map[0];
    int parent,child;
    for (int i=0; in-1; i++) {
        cin  parent  child;
        map[parent]-anc.push_back(map[child]);
    }
    int q;
    cin  q;
    dfs(0);
    for (int i=0; iq; i++) {
        cin  parent  child;
        if (timeIn[child] = timeIn[parent] && timeOut[child] = timeOut[parent]) {
            printf(YESn);
        }
        else {
            printf(NOn);
        }
    }
}

int main() {
    ios_basesync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
