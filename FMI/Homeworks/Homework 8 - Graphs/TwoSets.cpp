#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <unordered_set>
using namespace std;

typedef pair <int, int> Pair;
vector < pair <int, int> > adj[100010];

void dijkstra(int start, int* dist, int n)
{
    dist[start] = 0;
    priority_queue < Pair, vector <Pair> , greater <Pair> > p; 
    p.push(make_pair(start,0));
    while (!p.empty())
    {
        int v = p.top().first;
        p.pop();
        
        for (auto i = adj[v].begin(); i!=adj[v].end(); i++)
        {
            int v1 = (*i).first;
            int w1 = (*i).second;
            
            if (dist[v1]>dist[v]+w1)
            {
                dist[v1] = dist[v] + w1;
                p.push(make_pair(v1,dist[v1]));
            }
        }
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj[from].push_back(make_pair(to,weight));
        adj[to].push_back(make_pair(from,weight));
    }
    int* dist = new int[n];
    for (int i=0; i<n; i++)
    {
        dist[i] = INT_MAX;
    }
    int k;
    cin >> k;
    unordered_set <int> discos;
    for (int i=0; i<k; i++)
    {
        int disco;
        cin >> disco;
        discos.insert(disco);
    }
    int q;
    cin >> q;
    int* minEdge = new int[n];
    for (int i=0; i<n; i++)
    {
        minEdge[i] = INT_MAX;
    }
    for (auto k = discos.begin(); k!=discos.end(); k++)
    {
        for (auto j = adj[*k].begin(); j!=adj[*k].end(); j++ )
        {
            if ((*j).second<minEdge[(*j).first] && discos.find((*j).first)==discos.end())
            {
                minEdge[(*j).first] = (*j).second;
            }
        }
    }
    int v = n+3;
    for (int i=0; i<n; i++)
    {
        if (minEdge[i] !=INT_MAX)
        {
            adj[i].push_back(make_pair(v,minEdge[i]));
            adj[v].push_back(make_pair(i,minEdge[i]));
        }
    }
    dijkstra(v,dist,n);
    for (int i=0; i<q; i++)
    {
        int loc;
        cin >> loc;
        cout << dist[loc] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
