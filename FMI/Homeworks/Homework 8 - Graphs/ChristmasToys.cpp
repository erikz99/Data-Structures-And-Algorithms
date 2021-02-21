#include <cmath>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

unordered_map <long long, unordered_set <long long>  > adj;
unordered_map <long long, bool > used;
unordered_set <long long> met;

void dfs(long long n, long long &countVisited)
{
    used[n] = true;
    for (auto i = adj[n].begin(); i!=adj[n].end(); i++)
    {
        if (used[*i]!=true)
        {
            dfs(*i,countVisited);
            countVisited++;
        }
    }
}

long long getSameColour(long long n)
{
    long long countVisited = 0;
    long long countComp = 0;
    for (auto i = met.begin(); i!=met.end(); i++)
    {
        if (used[*i]!=true)
        {
            dfs(*i,countVisited);
            countVisited++;
            countComp++;
        }
    }
    return countVisited-countComp;
}

void solve() {
    long long n;
    int m;
    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        long long c1, c2;
        cin >> c1 >> c2;
        met.insert(c1);
        met.insert(c2);
        adj[c1].insert(c2);
        adj[c2].insert(c1);
    }
    cout << n-getSameColour(n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}
