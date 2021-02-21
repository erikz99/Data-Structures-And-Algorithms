#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct knight {
    int x, y;
};

struct cell {
    int first, second;
};

knight arr[2020];
int mat[2020][2020];
int moves = 0;
int cnt = 0;
int n, m, k;
int pX, pY;

void bfs(int x, int y) {
    vector < vector <int> > used(n, vector <int>(n, false));
    vector < vector <int> > dist(n, vector <int>(n, INT_MAX));
    queue < cell > q;
    dist[x][y] = 0;
    q.push({ x,y });

    while (!q.empty()) {
        cell p = q.front();
        int x = p.first;
        int y = p.second;

        q.pop();

        if ((!((x - 1 < 0 || x - 1 > n - 1) || (y - 2 < 0 || y - 2 > n - 1))) && (mat[x - 1][y - 2] != 1) && (!used[x - 1][y - 2])) {
            used[x - 1][y - 2] = true;
            dist[x - 1][y - 2] = dist[x][y] + 1;
            q.push({ x - 1 , y - 2 });
        }

        if ((!((x - 2 < 0 || x - 2 > n - 1) || (y - 1 < 0 || y - 1 > n - 1))) && (mat[x - 2][y - 1] != 1) && (!used[x - 2][y - 1])) {
            used[x - 2][y - 1] = true;
            dist[x - 2][y - 1] = dist[x][y] + 1;
            q.push({ x - 2 , y - 1 });
        }

        if ((!((x + 2 < 0 || x + 2 > n - 1) || (y - 1 < 0 || y - 1 > n - 1))) && (mat[x + 2][y - 1] != 1) && (!used[x + 2][y - 1])) {
            used[x + 2][y - 1] = true;
            dist[x + 2][y - 1] = dist[x][y] + 1;
            q.push({ x + 2 , y - 1 });
        }

        if ((!((x + 1 < 0 || x + 1 > n - 1) || (y + 2 < 0 || y + 2 > n - 1))) && (mat[x + 1][y + 2] != 1) && (!used[x + 1][y + 2])) {
            used[x + 1][y + 2] = true;
            dist[x + 1][y + 2] = dist[x][y] + 1;
            q.push({ x + 1 , y + 2 });
        }

        if ((!((x - 2 < 0 || x - 2 > n - 1) || (y + 1 < 0 || y + 1 > n - 1))) && (mat[x - 2][y + 1] != 1) && (!used[x - 2][y + 1])) {
            used[x - 2][y + 1] = true;
            dist[x - 2][y + 1] = dist[x][y] + 1;
            q.push({ x - 2 , y + 1 });
        }

        if ((!((x - 1 < 0 || x - 1 > n - 1) || (y + 2 < 0 || y + 2 > n - 1))) && (mat[x - 1][y + 2] != 1) && (!used[x - 1][y + 2])) {
            used[x - 1][y + 2] = true;
            dist[x - 1][y + 2] = dist[x][y] + 1;
            q.push({ x - 1 , y + 2 });
        }

        if ((!((x + 2 < 0 || x + 2 > n - 1) || (y + 1 < 0 || y + 1 > n - 1))) && (mat[x + 2][y + 1] != 1) && (!used[x + 2][y + 1])) {
            used[x + 2][y + 1] = true;
            dist[x + 2][y + 1] = dist[x][y] + 1;
            q.push({ x + 2 , y + 1 });
        }

        if ((!((x + 1 < 0 || x + 1 > n - 1) || (y - 2 < 0 || y - 2 > n - 1))) && (mat[x + 1][y - 2] != 1) && (!used[x + 1][y - 2])) {
            used[x + 1][y - 2] = true;
            dist[x + 1][y - 2] = dist[x][y] + 1;
            q.push({ x + 1 , y - 2 });
        }
    }
    
    for (int i = 0; i < k; i++) {
        int m = arr[i].x, l = arr[i].y;
        int distance = dist[m][l];
        if (distance != INT_MAX) {
            cnt++;
            moves = distance > moves ? distance : moves;
        }
    }
}

void solve() {
    bfs(pX,pY);

    cout << cnt << " " << moves;
}

void input() {
    cin >> n >> m >> k;
    int x, y;


    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        mat[x][y] = 1;
    }

    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        arr[i] = { x,y };
    }

    cin >> pX >> pY;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();
}