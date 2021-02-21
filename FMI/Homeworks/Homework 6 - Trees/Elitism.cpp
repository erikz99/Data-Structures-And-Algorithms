#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;


class minHeap
{

public:
    int heapSize;
private:
    vector<long long> arr;

    int parent(int idx)
    {
        return (idx - 1) / 2;
    }

    int leftChild(int idx)
    {
        return idx * 2 + 1;
    }

    int rightChild(int idx)
    {
        return idx * 2 + 2;
    }

    bool hasLeftChild(int idx)
    {
        return idx * 2 + 1 < heapSize;
    }

    bool hasRightChild(int idx)
    {
        return idx * 2 + 2 < heapSize;
    }

    void pullUp(int idx)
    {
        if (idx == 0)
            return;
        if (arr[idx] < arr[parent(idx)])
        {
            swap(arr[idx], arr[parent(idx)]);
            pullUp(parent(idx));
        }
    }

    void heapify(int i)
    {
        int l = leftChild(i);
        int r = rightChild(i);
        int smallest = i;
        if (l < heapSize && arr[l] < arr[i])
            smallest = l;
        if (r < heapSize && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

public:
    minHeap()
    {
        heapSize = 0;
    }

    minHeap(long long* arr, int n)
    {
        heapSize = n;
        for (int i = 0;i < n;++i)
        {
            this->arr.push_back(arr[i]);
        }
        for (int i = n / 2 - 1;i >= 0;--i)
        {
            heapify(i);
        }
    }

    void push(long long x)
    {
        arr.push_back(x);
        pullUp(heapSize++);
    }

    int top()
    {
        return arr[0];
    }

    void pop()
    {
        swap(arr[0], arr[--heapSize]);
        heapify(0);
        arr.pop_back();
    }
};

class maxHeap
{
public:
    int heapSize;

private:
    vector<long long> arr;

    int parent(int idx)
    {
        return (idx - 1) / 2;
    }

    int leftChild(int idx)
    {
        return idx * 2 + 1;
    }

    int rightChild(int idx)
    {
        return idx * 2 + 2;
    }

    bool hasLeftChild(int idx)
    {
        return idx * 2 + 1 < heapSize;
    }

    bool hasRightChild(int idx)
    {
        return idx * 2 + 2 < heapSize;
    }

    void pullUp(int idx)
    {
        if (idx == 0)
            return;
        if (arr[idx] > arr[parent(idx)])
        {
            swap(arr[idx], arr[parent(idx)]);
            pullUp(parent(idx));
        }
    }

    void heapify(int i)
    {
        int l = leftChild(i);
        int r = rightChild(i);
        int largest = i;
        if (l < heapSize && arr[l] > arr[i])
            largest = l;
        if (r < heapSize && arr[r] > arr[largest])
            largest = r;
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

public:
    maxHeap()
    {
        heapSize = 0;
    }

    maxHeap(long long* arr, int n)
    {
        heapSize = n;
        for (int i = 0;i < n;++i)
        {
            this->arr.push_back(arr[i]);
        }
        for (int i = n / 2 - 1;i >= 0;--i)
        {
            heapify(i);
        }
    }

    void push(long long x)
    {
        arr.push_back(x);
        pullUp(heapSize++);
    }

    int top()
    {
        return arr[0];
    }

    void pop()
    {
        swap(arr[0], arr[--heapSize]);
        arr.pop_back();
        heapify(0);
    }
};

void solve() {
    int n;
    scanf ("%i",&n);

    maxHeap left;
    minHeap right;
    cout << setprecision(1);
    cout << fixed;

    for (int i = 0; i < n; i++) {
        long long num;
        scanf ("%i",&num);

        if (left.heapSize == 0 || num <= left.top()) {
            left.push(num);
            while (left.heapSize - right.heapSize > 1)
            {
                right.push(left.top());
                left.pop();
            }

        }
        else {
            right.push(num);
            while (right.heapSize - left.heapSize > 1)
            {
                left.push(right.top());
                right.pop();
            }

        };

        double m = 0;
        if (left.heapSize > right.heapSize) {
            m = left.top();
        }
        else if (left.heapSize < right.heapSize) {
            m = right.top();
        }
        else {
            m = (left.top() + right.top()) / 2.0;
        }

        printf("%.1f", m);
        printf("\n");
    }

}

int main() {
    solve();
    
    return 0;
}