#include <iostream>
#include <algorithm>
using namespace std;

long long n, k;
long long hotels[100010];

bool isOk(int d) {
    int cnt = 1;
    long long  last = hotels[0];

    for (int i = 1; i < n; i++) {
        if (hotels[i] - last >= d) {
            last = hotels[i];
            cnt++;
        }
    }

    if (cnt>=k) {
        return true;
    }
    return false;
}

long long binarySearch() {
    long long  l = 0, r = hotels[n-1], ans = -1;

    while (l <= r) {
        long long  mid = (l + r) / 2;

        if (isOk(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else {
            r = mid - 1;
        }
    }

    return ans;
}

void input() {
    scanf("%lld",&n);
    scanf("%lld",&k);

    for (int i = 0; i < n; i++) {
        scanf("%lld",&hotels[i]);
    }
}

void solve() {
    sort(hotels, hotels + n);
    printf("%lld",binarySearch());
}

int main() {
    input();
    solve();
}