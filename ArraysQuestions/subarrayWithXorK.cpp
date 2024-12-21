#include <iostream>
#include <vector>
#include <map>
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

int subArrayWithXorKOptimal(vector<int> &arr, int n){
    // [4 2 2 6 4], target=6

    // Optimal approach uses hashing to store the xor at every index and then checking the if we can meet the xorTarget, if we can find 
    // lets say if at any index we get xor as 4, then we need xorRequired so that we can reach target 6 (lets say)
    // xorRequired ^k = xoratindex
    // xorRequired^k^k = xoratindex ^k
    // xorRequired=xoratindex^k  //we will use this >>>>very SIMPLE

    map<int, int> xorHash; //key will be xor at the indexes and value will be the count for the same
    xorHash[0]++; //storing 0,1 as pair initially
    int xorTarget;
    cout<<"enter xorTarget "<<endl;
    cin>>xorTarget;
    int count=0; //initially obv
    int xi=0; // xor at index 
    for(int i=0;i<n;i++){
        xi^=arr[i];
        int xorRequired = xi^xorTarget;
        if(xorHash.find(xorRequired)!=xorHash.end()){
            //xorRequired exists previously
            count+=xorHash[xorRequired];
        }
        //found or not found increment xorHash[xorRequired] for hashing
        xorHash[xorRequired]++;
    }
    

    return count;
}


int subArrayWithXorKBrute(vector<int> &arr, int n){
    // [4 2 2 6 4]

    // brute approach: get all the subarrays and check xor of each subarray
    int xorTarget;
    cout<<"enter xorTarget "<<endl;
    cin>>xorTarget;
    int count=0; //initially 
    for(int i=0;i<n;i++){
        int x=0; // xor was already taken so giving variable name x
        for(int j=i;j<n;j++){
            x=x^arr[j];
            if(x==xorTarget) count++;
        }
    }

    return count;
}

int main(){

    vector<int> arr;
    int n=getArray(arr);
    // cout<<subArrayWithXorKBrute(arr, n)<<endl;

    cout<<subArrayWithXorKOptimal(arr, n)<<endl;

    
    return 0;
}