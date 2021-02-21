#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector < pair <int,int> > adj[20010];
bool visited[20010];

int prim(int start, int n)
{
    vector <int> dist(n,INT_MAX);
    priority_queue < pair <int,int>, vector < pair <int,int> >, greater < pair <int,int> > > q;
    q.push(make_pair(0,start));
    int result = 0;
    while (!q.empty())
    {
        int v = q.top().second;
        int w = q.top().first;
        
        q.pop();
        
        if(!visited[v])
        {
            visited[v] = true;
            result+=w;
            for (auto i=adj[v].begin(); i!=adj[v].end(); i++)
            {
                if(dist[(*i).first]==INT_MAX || dist[(*i).first]>(*i).second)
                {
                    dist[(*i).first]=(*i).second;
                    q.push(make_pair(dist[(*i).first],(*i).first));
                }
            }
            
        }
    
    }
    return result;
}

void solve() {
    int n,m;
    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        int v1,v2,w;
        cin >> v1 >> v2 >> w;
        adj[v1].push_back(make_pair(v2,w));
        adj[v2].push_back(make_pair(v1,w));
    }
    int minCost = 0;
    for (int i=0; i<n; i++)
    {
        if (!visited[i])
        {
            int currentCost = prim(i,n);
            minCost+=currentCost;
        }
    }
    cout << minCost << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
