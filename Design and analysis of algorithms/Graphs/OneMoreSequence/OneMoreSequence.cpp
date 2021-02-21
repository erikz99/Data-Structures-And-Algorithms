#include iostream
#include queue
#include cmath
using namespace std;

int a, b;

int reverse(int num) {
        int reversedNumber = 0, remainder;

        while (num != 0) {
                remainder = num % 10;
                reversedNumber = reversedNumber  10 + remainder;
                num = 10;
        }

        return reversedNumber;
}

void input() {
        cin  a  b;

}

void solve() {
        vector int dist(1000010);
        vector int used(1000010,false);
        queue int q;
        q.push(a);
        dist[a] = 1;
        int cnt = 0;
        while (!q.empty()) {
                int num = q.front();
                q.pop();
                if (num == b) {
                        break;
                }

                int n1 = (num + 1) % 1000007;
                if (!used[n1]) {
                        q.push(n1);
                        used[n1] = true;
                        dist[n1] = dist[num] + 1;
                }

                int rev = reverse(num) % 1000007;
                if (!used[rev]) {
                        used[rev] = true;
                        q.push(rev);
                        dist[rev] = dist[num] + 1;
                }
        }
        cout  dist[b];
}

int main() {
        ios_basesync_with_stdio(false);
        cin.tie(nullptr);

        input();
        solve();
}