#include <iostream>
#include <vector>
using namespace std;

//was not working for the test case of descending array if we put i<j (leave the equal to condition)

vector<int> arr;

int getArray(){
    int n;
    cout<<"enter array size"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        arr.push_back(e);
    }
    return n;
}

void swap(int i, int j){
    int temp= arr[i];
    arr[i]= arr[j];
    arr[j]= temp;
}

int partition(int low, int high){
    //doing it by two pointer approach
    int pivot= arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot and i<=j){
            i++;
        }
        while(arr[j]>=pivot and i<=j){
            j--;
        }
        if(i<=j) swap(i,j);
    }

    swap(i-1,low);
    return i-1;
}
// 3 5 2 1 9 7
// after first partion>>>  3 1 2 5 9 7 (i is at 5 and j is also at 5) swap low with i-1
//taking pivot as the first element(low) of the array
void partitionSort(int low, int high){
    if(low<high){
        int part = partition(low, high);
        partitionSort(low, part);
        partitionSort(part+1,high);
    }
}

int main(){

    int n= getArray();
    partitionSort(0,n-1);
    for(auto i: arr) cout<<i<<" ";
    cout<<endl;
    return 0;
}