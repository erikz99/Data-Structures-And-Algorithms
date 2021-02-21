#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long p,n;

long long ternary_Search(long long no, long long left, long long right, long long& counter){
    long long mid1 = (2*left + right)/3;
    long long mid2 = (left + 2*right)/3+1;
    if (left==right) {
        return counter;
    }
    if(mid1<no && mid2>no) {
        return counter;
    }
    if(mid1>=no) {
        counter++;
        return ternary_Search(no, left,mid1,counter);
    }
    if(mid2<=no) {
        counter++;
        return ternary_Search(no,mid2,right,counter);
    }
    return -1;
}

void solve() {
    cin >> p >> n;
    
    for(long long i=0; i<n; i++) {
        long long no;
        cin >> no;
        long long counter = 1;
        printf("%lld\n",ternary_Search(no,1,pow(3,p),counter));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}
