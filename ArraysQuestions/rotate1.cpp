#include <iostream>
#include<vector>
using namespace std;

int getArray(vector<int> &arr){
    int n;
    cout<<"enter size"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        arr.push_back(e);
    }

    return n;
}

void leftRotate1(vector<int> &arr,int n){
    // 1 2 3 4 5 
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}

void rightRotate1(vector<int> &arr, int n){
    // 1 2 3 4 5
    // 5 1 2 3 4
     
    int temp=arr[n-1];
    for(int i=n-1;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
}

void printArray(vector<int> &arr){
    for(int i:arr) cout<<i<<" ";
    cout<<endl;
}

int main(){

    vector<int> arr;
    int n=getArray(arr);
    //leftRotate1(arr,n);
    rightRotate1(arr,n);
    printArray(arr);

    return 0;
}