#include <iostream>
#include <climits>
using namespace std;

int n;
int arr[510];
int dp[510][510];
int sum[510];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int find(int start, int end) {
    int res = dp[start][end];
    if (res != INT_MAX) {
        return res;
    }
    
    int minCost = INT_MAX;
    for (int i = start; i < end; i++) {
        int length = sum[end] - sum[start] + arr[start];
        int cost = length + find(start, i) + find(i+1, end);

        if (cost < minCost) {
            minCost = cost;
        }

    }
    if (minCost == INT_MAX) minCost = 0;

    dp[start][end] = minCost;
    return minCost;
}

void solve() {
    int s = 0;
    for (int i = 0; i < n; i++) {
        sum[i] += (s + arr[i]);
        s = sum[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INT_MAX;
        }
    }

    int optimalCost = find(0, n-1);
    cout << optimalCost << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();
}
