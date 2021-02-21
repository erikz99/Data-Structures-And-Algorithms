#include <iostream>
#include <vector>
using namespace std;

int n, m, cnt=0;
vector <int> adjList[501];
bool used[501];

void dfsUtil(int v) {
        used[v] = true;
        for (auto i = adjList[v].begin(); i != adjList[v].end(); i++) {
                if (!used[*i]) {
                        dfsUtil(*i);
                }
        }
}

void dfs() {
        for (int i = 1; i <= n; i++) {
                if (!used[i]) {
                        dfsUtil(i);
                        cnt++;
                }
        }
}

void init() {
        scanf("%d %d", &n, &m);
        int from, to;
        for (int i = 0; i < m; i++) {
                scanf("%d %d", &from, &to);
                adjList[from].push_back(to);
                adjList[to].push_back(from);
        }
}

void solve() {
	dfs();
        printf("%d", cnt);
}

int main() {
        init();
        solve();
}