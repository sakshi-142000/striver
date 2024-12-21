#include <iostream>
#include <vector>
using namespace std;

// problem statement: given an array of integers, find the peak element in the array
// peak element: arr[i] s.t. 
// arr[i-1]<arr[i]>arr[i+1]
// assume -infinity on both sides of array

int peakElementBrute(vector<int> &arr, int n){

    // linear search
    for(int i=0;i<n;i++){
        // not leaving 0th an (n-1)th index, instead putting conditions on them

        if((i==0 || arr[i-1]<arr[i]) && (i==n-1 || arr[i]>arr[i+1]) ) return i; //return 0 based index of the peak element

        // if i==0 then don't look for the previous index (-infinity and arr[0] is always greater than that) then just look for the arr[i+1]
        // if i==n-1 then do not look for the next index (arr[n-1] will always be greater than -infinity)
    }
    return -1; //this will never run but still to avoid unnecessary warnings
}


int getArray(vector<int> &arr){
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }
    return n;
}

int main(){
    vector<int> arr;
    int n=getArray(arr);
    
    cout<<peakElementBrute(arr, n)<<endl;
    
    return 0;
}