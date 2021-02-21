#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


struct folder
{
    int num;
    string name;
    folder* parent;
    
    folder(string name = "", folder* parent = NULL)
    {
        this->name = name;
        this->parent = parent;
    }
    
    bool operator<(const folder &obj)
    {
        return this->name < obj.name;
    }
    
    bool operator>(const folder &obj)
    {
        return this->name > obj.name;
    }
};

struct sortByName
{
    bool operator()(folder* x, folder* y)
    {
        return x->name < y->name;
    }
};

void solve() {
    int n;
    cin >> n;
    unordered_map < folder*, vector<folder*> > dirs;
    folder* currentFolder = new folder("/");
    for (int i=0; i<n; i++)
    {
        string op;
        cin >> op;
        if (op == "mkdir")
        {
            string name;
            cin >> name;
            bool is = false;
            for (int i=0; i<dirs[currentFolder].size(); i++)
            {
                if (dirs[currentFolder][i]->name == name)
                {
                    is = true;
                    break;
                }
            }
            if (!is)
            {
                folder *f = new folder(name, currentFolder);
                dirs[currentFolder].push_back(f);
            }
            else 
            {
                cout << "Directory already exists" << endl;
            }
        
        }
        else if (op == "ls")
        {
            sort(dirs[currentFolder].begin(), dirs[currentFolder].end(), sortByName());
            for (int i =0; i<dirs[currentFolder].size(); i++)
            {
                cout << dirs[currentFolder][i]->name << " ";
            }
            cout << "\n";
        }
        else if (op == "pwd")
        {
            string s = currentFolder->name;
            if (s=="/") cout << s << endl;
            else
            {
                folder* temp = currentFolder;
                while (temp->parent)
                {
                    temp = temp->parent;
                    s.insert(0,"/");
                    if (temp->name!="/")
                    {
                        s.insert(0,temp->name);
                    }
                }
                cout << s << "/" << "\n";
            }

        }
        else 
        {
            string name;
            cin >> name;

            if (name=="..")
            {   
                if (currentFolder->parent) currentFolder = currentFolder->parent;
                else cout << "No such directory" << endl;
            }
            else 
            {
                bool is = false;
                for (int i =0; i<dirs[currentFolder].size(); i++){
                    if (dirs[currentFolder][i]->name==name)
                    {
                        currentFolder = dirs[currentFolder][i];
                        is = true;
                        break;
                    }
                }
                if (!is) cout << "No such directory" << endl;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
 