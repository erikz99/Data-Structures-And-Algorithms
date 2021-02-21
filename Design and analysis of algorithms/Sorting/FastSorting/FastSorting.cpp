#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
using namespace std;

int heap[1000000];
int n = 0;

void siftUp(int i) {
    int parent = (i - 1) / 2;
    while (parent >= 0 && (heap[parent] > heap[i])) {
        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;
        i = parent;
        parent = (i - 1) / 2;
    }
}

void siftDown(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && right >= n) {
        if (heap[i] > heap[left]) {
            int temp = heap[left];
            heap[left] = heap[i];
            heap[i] = temp;
            siftDown(left);
        }
    }
    else if (left < n && right <n) {
        if (heap[left] <= heap[right] && heap[i] > heap[left]) {
            int temp = heap[left];
            heap[left] = heap[i];
            heap[i] = temp;
            siftDown(left);
        }
        else if (heap[right] <= heap[left] && heap[i] > heap[right]) {
            int temp = heap[right];
            heap[right] = heap[i];
            heap[i] = temp;
            siftDown(right);
        }
    }
}

void add(int data) {
    heap[n] = data;
    if (n > 0) {
        siftUp(n);
    }
    n++;
}

void remove() {

    if (n > 0) {
        heap[0] = heap[n - 1];
        n--;
        siftDown(0);
    }
}

void peek() {
    if (n > 0) {
        printf("%d ", heap[0]);
    }
    else {
        printf("Not available\n");
    }
}

void solve() {
	int numOfElems,num;
    scanf("%d", &numOfElems);
    for (int i = 0; i < numOfElems; i++) {
        scanf("%d", &num);
        add(num);
    }
    for (int i = 0;i < numOfElems; i++) {
        peek();
        remove();
    }
}

int main() {
    solve();
}