#include<iostream>
#include <vector>
int const N = 1000000;
using namespace std;


int getArray(vector<int> &arr){
    int n;
    cout<<"enter array size"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);       
    }
    return n;
}

int BinarySearchResursive(int *arr, int low, int high, int target){
    if(low>high) return -1;
    int mid= (low+high)/2;  
    if(target==arr[mid]) return mid;  
    else if(target<arr[mid]) {
        // search in left
        return BinarySearchResursive(arr,low,mid-1,target); // make sure that for every fn call you are returning.
    }
    else return BinarySearchResursive(arr, mid+1,high,target); //search right

}

int BinarySearchIterative(int *arr, int target){
    int low=0;
    int high=N-1; 
    while(low<=high){
        // break when low exceeds high
        // cout<<"triggering"<<endl;
        int mid= (low+high)/2; //checking the middle element
        if(arr[mid]==target) return mid; 
        else if(target<arr[mid]) high=mid-1;
        else if(target>arr[mid]) low=mid+1;
    }

    return -1;
}

int main(){
    // vector<int> &arr;
    // int n= getArray(arr);
    int arr[N];
    for(int i=0;i<N;i++) arr[i]=i+1;
    int target;
    cout<<"Enter the number you wanna search for "<<endl;
    cin>>target;
    // cout<<"target is present at index "<<BinarySearchIterative(arr, target);
    cout<<"target is present at index "<<BinarySearchResursive(arr, 0, N-1, target); //passing low and high in the function call
    return 0;
}