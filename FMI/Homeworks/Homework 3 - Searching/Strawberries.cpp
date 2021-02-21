#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class bowl
{
public:
    long long start;
    long long end;
    bowl(long long start=0, long long end=0)
    {
        this->start = start;
        this->end = end;
    }
};

bowl bowls[100010];
long long positions[100010];
int n, m;

int binarySearch(int l, int r, long long k)
{
    if (l>r) return 0;
    int m = (l+r)/2;
    if (bowls[m].start<=k && bowls[m].end>=k) return m+1;
    if (bowls[m].end<k) return binarySearch(m+1,r,k);
    return binarySearch(l,m-1,k);
}

void init() {
    cin >> n;
    long long start = 1;
    for (int i=0; i<n; i++)
    {
        long long strawberries;
        cin>>strawberries;
        bowls[i] = bowl(start,strawberries+start-1);
        start+=strawberries;
    }
    
    cin >> m;
    
    for (int i=0; i<m; i++)
    {
        cin >> positions[i];
    }
}

void solve() {
    for (int i=0; i<m; i++)
    {
        cout << binarySearch(0,n-1,positions[i]) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    solve();
}

