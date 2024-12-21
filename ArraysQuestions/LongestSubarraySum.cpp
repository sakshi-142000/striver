#include <iostream>
#include <map> // for better approach we need hashing for O(logn) operation
#include<vector>
using namespace std;

/*
q: given an array and int k find the maximum subarray length that sum up to k 
eg:
a: [1 2 1 1 1 3 3] k=3
subarray: [1,2] [1 1 1] [3] [3]
[1 1 1] has the largest length, return 3
*/

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

int longestSubarraySumOptimal(vector<int> arr, int n){
    // T(n): O(2n); works for only for arrays with +ves and 0's
    // using two pointer l(left) and r (right), right for moving forward and left for reducing the sum by arr[left] in case sum exceeds k
    // using 2 pointer + greedy approach
    //arr:   [1 2 1 1 1 3 3] k=3

    int k;
    cin>>k;
    int l=0, r=0; // the left and right pointers
    int maxLen=0, sum=0; //initially
    while(r<n){
        if(sum>k and l<=r){
            //in case sum exceeds, also making sure that l never exceeds r
            sum-=arr[l]; // decreasing sum and then increasing l, 'cause l is already standing at 0 initially
            l++;
        }
        if(sum==k) maxLen=max(maxLen, r-l+1);
        r++;
        if(r<n) sum+=arr[r]; // making sure we are not touching array out of index thing

    }

    return maxLen;
}

int longestSubarraySumBetter(vector<int> arr, int n){
    // T(n): O(nlong); works for all the arrays with +ves, 0's and -ves
    //arr:   [1 2 1 1 1 3 3] k=3
    //presum:[1 3 4 5 6 9 12]
    //for better approach, we will be using hashMap to store presum-index as key value 
    int k;
    cin>>k;
    map<int, int> hashPresum;
    int maxLen=0, sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if (sum==k) maxLen=max(maxLen, i+1);
        else if(sum>k){
            int rem= sum-k;
            if(hashPresum.find(rem)!=hashPresum.end()){
                //if remainder exists
                maxLen=max(maxLen, i-hashPresum[rem]);
            }
        }

        if(hashPresum.find(sum)==hashPresum.end()) hashPresum[sum] = i; //storing in the hashMap only if the presum already does not exits, eliminating the corner cases for 0s and -ves
        
    }


    return maxLen;
}

int longestSubarraySumBrute(vector<int> arr, int n){
    //[1 2 1 1 1 3 3] k=3
    //for bruteforce, for every number, generate all the subarrays starting from that number
    int k;
    cin>>k;
    int maxLen=0;

    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         int sum=0;
    //         for(int l=i; l<=j;l++){
    //             sum+=arr[l];
    //             if(sum==k) maxLen=max(maxLen, l-i+1); 
    //         }
    //     }
    // }

    //Optimising the above bruteforce to n^2

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k) maxLen=max(maxLen, j-i+1);
        }
    }


    return maxLen;
}

int main(){
    vector<int> arr;
    int n = getArray(arr);
    //cout<<longestSubarraySumBrute(arr, n)<<endl;
    //cout<<longestSubarraySumBetter(arr, n)<<endl;
    cout<<longestSubarraySumOptimal(arr, n)<<endl;
    

    return 0;
}