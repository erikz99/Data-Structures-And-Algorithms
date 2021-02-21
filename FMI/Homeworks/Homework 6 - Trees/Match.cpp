#include <iostream>
#include <unordered_map>
using namespace std;

struct trieNode {
    bool end;
    char c;
    unordered_map <char, trieNode*> m;

    trieNode(char c = '\0') 
    : c(c) {}
};

class Trie {
public:
    trieNode* root;
    int n,q;

    Trie() {
        root = new trieNode;
    }

    void addString(string& s) {
        trieNode* curr = root;
        for (char c: s) {
            if (curr->m.find(c) == curr->m.end()) {
                curr->m[c] = new trieNode(c);
            }
            
            curr = curr->m[c];
        }

        curr->end = true;
    }

    bool checkString(string& s) {
        trieNode* curr = root; 

        for (char c: s) {
            if (curr->m.find(c) != curr->m.end()) {
                curr = curr->m[c];
            } else {
                return false;
            }
        }

        if (curr->end) {
            return true;
        }
        return false;
    }

    void input() {
        cin >> n;

        string s;
        for (int i=0; i<n; i++) {
            cin >> s;
            addString(s);
        }
        
        cin >> q;
        for (int i=0; i<q; i++) {
            cin >> s;
            if (checkString(s)) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }
};

void solve() {
    Trie trie;
    trie.input();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

}