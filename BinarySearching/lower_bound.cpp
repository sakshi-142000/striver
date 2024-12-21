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

int find_lower_bound(vector<int> &arr, int n, int x){
    //using binary search for getting the lower bound
    // lower bound of x with be index st arr[index]>=x
    // if it does not exist then return the hypothetical last index>> arr.size()
    int low=0;
    int high=n-1;
    int ans= arr.size();
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=x){
            // might be the lower bound
            ans=mid;
            // move left to check for any smaller element
            high=mid-1;
        }
        else if(arr[mid]<x){
            //move right
            low=mid+1;
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
    cout<<"lower bound of "<<x<<" "<<find_lower_bound(arr, n, x);
    return 0;
}