#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

void solve() {
    int n,d;
    cin >> n >> d;
    vector <long long> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }    
    deque <long long> min;
    int cnt = 0;
    int index = 0;
    long long sum =0;
    for (size_t i=0; i<v.size(); i++) {
        while (!min.empty() && min.back() > v[i]) {
            min.pop_back();
        }
        min.push_back(v[i]);
        cnt++;
        if (cnt == d) {
            sum+=min.front();
            if (!min.empty() && min.front()==v[index++]) {
                min.pop_front();
            }
            cnt--;
        }
    }
    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}