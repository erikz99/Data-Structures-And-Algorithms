#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    unordered_map <long long, long long> keysInAvailability;
    vector <long long> keysInRooms;
    for (long long i = 0; i<n-1; i++)
    {
        long long key;
        cin >> key;
        keysInRooms.push_back(key);
    }
    vector <long long> keysForRooms;
    for (long long i=0; i<n-1; i++)
    {
        long long key;
        cin >> key;
        keysForRooms.push_back(key);
    }
    long long minKeys = 0;
    keysInAvailability[keysInRooms[0]] = 1;
    for (long long i =1; i<=n-1; i++)
    {
        if (keysInAvailability.find(keysForRooms[i-1]) == keysInAvailability.end() || keysInAvailability[keysForRooms[i-1]] == 0)
        {
            minKeys++;
        }
        else
        {
            keysInAvailability[keysForRooms[i-1]]--;
        }
        if (keysInAvailability.find(keysInRooms[i]) == keysInAvailability.end()) keysInAvailability[keysInRooms[i]] = 1;
        else keysInAvailability[keysInRooms[i]]++;
    }
    cout << minKeys;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}
