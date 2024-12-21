#include <iostream>
#include <vector>
using namespace std;

void getElements(vector<int> &arr){
    cout<<"enter the size of heap"<<endl;
    int n;
    cin>>n;
    cout<<"enter heap elements"<<endl;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }
}

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

void heapify(vector<int> &arr, int &index, int &heapSize){
    int leftIndex=2*index;
    int rightIndex=leftIndex+1;
    int greatestIndex=index; //initially
    if(leftIndex<=heapSize and (arr[leftIndex-1]>arr[index-1])){
        greatestIndex=leftIndex;
    } 
    if(rightIndex<=heapSize and (arr[rightIndex-1]>arr[greatestIndex-1])){
        greatestIndex=rightIndex;
    } 
    swap(arr[index-1],arr[greatestIndex-1]);
    if(greatestIndex!=index) heapify(arr, greatestIndex, heapSize); //otherwise, no swapping is done and no need for heapify
}

void buildHeap(vector<int> &arr, int &heapSize){
    if(heapSize==0 or heapSize==1) return;
    // 1 2 3 4 5 1-> 2 3 2->4 5 1->5 3 5->4 2
    // start from the last non leaf elements and start building heap from there

    int nonLeaf=heapSize/2;
    while(nonLeaf){
        heapify(arr, nonLeaf, heapSize);
        nonLeaf--;
    }
}

void heapSort(vector<int> &arr, int &heapSize){
    if(heapSize==0) return;
    buildHeap(arr, heapSize); //get the maximum by building heap
    swap(arr[0], arr[heapSize-1]); //swap the max element with the last element in the heap
    heapSize-=1; //exclude the last max element from the heap
    heapSort(arr, heapSize);

}

void printHeap(vector<int> &arr){
    for(auto i:arr) cout<<i<<" ";
    cout<<endl;
}


int main(){
    vector<int> arr;
    getElements(arr);
    int heapSize= arr.size();
    buildHeap(arr,heapSize);
    printHeap(arr);
    heapSort(arr,heapSize);
    printHeap(arr);
    return 0;
}