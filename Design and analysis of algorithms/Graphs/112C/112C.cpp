#include <iostream>
#include <vector>
using namespace std;

int n, m, q;
int cnt = 1;
vector <int> adj[1010];
int comp[1010];
int used[1010];

void bfsUtill(int v) {
        used[v] = true;
        comp[v] = cnt;
        for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
                if (!used[*i]) {
                        bfsUtill(*i);
                }
        }
}

void bfs() {
        for (int i = 1; i <= n; i++) {
                if (!used[i]) {
                        bfsUtill(i);
                        cnt++;
                }
        }
}

void solve() {
        bfs();
        cin >> q;

        for (int i = 0; i < q; i++) {
                int from, to;
                cin >> from >> to;

                if (comp[from] == comp[to]) {
                        cout << 1;
                }
                else {
                        cout << 0;
                }
        }
}

void input() {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
                int from, to;
                cin >> from >> to;
                adj[from].push_back(to);
                adj[to].push_back(from);
        }
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        input();
        solve();
}