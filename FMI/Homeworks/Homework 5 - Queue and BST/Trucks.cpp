#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <stdio.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    stack <int> s;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int i=0;
    while (v[i]<0) {
        s.push(v[i]);
        i++;
    }
    for (; i<n; i++) {
        if (s.empty()) {
            s.push(v[i]);
            continue;
        }
        if(v[i]>0) {
            s.push(v[i]);
        }
        else {
            if (s.top()<0) {
                s.push(v[i]);
            }
            else {
                while(!s.empty() && s.top()>0 && abs(s.top()) < abs(v[i])) {
                    s.pop();
                }
                if(s.empty() || s.top()<0) {
                    s.push(v[i]);
                }
                else if(s.top()>0 && abs(s.top()) == abs(v[i])) {
                    s.pop();
                }
            }
        }
    }
    stack <int> s2;
    while (!s.empty()) {
        s2.push(s.top());
        s.pop();
    }
    while (!s2.empty()) {
        printf("%d ", s2.top());
        s2.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();   
    return 0;
}
