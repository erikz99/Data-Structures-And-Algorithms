#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long printers[1000000];
long long n,k;

long long printed(long long s) {
    long long ans=0;
    for (int i=0; i<k; i++) {
        ans+=s/printers[i];
    }
    return ans;
}

long long binarySearch() {
    long long l=0,r=100000000000;
    long long ans=0;
    while(l<=r) {
        long long mid =(l+r)/2;
        long long p = printed(mid);
        if (p>=n) {
            ans=mid;
            r=mid-1;
        }
        else {
            l=mid+1;
        }
    }
    return ans;
}

void init() {
    cin >> n >> k;
    for (long long i=0; i<k; i++) {
        cin >> printers[i];
    }
}

void solve() {
    cout << binarySearch();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    solve();
    
    return 0;
}
