#include<iostream>
#include <vector>
using namespace std;

int getArray(vector<int> &arr){
    int n;
    cout<<"enter size"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }
    return n;
}

int find_Upper_bound(vector<int> &arr, int n, int x){
    //using binary search for getting the Upper bound
    // Upper bound of x with be index st arr[index]>x (strictly greater than x)
    // if it does not exist then return the hypothetical last index>> arr.size()
    int low=0;
    int high=n-1;
    int ans= arr.size();
    while(low<=high){
      int mid=(low+high)/2;
      if(arr[mid]<=x) {
        // move right we still need to find the greater one
        low=mid+1;
      }
      else if(arr[mid]>x){
        // might be the upper bound but locate if we have any lesser number than ans
        ans=mid;
        //move left for the lower number than ans but greater than x if available
        high=mid-1;
      }
    }

    return ans;

}

int main(){ 
    vector<int> arr;
    int n=getArray(arr);
    int x;
    cout<<"enter x"<<endl;
    cin>>x;
    cout<<"Upper bound of "<<x<<" "<<find_Upper_bound(arr, n, x);
    return 0;
}