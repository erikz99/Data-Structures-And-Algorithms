#include <iostream>
#include <fstream>
#include <unordered_map>
#include <chrono>
using namespace std;

struct trieNode {
    int cnt;
    bool end;
    char c;
    unordered_map <char, trieNode*> m;

    trieNode(char c = '\0', bool end = false, int cnt = 0)
        : c(c), end(end), cnt(cnt) {}
};

class Trie {
public:
    Trie() {
        root = new trieNode;
    }

    bool inputDict() {
        string fileName = "dict.txt";

        ifstream in(fileName);

        if (!in) {
            return false;
        }

        string s;

        while (in >> s) {
            addString(s);
        }

        in.close();

        return true;
    }

    void run() {
        if (!inputDict()) {
            return;
        }
        
        string fileName = "input.txt";
        ifstream in(fileName);

        if (!in) {
            return;
        }

        fileName = "output.txt";
        ofstream out(fileName);

        if (!out) {
            return;
        }

        string word;
        int cnt = 0;
        while (in >> word) {
            checkString(word, out);
        }

        out.close();
    }

private:
    trieNode* root;

    void addString(string& s) {
        trieNode* curr = root;
        for (char c : s) {
            if (curr->m.find(c) == curr->m.end()) {
                curr->m[c] = new trieNode(c);
            }

            curr = curr->m[c];
        }

        curr->cnt++;
        curr->end = true;
    }

    void autoComplete(trieNode* node, string word, ofstream& out) {
       
        if (node->end) {
            out << word << " ";
        }

        for (auto it = node->m.begin(); it != node->m.end(); it++) {
            char c = it->first;
            
            word.push_back(c);
            autoComplete(it->second, word, out);
            word.pop_back();
        }
    }

    void autoCorrect(string& word, ofstream& out) {
        int len = word.length();

        // Deletion
        for (int i = 0; i < len; i++) {
            string newString = word.substr(0, i) + word.substr(i + 1);
            trieNode* node = searchString(newString);
            if (node && node->end) {
                out << newString << " ";
            }
        }

        // Swap of adjacent letters
        for (int i = 0; i < len - 1; i++) {
            string newString = word.substr(0, i) + word.substr(i + 1, 1) + word.substr(i, 1) + word.substr(i + 2);
            trieNode* node = searchString(newString);
            if (node && node->end) {
                out << newString << " ";
            }
        }

        // Replacements
        for (int i = 0; i < len; i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                string newString = word.substr(0, i) + c + word.substr(i + 1);
                trieNode* node = searchString(newString);
                if (node && node->end) {
                    out << newString << " ";
                }
            }
            for (char c = 'A'; c <= 'Z'; c++) {
                string newString = word.substr(0, i) + c + word.substr(i + 1);
                trieNode* node = searchString(newString);
                if (node && node->end) {
                    out << newString << " ";
                }
            }
        }

        // Insertions
        for (int i = 0; i <= len; i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                string newString = word.substr(0, i) + c + word.substr(i);
                trieNode* node = searchString(newString);
                if (node && node->end) {
                    out << newString << " ";
                }
            }
            for (char c = 'A'; c <= 'Z'; c++) {
                string newString = word.substr(0, i) + c + word.substr(i);
                trieNode* node = searchString(newString);
                if (node && node->end) {
                    out << newString << " ";
                }
            }
        }

    }

    trieNode* searchString(string word) {
        trieNode* curr = root;

        for (char c : word) {
            if (curr->m.find(c) != curr->m.end()) {
                curr = curr->m[c];
            }
            else {
                return nullptr;
            }
        }

        return curr;
    }

    void checkString(string& word, ofstream& out) {
        trieNode* node = searchString(word);

        if (node==nullptr) {
            autoCorrect(word, out);
        }
        else {
            autoComplete(node, word, out);
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = chrono::high_resolution_clock::now();

    Trie trie;
    trie.run();

    auto end = chrono::high_resolution_clock::now();
    
    double time_taken =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    cout << "Time taken by program is : "  << time_taken << " sec" << endl;
    return 0;
    
}