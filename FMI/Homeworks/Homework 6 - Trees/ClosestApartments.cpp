#include <cmath>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct apartment
{
    double distance;
    long long x, y;

    apartment(long long x = 0, long long y = 0)
    {
        this->x = x;
        this->y = y;
        this->distance = x * x + y * y;
    }

     bool operator <(const apartment& obj)
    {
        if (this->distance == obj.distance)
        {
            if (this->x==obj.x) return this->y < obj.y;
            return this->x<obj.x;
        }
        else
        {
            return this->distance < obj.distance;
        }
    }

    bool operator >(const apartment& obj)
    {
        if (this->distance == obj.distance)
        {
            if (this->x==obj.x) return this->y > obj.y;
            return this->x>obj.x;
        }
        else
        {
            return this->distance > obj.distance;
        }
    }
};


void heapify(vector <apartment> &ap, long long &n, long long i)
{
    long long l = 2 * i + 1;
    long long r = 2 * i + 2;

    long long largest = i;

    if (l < n && ap[largest] < ap[l])
    {
        largest = l;
    }

    if (r < n && ap[largest] < ap[r])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(ap[largest], ap[i]);
        heapify(ap, n, largest);
    }
}

void heapSort(vector <apartment> &ap, long long &n, long long k)
{
    for (long long i = n / 2 - 1; i >= 0; i--)
    {
        heapify(ap, n, i);
    }

    for (long long i = n - 1; i >= 0; i--)
    {
        swap(ap[i], ap[0]);
        heapify(ap, i, 0);
    }

}

void solve() {
    long long n, k;
    cin >> n >> k;
    vector <apartment> ap;
    int x,y;
    cin >> x >> y;
    ap.push_back(apartment(x,y));
    double maxDistance = ap[0].distance;
    for (int i = 1; i < k; i++)
    {
        int x,y;
        cin >> x >> y;
        ap.push_back(apartment(x,y));
        if (ap[i].distance>maxDistance) {
            maxDistance = ap[i].distance;
        }
    }
    vector <apartment> base = ap;
    int maxElementIndex = k-1;
    heapSort(base, k, 0);
    for (int i=k; i<n; i++)
    {
        int x,y;
        cin >> x >> y;
        apartment currentElement = apartment(x,y);
        if (base[k-1] > currentElement) {
            base[k-1] = currentElement;
        }
        if (base[k-1] < base [k-2]) {
            heapSort(base, k, 0);
        }
    }
    for (long long i = 0; i < k; i++)
    {
        cout << base[i].x << " " << base[i].y << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
