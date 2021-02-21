#include<cstdio>
#include<iostream>

using namespace std;

int arr[int(1e6)+9],numberOfElements,n;

void siftUp(int ind){
    if(ind==0)return;

    int parent = (ind-1)/2;///the index of the parent

    if(arr[ind] < arr[parent]){
        swap(arr[ind],arr[parent]);
        siftUp(parent);
    }
}

void siftDown(int ind){
    int left = ind*2+1, right = ind*2+2;///indexes of the children

    if(left>=numberOfElements)return;

    if(arr[left] > arr[right] && arr[ind] > arr[right]){
        swap(arr[right],arr[ind]);
        siftDown(right);
    }
    else if(arr[left] < arr[ind]){
        swap(arr[left],arr[ind]);
        siftDown(left);
    }
}

void addElement(int element){
    arr[numberOfElements]=element;
    siftUp(numberOfElements++);
}

void removeElement(){
    arr[0]=arr[--numberOfElements];
    siftDown(0);
}

int top(){
    return arr[0];
}

void init(){
    int temp;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        addElement(temp);
    }
}

void printSorted(){
    while(numberOfElements){
        printf("%d ",top());
        removeElement();
    }
    printf("\n");
}

int main(){
    init();
    printSorted();
}
