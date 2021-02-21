#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector <long long> vect1, vector <long long> vect2, int n, long long m, long long  c)
{
    for (int i = 0; i < n; i++)
    {
        if (c / vect2[i] >= vect1[i])
        {
            continue;
        }
        else
        {
            long long diff = vect1[i] - c / vect2[i];
            m -= diff;
            if (m < 0)
            {
                return false;
            }
        }
    }
    return true;
}

long long getMinMax(vector <long long> vect1, vector <long long> vect2, int n, long long m)
{
    long long right = vect1[0] * vect2[0];
    for (int i = 1; i < n; i++)
    {
        if (vect1[i] * vect2[i] > right)
        {
            right = vect1[i] * vect2[i];
        }
    }
    long long left = 0;
    while (left < right)
    {
        long long mid = left + (right - left) / 2;
        if (isPossible(vect1, vect2, n, m, mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

void solve() {
    int n;
    cin >> n;
    long long m;
    cin >> m;
    vector <long long> balloons;
    for (int i = 0; i < n; i++)
    {
        long long b;
        cin >> b;
        balloons.push_back(b);
    }
    vector <long long> candies;
    for (int i = 0; i < n; i++)
    {
        long long c;
        cin >> c;
        candies.push_back(c);
    }
    
    cout << getMinMax(balloons, candies, n, m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}