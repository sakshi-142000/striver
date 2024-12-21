#include <iostream>
#include <vector>
using namespace std;

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

int MinimumInSortedRotatedArray(vector<int> &arr, int n){
    int low=0, high=n-1; 

    int minElement= INT_MAX;

    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low]<=arr[mid]){
            // if left part of array is sorted
            minElement=min(minElement, arr[low]);
            //search in right part now
            low=mid+1;
        }
        else if (arr[mid]<=arr[high]){
            // right part is sorted
            minElement=min(minElement, arr[mid]); //get the minimum
            //look in left array now
            high=mid-1;
        }
    }

    return minElement;
}

int main(){
    vector<int> arr;
    int n=getArray(arr);
    cout<<MinimumInSortedRotatedArray(arr, n)<<endl;
    
    return 0;
}