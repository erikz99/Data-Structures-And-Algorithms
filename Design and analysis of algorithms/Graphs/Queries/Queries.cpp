#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

long long n, m, q;
vector < pair <long long, long long> > adj[600];
vector < vector <long long> > queries(600, vector <long long>(600));

void dijkstra(int from) {
    vector <long long> dist(n + 1, INT_MAX);
    vector <long long> used(n + 1, false);
    vector <long long> minPaths(n + 1, 0);
    dist[from] = 0;
    queries[from][from] = 1;
    priority_queue < pair<long long, long long>, vector <pair<long long, long long>>, greater <pair<long long, long long>>> pq;
    pq.push({ 0,from });

    while (!pq.empty()) {
        long long v = pq.top().second;
        pq.pop();
        if (used[v] == true) {
            continue;
        }
        used[v] = true;
        for (size_t i = 0; i < adj[v].size(); i++) {
            long long v1 = adj[v][i].first;
            long long w1 = adj[v][i].second;

            if (dist[v1] > dist[v] + w1) {
                queries[from][v1] = queries[from][v]%(1000000021);
                dist[v1] = dist[v] + w1;
                pq.push({ dist[v1],v1 });
            }
            else if (dist[v1] == dist[v] + w1) {
                queries[from][v1] += (queries[from][v])%(1000000021);
            }
        }
    }
}

void solve() {
    cin >> q;
    for (long long i=1; i<=n; i++) {
        dijkstra(i);
    }
    for (long long i = 0; i < q; i++) {
        long long from, to;
        cin >> from >> to;
        cout << (queries[from][to])%(1000000021) << " ";
    }
}

void init() {
    cin >> n >> m;
    for (long long i = 0; i < m; i++) {
        long long from, to, weight;
        cin >> from >> to >> weight;

        adj[from].push_back({ to,weight });
        adj[to].push_back({ from,weight });
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    solve();
}