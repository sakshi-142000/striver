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

int RotatedSortedArray(vector<int> &arr, int n, int target){
    // problem: given a rotated sorted array, find the target in the array in logn 
    // eg 7 8 9 1 2 3 4 5 6 //rotated from 7
    // approach is that, get mid, either left or right of the mid will definitely be sorted, you can work from there
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target) return mid;
        // identify the sorted half array 
        if(low<=mid){
            //first half is sorted
            // check if target is in the first array range??
            if(target>=low and target<mid){
                high=mid-1; //search in first half
            }
            else low=mid+1; //search in the second half
        }
        else if(mid<=high){
            //second half is sorted
            if(target>mid and target<=high){
                //target lies in the sorted array itself
                low=mid+1; //search in the second half
            }
            else high=mid-1; //search in second half
        }
    }

    return -1; //if target not found
}

int main(){
    vector<int> arr;
    int n=getArray(arr);
    int target;
    cout<<"enter target"<<endl;
    cin>>target;
    cout<<RotatedSortedArray(arr, n, target)<<endl;
    return 0;
}