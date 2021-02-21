#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];
int n,q;

int left(int a) {
    int l=0, r=n-1,answer=-1;
    while (l<=r) {
        int mid = (l+r)/2;
        if (arr[mid]>=a) {
            answer=mid;
            r=mid-1;
        }
        else {
            l=mid+1;
        }
    }
    return answer;
}

int right(int b) {
    int l=0, r=n-1,answer=-1;
    while (l<=r) {
        int mid = (l+r)/2;
        if (arr[mid]<=b) {
            answer=mid;
            l=mid+1;
        }
        else {
            r=mid-1;
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
    
    int a,b;
    for (int i=0; i<q; i++) {
        cin >> a >> b;
        int l=left(a),r=right(b);
        if (a>b) {
            printf("%d\n",0);
            continue;
        }
        if (l==-1 || r==-1) {
            printf("%d\n",0);
        } 
        else {
            printf("%d\n",right(b)-left(a)+1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    solve();

    return 0;
}
