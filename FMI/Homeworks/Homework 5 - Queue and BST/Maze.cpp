#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

bool used[1001][1001];
char mat[1001][1001];
int startX, startY, endX, endY;

bool valid(int i, int j, int n, int m)
{
    if (i>=0 && j>=0 && i<n && i<m && mat[i][j]!='#') return true;
    return false;
}

bool in(int i, int j, int n, int m)
{
    if (i>=0 && j>=0 && i<n && i<m) return true;
    return false;
}

int bfs(int n, int m)
{
    queue < pair <int, int> > q;
    q.push(make_pair(startX,startY));
    used[startX][startY] = true;
    int level[1001][1001];
    level[startX][startY] = 0;
    while (!q.empty())
    {
        pair <int, int> p = q.front();
        if (p.first == endX && p.second == endY)
        {
            return level[endX][endY];
        }
        int x = p.first+1;
        while (mat[x][p.second]!='#' && in(x,p.second,n,m))
        {
            x++;
        }
        if (mat[x][p.second]=='#' && !used[x-1][p.second])
        {
            q.push(make_pair(x-1,p.second));
            level[x-1][p.second] = level[p.first][p.second]+1;
            used[x-1][p.second] = true;
        }
        if (!used[p.first+1][p.second] && valid(p.first+1,p.second,n,m))
        {
            used[p.first+1][p.second] = true;
            q.push(make_pair(p.first+1,p.second));
            level[p.first+1][p.second] = level[p.first][p.second]+1;
        }
        int y = p.second-1;
        while (mat[p.first][y]!='#' && in(p.first,y,n,m))
        {
            y--;
        }
        if (mat[p.first][y]=='#' && !used[p.first][y+1])
        {
            q.push(make_pair(p.first,y+1));
            level[p.first][y+1] = level[p.first][p.second]+1;
            used[p.first][y+1] = true;
        }
        if (!used[p.first][p.second-1] && valid(p.first,p.second-1,n,m))
        {
            used[p.first][p.second-1] = true;
            q.push(make_pair(p.first,p.second-1));
            level[p.first][p.second-1] = level[p.first][p.second]+1;
        }
        y = p.second+1;
        while (mat[p.first][y]!='#' && in(p.first,y,n,m))
        {
            y++;
        }
        if (mat[p.first][y]=='#' && !used[p.first][y-1])
        {
            q.push(make_pair(p.first,y-1));
            level[p.first][y-1] = level[p.first][p.second]+1;
            used[p.first][y-1] = true;
        }
        if (!used[p.first][p.second+1] && valid(p.first,p.second+1,n,m) )
        {
            used[p.first][p.second+1] = true;
            q.push(make_pair(p.first,p.second+1));
            level[p.first][p.second+1] = level[p.first][p.second]+1;
        }
        x = p.first-1;
        while (mat[x][p.second]!='#' && in(x,p.second,n,m))
        {
            x--;
        }
        if (mat[x][p.second]=='#' && !used[x+1][p.second])
        {
            q.push(make_pair(x+1,p.second));
            level[x+1][p.second] = level[p.first][p.second]+1;
            used[x+1][p.second] = true;
        }
        if (!used[p.first-1][p.second] && valid(p.first-1,p.second,n,m) )
        {
            used[p.first-1][p.second] = true;
            q.push(make_pair(p.first-1,p.second));
            level[p.first-1][p.second] = level[p.first][p.second]+1;
        }
        q.pop();
    }
    return -1;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j]=='S')
            {
                startX = i;
                startY = j;
            }
            else if (mat[i][j]=='F')
            {
                endX = i;
                endY = j;
            }
        }
    }
    cout << bfs(n,m) << endl;  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}
