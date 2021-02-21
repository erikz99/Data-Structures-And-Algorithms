#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long n;
string word1, word2;

void init() {
    cin >> n;
    cin >> word1 >> word2;
}

bool isPermutation(string str1, string str2, int n)
{
    if (str1.length() != str2.length()) {
        return false;
    }
    
    vector <int> counterStr1(26,0);
    vector <int> counterStr2(26,0);

    for (int i=0; i<n; i++)
    {
        counterStr1[str1[i]-((int)'a')]++;
        counterStr2[str2[i]-((int)'a')]++;
    }
    
    for (int i=0; i<26; i++) {
        if (counterStr1[i] != counterStr2[i]) {
            return false;
        }
    }
    
    return true;
}

void solve() {
    if (isPermutation(word1,word2,n)) {
        cout << "yes";
    } else {
        cout << "no";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    solve();
}