#include <iostream>
#include <vector>
using namespace std;


// given a array of sorted intergers, you rotate the array by some numbers (one at a time), find the number of rotations
// eg                 1 2 3 4 5
// after rotation     3 4 5 1 2 // rotated 3 times 

int getArray(vector<int> &arr){
    int n;
    cout<<"give the array size input"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }

    return n;
}


int numberOfArrayRotationsBS(vector<int> &arr, int n){
    // approach is to find the minimum array element because index of the min element is the number of rotations cz it has been moved that many times
    int low=0, high=n-1; 
    int minIndex=-1; //initially
    int minElement=INT_MAX;

    while(low<=high){
        int mid=(low+high)/2;
        //figure out the sorted array whether it is low-mid or mid-high
        // eg  3 4 5 1 2 low-> 3 mid->5 high-> 2 low-mid is sorted

        if(arr[low]<=arr[mid]){
            //first half is sorted, get the minimum and search in the right unsorted array
            minElement=min(minElement,arr[low]);
            if(minElement==arr[low]) minIndex=low;
            low=mid+1; 
        }
        else if(arr[mid]<=arr[high]){
            minElement=min(minElement,arr[mid]);
            if(minElement==arr[mid]) minIndex=mid;
            high=mid-1; 
        }
    }

    return minIndex;
}

int main(){
    vector<int> arr;
    int n=getArray(arr);
    cout<<numberOfArrayRotationsBS(arr, n)<<endl;
    return 0;
}