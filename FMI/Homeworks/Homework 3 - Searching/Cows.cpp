#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long positions[100010];
int n,k;

void init() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> positions[i];
    }
}

bool isPossible(long long m, int n, int k)
{
    int counter = 1;
    int prev = positions[0];
    for (int i = 1; i < n; i++)
    {
        if (positions[i] - prev >= m)
        {
            prev = positions[i];
            counter++;
        }
        if (counter == k) {
            return true;
        }
    }
    return false;
}

int minDistance(int n, int k)
{
    int dist=0;
    long long left = positions[0], right = positions[n - 1]-1;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        if (isPossible(mid, n, k))
        {
            if (dist < mid)
            {
                dist = mid;
            }
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
    return dist;
}

void solve() {
    sort(positions, positions + n);
    cout << minDistance(n, k);
}

int main()
{   
    init();
    solve();
}