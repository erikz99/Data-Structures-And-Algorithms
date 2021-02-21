#include <iostream>
#include <cmath>
using namespace std;

long long arr[1000010], spTable[1000010][24], logs[1000010];
int n,m;

void input() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
}

void build() {
    spTable[0][0] = arr[0];
    logs[0] = -1;

    for (int i=1; i<=n; i++) {
        logs[i] = logs[i/2]+1;
        spTable[i][0] = arr[i];
    }

    for (int j=1; j<=23; j++) {
        for (int i=0; i+(1<<j)-1<n; i++) {
            int v1 = spTable[i][j-1];
            int v2 = spTable[i+(1<<(j-1))][j-1];
            spTable[i][j] = v1 < v2 ? v1 : v2;
        }
    }
}

long long rmq(int from ,int to) {
    int log = logs[to-from+1];
    int v1 = spTable[from][log];
    int v2 = spTable[to-(1<<log)+1][log];
    return v1 < v2 ? v1 : v2;
}

void process() {
    for (int i=0; i<m; i++) {
        int op;
        cin >> op;
        if (op==1) {
            int from, to;
            cin >> from >> to;
            cout << rmq(from,to) << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    build();
    process();
}