#include <iostream>
#include <vector>
using namespace std;


// given a array of sorted intergers, each having a pair, there exists a single element, find that single element
// eg 1 1 2 2 3 3 4 4 5 5 6 7 7 8 8 9 9 >>> here 6 is the single element


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

int findSingleElement(vector<int> arr, int n){

    // approach is to use binary search 
    // 0 1 2 3 4 5 6 7 8 9 | 10 | 11 12 13 14 15 16
    // 1 1 2 2 3 3 4 4 5 5 | 6  | 7  7  8  8  9  9

    // notice that due to 6, the single, the pair of index being (even, odd) broke, on the left of 6 elements have index pair as even, odd and on the right have index pair as odd, even
    // we will eliminate elements in the array using this property

    if(arr.size()==1) return arr[0]; // can't do anything with single element array as we will not be able to compare the left and right element
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1]; //if mid will point of either the oth index or last index than we might get OOBindexexception

    int low=1, high=n-1;

    while(low<=high){
        int mid=(low+high)/2;
        if((arr[mid]!=arr[mid+1]) && (arr[mid]!=arr[mid-1])) {
            // cout<<"checking mid"<<arr[mid]<<" "<<arr[mid+1]<<" "<<arr[mid-1]<<endl;
            return arr[mid];
        }

// even-odd pair, move to the righ
        else if(( (mid%2==0) and (arr[mid]==arr[mid+1])) || ((mid%2!=0) && (arr[mid]==arr[mid-1])) ) {
            // cout<<"inside even odd pair"<<arr[mid]<<" "<<arr[mid+1]<<" "<<arr[mid-1]<<endl;
            low=mid+1;
        }
// odd even pair, eliminate and move to the left
        else if(( (mid%2==0) and (arr[mid]==arr[mid-1])) || ( (mid%2!=0) && (arr[mid]==arr[mid+1])) ) {
            // cout<<"inside odd even pair"<<arr[mid]<<" "<<arr[mid+1]<<" "<<arr[mid-1]<<endl;
            high=mid-1;
        }

    }

}

int main(){
    vector<int> arr;
    int n=getArray(arr);
    cout<<findSingleElement(arr, n)<<endl;
    return 0;
}