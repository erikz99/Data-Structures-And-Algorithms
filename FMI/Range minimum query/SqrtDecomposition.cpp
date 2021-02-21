#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[1000010], ans[1010];
int n,m,len;

void input() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
}

void build() {
    len = sqrt(n) + 1;
    fill(ans,ans+len,INT_MAX);
    for (int i=0; i<n; i++) {
        ans[i/len] = min(ans[i/len],arr[i]);
    }
}

int getMin(int from, int to) {
    int answer = INT_MAX;

    while (from<=to) {
        if (from%len==0 && from+len-1<to) {
            answer = min(answer,ans[from/len]);
            from+=len;
        }
        else {
            answer = min(answer,arr[from]);
            from++;
        }
    }

    return answer;
}

void update(int index, int add) {
    arr[index]+=add;

    int r = (index/len)*len;
    ans[r/len] = INT_MAX;

    for (int i=0; i<len; i++) {
        ans[r/len] = min(ans[r/len],arr[r]);
        r++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    build();

    for (int i=0; i<m; i++) {
        int num;
        cin >> num;

        if (num==1) {
            int from, to;
            cin >> from >> to;
            cout << getMin(from,to) << endl;
        }

        else if (num==2) {
            int index, add;
            cin >> index >> add;
            update(index,add);
        }
    }
}