#include <iostream>
#include <vector>
using namespace std;

class event
{
public:
    int Start;
    int End;
    event(int s=0, int e=0)
    {
        this->Start = s;
        this->End = e;
    }
    bool operator>(const event& obj)
    {
        return this->End>obj.End;
    }
    bool operator<(const event& obj)
    {
        return this->End<obj.End;
    }
};

event events[1000010];
int n;

void Merge(int l, int m, int r)
{
    int n1= m-l+1;
    int n2=r-m;
    vector <event> vect1;
    vector <event> vect2;
    for (int i=0; i<n1; i++)
    {
        vect1.push_back(events[l+i]);
    }
    for (int i=0; i<n2; i++)
    {
        vect2.push_back(events[m+1+i]);
    }
    int i=0, j=0, k=l;
    while (i<n1 && j<n2)
    {
        if (vect1[i]>vect2[j])
        {
            events[k] = vect2[j];
            j++;
        }
        else
        {
            events[k] = vect1[i];
            i++;
        }
        k++;
    }
    while (i<n1)
    {
        events[k]=vect1[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        events[k] = vect2[j];
        j++;
        k++;
    }
}

void mergeSort(int l, int r)
{
    if (l<r)
    {
        int m = (l+r)/2;
        mergeSort(l,m);
        mergeSort(m+1,r);
        Merge(l,m,r);
    }
}

bool init() {
    cin >> n;
    if (n==0) {
        return false;
    }
    
    for (int i=0; i<n; i++)
    {
        int start, duration;
        cin >> start >> duration;
        events[i] = {start,start+duration};
    }
    return true;
}

void solve() {
    mergeSort(0,n-1);
    int currentTime=events[0].End;
    int counter =1;
    for (int i=1; i<n; i++)
    {
        if (events[i].Start>=currentTime)
        {
            currentTime = events[i].End;
            counter++;
        }
    }
    cout << counter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    if (!init()) {
        cout << 0;
    }
    else {
        solve();
    }
}