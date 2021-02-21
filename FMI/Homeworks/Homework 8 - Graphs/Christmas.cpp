#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map < string, vector <string> > adj;
unordered_map < string, bool > used;
unordered_map < string, string > parent;
vector <string> path;
string startCity, endCity;

void dfs(string start, bool &b)
{
    used[start] = true;
    for (auto i = adj[start].begin(); i!= adj[start].end(); i++)
    {
        if (used[*i]!=true)
        {
            parent[*i] = start;
            dfs(*i,b);
        }
        else if (used[*i]==true && *i==startCity)
        {
            endCity = start;
            b = true;
        }
    }
}

void printCycle()
{
    cout << startCity << " ";
    for (string i = endCity; i!=startCity; i = parent[i])
    {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    for (auto i = path.begin(); i!= path.end(); i++)
    {
        cout << *i << " ";
    }
    cout << startCity << " ";
}

void solve() {
    int n,m;
    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        string city1,city2;
        cin >> city1 >> city2;
        adj[city1].push_back(city2);
    }
    cin >> startCity;
    bool b = false;
    dfs(startCity,b);
    if (b)
    {
        printCycle();
    }
    else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
