#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int n, x;
int platform[200010];

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
int partition (int low, int high)  
{  
    int pivot = platform[high];
    int i = (low - 1);  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        if (platform[j] < pivot)  
        {  
            i++;
            swap(&platform[i], &platform[j]);  
        }  
    }  
    swap(&platform[i + 1], &platform[high]);  
    return (i + 1);  
}  
  
void quickSort(int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(low, high);  
  
        quickSort(low, pi - 1);  
        quickSort(pi + 1, high);  
    }  
}  

int blaster(int m, int currentStep)
{
    int maximum = platform[m-1]-currentStep;
    
    if (maximum<=0)
    {
        return 0;
    }
    else
    {
        int counter =0;
        for (int i=m-1; i>=0; i--)
        {
            if (platform[i]-currentStep==maximum)
            {
                counter++;
            }
            else
            {
                break;
            }
        }
        currentStep+=x;
        return 1+blaster(m-counter, currentStep);
    }
}

void init() {
    cin >> n >> x;
    for (int i=0; i<n; i++)
    {
        cin >> platform[i];
    }
}

void solve() {
    quickSort(0, n - 1); 
    printf("%d",blaster(n,0));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();
    solve();
}
