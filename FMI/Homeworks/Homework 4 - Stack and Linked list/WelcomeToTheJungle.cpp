#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n;
int forest[1000010];

void init() {
    cin >> n;
    
    for (int i=0; i<n; i++) {
        cin >> forest[i];
    }
    
}

void solve() {
    stack <int> s;
    int maxNum=1, lasti=n-1;
    s.push(forest[n-1]);
    for (int i=n-2; i>=0; i--) {
        while (!s.empty() && forest[i]>=s.top()) {
            s.pop();
        }
        s.push(forest[i]);
        int size = s.size();
        if (size>=maxNum) {
            maxNum = size;
            lasti=i;
        }
    }
    cout << lasti;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    solve();
    
    return 0;
}
