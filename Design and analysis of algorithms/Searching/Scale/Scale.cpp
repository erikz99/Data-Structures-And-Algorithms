#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, q;

struct student {
    string name;
    int fn;
    int points;

    bool operator<(const student& student) {
        if (points == student.points) {
            return fn < student.fn;
        }
        return points < student.points;
    }
};

student arr[100010];

int binarySearch(int p) {
    int l = 0, r = n - 1, ans = -1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (arr[mid].points >= p) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }

    return ans;
}

void input() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        string name;
        int fn, points;

        cin >> name;
        cin >> fn;
        cin >> points;

        arr[i] = { name,fn,points };
    }
}

void solve() {
    sort(arr, arr + n);

    int p;
    for (int i = 0; i < q; i++) {
        cin >> p;
        int index = binarySearch(p);
        cout << arr[index].name << " " << arr[index].fn << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solve();
}