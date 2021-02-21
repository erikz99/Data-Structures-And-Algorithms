#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100010];

int binarySearchGreater(int num) {
        int left = 0, right = n - 1, ans = -1;

        while (left <= right) {
                int mid = (left + right) / 2;

                if (arr[mid] >= num) {
                        ans = mid;
                        right = mid - 1;
                }
                else {
                        left = mid + 1;
                }
        }
        return ans;
}

int binarySearchLess(int num) {
        int left = 0, right = n - 1, ans = -1;

        while (left <= right) {
                int mid = (left + right) / 2;

                if (arr[mid] <= num) {
                        ans = mid;
                        left = mid + 1;
                }
                else {
                        right = mid - 1;
                }
        }
        return ans;
}

void solve() {
        for (int i = 0; i < m; i++) {
                int first, second;
                cin >> first >> second;
                int l = binarySearchGreater(first);
                int r = binarySearchLess(second);

                if (l == -1 || r == -1) {
                        cout << 0 << "\n";
                        continue;
                }
                cout << r -l + 1<< "\n";
        }
}

void input() {
        cin >> n;
        
        for (int i = 0; i < n; i++) {
                cin >> arr[i];
        }

        cin >> m;
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        input();
        solve();

}