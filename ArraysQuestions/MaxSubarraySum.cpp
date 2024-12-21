#include <iostream>
#include <vector>
using namespace std;

int getArray(vector<int> &arr){
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        arr.push_back(e);
    }
    return n;
}

vector<int> longestSubarraySumOptimal(vector<int> &arr, int n){ 
    //using kadanes algorithm, not taking the -ve sum forward
    // [-2, -1, 4, -1, -2, 1, 5, -3]

    vector<int> result; // subarray to be returned
    int maxSum=INT_MIN;
    int sum=0;
    int startI=-1;
    int endI=-1;

    int start=-1;
    for(int i=0;i<n;i++){
        if(sum==0) start=i;
        sum=sum+arr[i];
        if(sum>maxSum){
            maxSum=sum;
            startI=start;
            endI=i;
        }

        if(sum<0) sum=0;
    }

    for(int i=startI;i<=endI;i++){
        result.push_back(arr[i]);
    }

    return result;
}

void longestSubarraySumBrute(vector<int> &arr, int n){ 
    //using looping
    // [-2, -1, 4, -1, -2, 1, 5, -3]

    int maxSum=INT_MIN;
    int iStart=-1;
    int iLast=-1;
    for(int i=0;i<n;i++){
        int sum=0;
        int start=i;
        for(int j=i;j<n;j++){
            sum+=arr[j];//sub array sum from i to j
            if(sum>maxSum) {
                maxSum=sum;
                iLast=j;
                iStart=start;
            }
        }
    }

    for(int i=iStart;i<=iLast;i++) cout<<arr[i]<<" ";

}
int main(){
    vector<int> arr;
    int n=getArray(arr);
    longestSubarraySumBrute(arr,n);
    // vector<int> result= longestSubarraySumOptimal(arr, n);
    // int maxSum=0;
    // for(int i:result){
    //     cout<<i<<" ";
    //     maxSum+=i;
    // }
    // cout<<endl;
    // cout<<maxSum;

    return 0;

}