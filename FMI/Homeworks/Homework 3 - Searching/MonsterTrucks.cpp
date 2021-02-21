#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct truck
{
    int position;
    int monsters;

    truck(int position=0, int monsters=0)
    {
        this->position = position;
        this->monsters = monsters;
    }

    bool operator>(const truck& obj)
    {
        return this->position > obj.position;
    }

    bool operator<(const truck& obj)
    {
        return this->position < obj.position;
    }
};

truck trucks[50010];
int n;

long long monstersNecessary(int position)
{
    long long monsters = 0;
    for (int i = 0; i < n; i++)
    {
        monsters += (fabs(trucks[i].position - position)) * trucks[i].monsters;

    }
    return monsters;
}

long long minMonsters()
{
    long long left = trucks[0].position, right = trucks[n - 1].position;
    while (left < right)
    {
        long long mid1 = left + (right - left) / 3;
        long long mid2 = right - (right - left) / 3;
        if (monstersNecessary(mid1) > monstersNecessary(mid2))
        {
            left = mid1 + 1;
        }
        else
        {
            right = mid2 - 1;
        }
    }
    return monstersNecessary(left);
}

void init() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int pos, mon;
        cin >> pos >> mon;
        trucks[i] = truck(pos, mon);
    }
}

void solve() {
    if (n == 0)
    {
        cout << 0;
        return;
    }
    
    sort(trucks, trucks +n);
    cout << minMonsters();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    solve();
}