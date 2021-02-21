#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;
    vector <int> prices(n);
    for (int i=0; i<n; i++) {
        cin >> prices[i];
    }
    queue <int> q;
    int minInd=-1, sum=0, counter=0;
    for (int i=0; i<n; i++) {
        q.push(prices[i]);
        sum+=prices[i];
        counter++;
        while (sum>=k) {
            minInd = minInd==-1 ? counter : min(counter,minInd);
            sum-=q.front();
            q.pop();
            counter--;
        }
    }
    cout << minInd;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
