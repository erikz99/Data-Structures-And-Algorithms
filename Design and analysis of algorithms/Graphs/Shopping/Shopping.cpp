#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

long long n, m;
unordered_map <long long, unordered_set <long long> > adj;
unordered_map <long long, bool> used;
unordered_set <long long> vertices;
long long cnt = 0;

void dfs(long long v) {
    used[v] = true;
    for (auto i = adj[v].begin(); i!=adj[v].end(); i++) {
        if (used[*i]!=true) {
            dfs(*i);
        }
    }
}

void solve() {
    for (auto i = vertices.begin(); i!=vertices.end(); i++) {
        if (used[*i]!=true) {
            dfs(*i);
            cnt++;
        }
    }
    
    cout << n - vertices.size() + cnt;
}

void input() {
    cin >> n >> m;
    
    for (int i=0; i<m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].insert(to);
        adj[to].insert(from);
        
        vertices.insert(from);
        vertices.insert(to);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();
}