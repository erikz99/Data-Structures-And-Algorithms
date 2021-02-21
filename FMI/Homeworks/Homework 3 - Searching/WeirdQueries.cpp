#include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long arr[200000];
long long sums[200000];
long long n,q;
long long s,p;

long long binarySearchFindSmaller(long long num) {
    long long l=0,r=n-1,answer=-1;
    while (l<=r) {
        long long mid = (l+r)/2;
        if (arr[mid]<=num) {
            l=mid+1;
            answer = mid;
        } 
        else {
            r = mid-1;
        }
    }
    return answer;
}

bool isOk(long long i, long long r) {
    
    if (sums[i]-sums[r-1]<=s) {
        return true;
    }
    return false;
}

long long binarySearchByAnswer(long long i) {
    long long l=0, r=i;
    long long answer=-1;
    while (l<=r) {
        long long mid=(l+r)/2;
        if (isOk(i,mid)) {
            answer = mid;
            r=mid-1;
        }
        else {
            l=mid+1;
        }
    }
    return answer;
}

void init() {
    cin >> n >> q;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
}

void solve() {
    sort(arr,arr+n);
    long long sum=0;
    for (int i=0; i<n; i++) {
        sum+=arr[i];
        sums[i]=sum;
    }
    for (int i=0; i<q; i++) {
        cin >> s >> p;
        long long index = binarySearchFindSmaller(p);
        if (index==-1) {
            cout << 0 << "\n";
            continue;
        }
        long long answer = binarySearchByAnswer(index);
        if (answer==-1) {
            cout << 0 << "\n";
            continue;
        }
        cout << index - answer + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    solve();
    
    return 0;
}