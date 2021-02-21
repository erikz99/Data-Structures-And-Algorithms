#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int &n, int& k) {
        vector <int> v(n);
        for (int i = 0; i < n; i++) {
                cin >> v[i];
        }

        sort(v.begin(), v.end());

        cout << v[k - 1] << "\n";
}

void input() {
        int t, n, k;

        cin >> t;

        for (int i = 0; i < t; i++) {
             	cin >> n >> k;

        	solve(n, k);
        }
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        input();
}


