#include <unordered_map>
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    unordered_map <string, int> dict;
    for (int i=0; i<n; i++)
    {
        char word[20];
        cin >> word;
        string w(word,0,1);
        for (int i=0; i<strlen(word); i++)
        {
            if (dict.find(w) == dict.end()) dict[w] = 1;
            else dict[w]++;
            w.push_back(word[i+1]);
        }
    }
    for (int i=0; i<q; i++)
    {
        char pref[20];
        cin >> pref;
        if (dict.find(pref) == dict.end())
        {
            printf("%d",0);
            printf("%c", '\n');
        }
        else
        {
            printf("%d",dict[pref]);
            printf("%c", '\n');
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
