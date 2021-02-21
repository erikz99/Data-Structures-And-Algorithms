#include <iostream>
using namespace std;

int heights[100010];
int n;

long long Merge(int arr[], int l, int m, int r)
{
    long long invCount =0;
    int n1 = m-l+1;
    int n2 = r-m;
    int a1[n1];
    int a2[n2];
    for (int i=0; i<n1; i++)
    {
        a1[i] = arr[i+l];
    }
    for (int j=0; j<n2; j++)
    {
        a2[j] = arr[m+1+j];
    }
    int i=0,j=0,k=l;
    while (i<n1 && j<n2)
    {
        if (a1[i]>a2[j])
        {
            arr[k]=a2[j];
            j++;
            invCount+=m+j-k;

        }
        else
        {
            arr[k] = a1[i];
            i++;
        }
        k++;
    }
    while (i<n1)
    {
        arr[k] = a1[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        arr[k] = a2[j];
        j++;
        k++;
    }
    return invCount;
}

long long mergeSort(int arr[], int l, int r)
{
    long long invCount=0;
    if (l<r)
    {
        int m = (l+r)/2;
        invCount = mergeSort(arr,l,m);
        invCount+=mergeSort(arr, m+1, r);
        invCount+=Merge(arr, l, m, r);
    }
    return invCount;
}

void init() {
    cin >> n;
    for (int i=0; i<n; i++)
    {
        cin >> heights[i];
    }
}

void solve() {
    if (n==0) {
        cout << 0;
    }
    else {
        cout << mergeSort(heights, 0, n-1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    solve();
}
