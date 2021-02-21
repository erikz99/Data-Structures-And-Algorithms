#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector < vector <int> > mat;

void floydWarshall(int n)
{
    for (int k=0; k<n; k++)
    {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (mat[i][j]>mat[i][k]+mat[k][j])
                {
                    mat[i][j]=mat[i][k]+mat[k][j];
                }
            }
        }
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    mat.resize(n);
    for (int i=0; i<n; i++)
    {
        mat[i] = vector <int>(n,1000000);
    }
    for (int i=0; i<n; i++)
    {
        mat[i][i]=0;
    }
    for (int i=0; i<m; i++)
    {
        int v1,v2,w;
        cin >> v1 >> v2 >> w;
        v1--; 
        v2--;
        mat[v1][v2] = w;
    }

    int q;
    cin >> q;
    floydWarshall(n);
    for (int i=0; i<q; i++)
    {
        int s,e;
        cin >> s >> e;
        s--;
        e--;
        if (mat[s][e]==1000000) cout << -1 << "\n";
        else cout << mat[s][e] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}