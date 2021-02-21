#include <iostream>
#include <algorithm>
using namespace std;

struct sticker {
        int start, end;

        bool operator<(const sticker& sticker) {
                return start < sticker.start;
        }
};

int n, m;
sticker arr[1000010];

void input() {
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
                int start, end;
                cin >> start >> end;
                arr[i] = { start,end };
        }
}

void solve() {
        sort(arr, arr + m);

        int covered = arr[0].end - arr[0].start + 1;
        int last = arr[0].end;
        for (int i = 1; i < m; i++) {
                int start = arr[i].start;
                int end = arr[i].end;

                if (start < last) {
                        if (end > last) {
                                covered += end - last;
                                last = end;
                        }
                }
                else if (start==last) {
                        covered += end - start;
                        last = end;
                }
                else {
                        covered += end - start + 1;
                        last = end;
                }
        }

        cout << covered;
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        input();
        solve();
}