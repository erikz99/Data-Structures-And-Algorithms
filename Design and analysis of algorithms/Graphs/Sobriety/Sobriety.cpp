#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

int n, m, start, mid, final;
int dist[50010];
bool used[50010];
int parent[50010];
vector <int> path;
vector < pair <int, int> > adj[50010];

void dijkstra(int s, int end) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    for (int i = 1; i <= n; i++) {
        used[i] = false;
    }
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
    }
    priority_queue < pair <int, int>, vector <pair <int, int>>, greater<pair<int, int>> > pq;
    dist[s] = 0;
    pq.push({ dist[s],s });
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        if (used[v]) {
            continue;
        }
        used[v] = true;
        for (int i = 0; i < adj[v].size(); i++) {
            int v1 = adj[v][i].second;
            int w1 = adj[v][i].first;
            if (dist[v1] > dist[v] + w1) {
                parent[v1] = v;
                dist[v1] = dist[v] + w1;
                pq.push({ dist[v1],v1 });
            }
        }
        if (v == end) {
            break;
        }
    }

}

void printPath(int v)
{
    if (parent[v] == -1)
        return;
    printPath(parent[v]);
    path.push_back(v);
}

void solve() {
	scanf("%d %d %d %d %d", &n, &m, &start, &mid, &final);
    int from, to, weight;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &from, &to, &weight);
        adj[from].push_back({ weight,to });
        adj[to].push_back({ weight,from });
    }
    int total = 0;
    path.push_back(start);
    dijkstra(start, mid);
    if (dist[mid] == INT_MAX) {
        printf("%d", -1);
        return;
    }
    total += dist[mid];
    int v = mid;
    printPath(v);
    dijkstra(mid, final);
    if (dist[final] == INT_MAX) {
        printf("%d", -1);
        return;
    }
    total += dist[final];
    v = final;
    printPath(v);
    printf("%d\n", total);
    for (int i = 0; i < path.size(); i++) {
        printf("%d ", path[i]);
    }
}

int main() {
   	solve();
}