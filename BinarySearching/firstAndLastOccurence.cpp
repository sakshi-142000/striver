#include<iostream>
#include <vector>
using namespace std;

// 1 1 2 4 6 8 8 9 10 11

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

vector<int> firstLastOccurenceBS(vector<int> &arr, int n, int target){
    // 1 1 2 4 6 8 8 9 10 11
    int low=0, high=n-1, first=-1, last=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=target){
            // mid can be the first occurence
            first=mid;
            high=mid-1; //move left to check for smaller mid 
        }
        else low=mid+1;
    }
     if(nums[first]==target) {
            // if target exists then only look for the last occurence otherwise just return {-1 -1}
            int last=first;
            low=first, high=nums.size()-1;
            while (low<=high){
                int mid=(low+high)/2;
                if(arr[mid]==target) {
                    last=mid;
                    low=mid+1; 
                }
                else if(arr[mid]>target) high=mid-1;
            }
            return {first, last};
        }
        else return {-1,-1};
}

vector<int> firstLastOccurenceBrute(vector<int> &arr, int n, int target){
    // 1 1 2 4 6 8 8 9 10 11
    // eg first and last occurence of 8 will be  (5, 6)
    // if does not exist then return -1 -1

    // brute approach includes linear search

    int first=-1, last=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==target and first==-1){
            // first occurence
            first=i; 
            last=i;
        }
        else if(arr[i]==target and first!=-1) last=i; 
    }

    return {first, last};
    
}

vector<int> firstLastOccurenceUsingBounds(vector<int> &arr, int n, int target){
    // 1 1 2 4 6 8 8 9 10 11
    // lets say target=8
    // first occurence of 8 will be lower bound of 8
    // upper bound of 8 will be 9
    // last occurence will be upperBound-1

    // but if target does not exists, then lower bound will return the upper bound value, consider that corner scenario

    int low=0, high=n-1;
    int first=-1, last=n;

    while(low<=high){
        int mid= (low+high)/2;
        if(arr[mid]>=target) {
            first=mid; //look for left as well
            high=mid-1;         
        }
        else low=mid+1; //if arr[mid]<target, go right
    }

    if(arr[first]!=target) return {-1, -1}; //target does not exists
    else{
        //find upperbound-1 for the last occurence

        low=0, high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]<=target) low=mid+1; //move right
            else {
                last=mid;
                high=mid-1; 
            }
        }

    }
    return {first, last-1};
}

int main(){
    vector<int> arr;
    int n= getArray(arr);
    int target;
    cin>>target;
    vector<int> result=firstLastOccurenceUsingBounds(arr, n, target);
    for(auto i: result) cout<<i<<" ";
    cout<<endl;
    return 0;
}