#include <iostream>
using namespace std;

long long n,k;
long long dp[101];
long long num[101];
const int MOD = 1000000007;

void input() {
    cin >> n >> k;
}

void solve() {
    num[1] = 1; 
    dp[1] = k;

    for (int i=2; i<=n; i++) {
        dp[i] = (dp[i-1]*k)%(MOD) - num[i-1]%MOD;
        if (dp[i]<0) {
            dp[i]+=MOD;
        }

        num[i] = dp[i-1]%MOD - num[i-1]%MOD;
        if (num[i]<0) {
            num[i]+=MOD;
        }
    }

    cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();
}