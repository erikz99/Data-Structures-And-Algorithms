#include <iostream>
#include <queue>
using namespace std;

int used[1000][1000] = {};
int counter = 1;

struct apple
{
    int x;
    int y;
};

bool valid(int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return 0;
    }
    return 1;
}

int bfs(int i, int j, int n, int m, int t)
{
    apple* first = new apple;
    first->x = i;
    first->y = j;
    int number = 0;
    int level = -1;
    queue <apple*> apples;
    apples.push(first);
    apples.push(NULL);
    while (!apples.empty())
    {
        apple* current = apples.front();
        if (current == NULL)
        {
            level++;
            apples.pop();
            apples.push(NULL);
            if (apples.front() == NULL) break;
            else continue;
        }
        if (level == t)
        {
            break;
        }
        if (used[current->x][current->y] == 0 || used[current->x][current->y]<counter)
        {
            if (used[current->x][current->y] == 0) number++;
            if (valid(current->x, current->y - 1, n, m))
            {
                apple* curr = new apple;
                curr->x = current->x;
                curr->y = current->y - 1;
                apples.push(curr);
            }
            if (valid(current->x, current->y + 1, n, m))
            {
                apple* curr = new apple;
                curr->x = current->x;
                curr->y = current->y + 1;
                apples.push(curr);
            }
            if (valid(current->x - 1, current->y, n, m))
            {
                apple* curr = new apple;;
                curr->x = current->x - 1;
                curr->y = current->y;
                apples.push(curr);
            }
            if (valid(current->x + 1, current->y, n, m))
            {
                apple* curr = new apple;
                curr->x = current->x + 1;
                curr->y = current->y;
                apples.push(curr);
            }
            used[current->x][current->y]++;
        }
        apples.pop();
    }
    return number;
}

int n,m,t;

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    int sum = 0;
    int x, y;
    while (cin >> x >> y)
    {

        sum += bfs(n - x, y - 1, n, m, t);
        counter++;
    }
    cout << n * m - sum << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}