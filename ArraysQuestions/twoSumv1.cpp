#include <iostream>
#include <vector>
#include <map>
using namespace std;

// two sum problem, given an array and a target value, check if we have number in the array tht sum up to target or not
// if yes, then return true otherwise false

int getArray(vector<int> &arr){
    int n;
    cout<<"enter n"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        arr.push_back(e);
    }
    return n;
}

bool twoSumOptimal(vector<int> &arr, int n){
    //1 9 2 6 3 8 target=14
    //using 2 pointer approach increasing left or decreasing right depending on if sum is greater or lesser than target

    int target;
    cin>>target;

    int left=0;
    int right=n-1;
    int sum=0;

    sort(arr.begin(),arr.end());

    while(left<right){
        sum=arr[left]+arr[right];
        if(sum==target) return true;
        else{
            if(sum<target) {
                left++;
            }
            else right--;

        }
    }

    return false;



}


bool twoSumv1Better(vector<int> &arr, int n){
    //better approach includes, using hashing 
    int target;
    cin>>target;

    map<int, int> mpp; // <number, index> pair
    vector<int> result;

    for(int i=0;i<n;i++){
        int comp=target-arr[i];
        if(mpp.find(comp)==mpp.end()){
            // if comp of arr[i] does not exist in hash
            mpp[arr[i]]=i; // store the current number and it hash value(index)
        }

        else return true;
        // else {
        //     result.push_back(i);
        //     result.push_back(mpp[comp]);
        // }
    }
    // return result;
    return false;
}

bool twoSumBrute(vector<int> &arr, int n){
    int target;
    cin>>target;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(arr[i]+arr[j]==target) return true;
        }
    }
    return false;
}




int main(){
    vector<int> arr;
    int n = getArray(arr);
    // cout<<twoSumv1Better(arr,n)<<" ";
    // cout<<twoSumBrute(arr,n)<<" ";
    cout<<twoSumOptimal(arr,n)<<" ";
    // for(int i: result) cout<<i<<" ";
    return 0;
}
