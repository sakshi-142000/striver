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

// given rotated sorted array with duplicate elements, return true if target is present else false

bool RotatedSortedArray(vector<int> &arr, int n, int target){
    // we can do it with binary search but the edge case occurs when arr[low] == arr[mid] == arr[high]
    // 3 3 3 1 3 3 3 3 3 3, target= 1
    // low=0, mid=5, high=10 arr[low] == arr[mid] == arr[high]
    // now when you split from mid, you do not know which one is the sorted array
    // left one is not sorted but it seems to be sorted when we check on the condition arr[low]<=arr[mid]

    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target) return true;
        if(arr[low]==arr[mid] and arr[high]==arr[mid]) {
            low++;
            high--;
            continue; //calculate mid again, however, mid will always point to the same index as we are increating and decreasing simultaneously
            // do this until we get out of this situation
        }

        else if (arr[low]<arr[mid]){
            // first half is sorted
            if(target<=arr[low] and target<arr[mid]){
                high=mid-1; //target is in left half
            }
            else low=mid+1; 
        }
        else if(arr[mid]<arr[high]){
            //second half is sorted
            if(target>arr[mid] and target<=arr[high]){
                low=mid+1; //target is in second half
            }
            else high=mid-1;

        }
    }

    return false;
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