#include <bits/stdc++.h>
using namespace std;

struct work {
    long long time;
    long long lines;
    long long index;
    
    bool operator<(const work& w) {
        return time < w.time;
    }
};

struct cmp {
    bool operator() (const work& w1, const work& w2) {
        if (w1.lines>w2.lines) {
            return true;
        }
        return false;
    }
};

void solve() {
    long long n;
    cin >> n;
    vector < work > v(n);
    for (long long i=0; i<n; i++) {
        long long t, l;
        cin >> t >> l;
        v[i].time = t;
        v[i].lines = l;
        v[i].index = i;
    }
    sort(v.begin(),v.end());
    priority_queue <work, vector <work>, cmp> pq;
    long long time = v[0].time;
    long long i = 0;
    vector <double> wait(n,0);
    while (i<n) {
        if (v[i].time<=time) {
            pq.push(v[i]);
            i++;
            continue;
        }
        if (!pq.empty()) {
            work w = pq.top();
            wait[w.index] = time-w.time+w.lines;
            time+=w.lines;
            pq.pop();
        }
        else {
            time = v[i].time;
        }
    }
    while (!pq.empty()) {
        work w = pq.top();
        wait[w.index] = time-w.time+w.lines;
        time+=w.lines;
        pq.pop();
    }
    double ans = 0;
    for (int i=0; i<n; i++) {
        ans+=wait[i]/n;
    }
    long long a = ans;
    cout << a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  	
    solve();
 
    return 0;
}