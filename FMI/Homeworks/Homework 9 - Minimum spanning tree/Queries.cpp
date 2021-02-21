#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector <int> p;
vector <int> r;

struct Edge
{
    int from,to;
    
};

vector <Edge> edges;

void make_set(int v)
{
    p[v]=v;
    r[v]=0;
}

int find_set(int v)
{
    if (v==p[v]) return v;
    return p[v] = find_set(p[v]);
}

void union_set(int v1, int v2)
{
    v1 = find_set(v1);
    v2 = find_set(v2);
    if (v1!=v2)
    {
        if (r[v1]<r[v2])
        {
            swap(v1,v2);
        }
        p[v2]=v1;
        if (r[v1]==r[v2])
        {
            r[v1]++;
        }
    }
}

void kruskall(int n, int m)
{
    for (int i=1; i<=n; i++)
    {
        make_set(i);
    }
    for (int i=0; i<m; i++)
    {
        if (find_set(edges[i].from)!=find_set(edges[i].to))
        {
            union_set(edges[i].from,edges[i].to);
        }
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    p.resize(n+1);
    r.resize(n+1);
    edges.resize(m);
    for (int i=0; i<m; i++)
    {
        int v1,v2; 
        cin >> v1 >> v2;
        edges[i].from = v1;
        edges[i].to = v2;
    }
    int q;
    cin >> q;
    kruskall(n,m);
    for (int i=0; i<q; i++)
    {
        int code;
        cin >> code;
        int v1,v2;
        cin >> v1 >> v2;
        if (code==1)
        {
            if (find_set(v1)==find_set(v2))
            {
                printf("%d",1);
            }
            else printf("%d",0);
        }
        else if (code==2)
        {
            union_set(v1,v2);
        }
    }    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
