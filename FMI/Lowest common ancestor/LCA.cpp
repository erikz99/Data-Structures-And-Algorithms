#include <iostream>
#include <vector>
using namespace std;

void eulerDfsUtill(vector <int> &first, vector <int> &euler,vector <int> &height, int v, vector <int> &used, vector < vector <int> > &adj, int n) {
    used[v] = true;
    first[v] = euler.size();
    euler.push_back(v);
    for (auto i = adj[v].begin(); i!=adj[v].end(); i++) {
        if (!used[*i]) {
            height[*i] = height[v] + 1;
            eulerDfsUtill(first,euler,height,*i,used,adj,n);
            euler.push_back(v);
        }
    }
}

void eulerDfs(vector <int> &first, vector <int> &euler, vector <int> &height, vector < vector <int> > &adj, int n) {
    vector <int> used(n+1,false);
    height[1] = 1;
    eulerDfsUtill(first,euler,height,1,used,adj,n);
}

void answer(vector <int> &first, vector < pair <int, int> > &queries, vector <int> &height, vector <int> &euler, int n) {
    vector <int> logs(euler.size()+1);
    logs[0] = -1;

    for (size_t i=1; i<=euler.size(); i++) {
        logs[i] = logs[i/2]+1;
    }

    int p = euler.size();
    int q = logs[p]+1;
    vector < vector <int> > spTable(p);
    for (int i=0; i<p; i++) {
        spTable[i] = vector <int>(q);
        spTable[i][0] = euler[i];
    }

    for (int j=1; j<q; j++) {
        for (int i=0; i+(1<<j)-1<p; i++) {
            int v1 = spTable[i][j-1];
            int v2 = spTable[i+(1<<(j-1))][j-1];
            spTable[i][j] = height[v1] < height[v2] ? v1 : v2;
        }
    }

    for (pair <int,int> pr: queries) {
        int left = first[pr.first];
        int right = first[pr.second];

        if (left > right) {
            swap(left,right);
        }

        int log = logs[right-left+1];
        int v1 = spTable[left][log];
        int v2 = spTable[right - (1<<log)+1][log];
        
        int res = v1 < v2 ? v1 : v2;
        cout << res << "\n";
    }

}

void input() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int n;
        cin >> n;

        vector < vector <int> > adj(n+1);
        vector <int> height(n+1);
        vector <int> euler;
        vector <int> first(n+1);

        for (int k=1; k<=n; k++) {
            int m;
            cin >> m;
            
            if (m==0) {
                continue;
            }

            for (int j=0; j<m; j++) {
                int child;
                cin >> child;

                adj[k].push_back(child);
                adj[child].push_back(k);
            }
        }

        eulerDfs(first,euler,height,adj,n);

        int q;
        cin >> q;

        vector < pair <int,int> > queries(q);

        for (int l=0; l<q; l++) {
            int first, second;
            cin >> first >> second;
            queries[l].first = first;
            queries[l].second = second;
        }

        cout << "Case " << i+1 << ":" << "\n"; 
        answer(first,queries,height,euler,n);

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
}