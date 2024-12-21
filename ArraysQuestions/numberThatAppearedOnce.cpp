#include <iostream>
#include <vector>
#include <map>
using namespace std;

//given array of numbers each appearing twice, find that one number that appeared only once
// [1 1 2 2 3 4 4 5 5] -> return 3 here 

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

int findNumBrute(vector<int> &arr, int n){
    //for each number in the array check the count of each num
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]) cnt++;
        }
        if(cnt==1) return arr[i];
    }
    return -1; 
}

int findNumBetter(vector<int> &arr, int n){
    //build a hash array of size maxElement +1 and store the cnt of every number appearance in the hash array

    //find the maxElement
    int maxE=0;
    for(int i: arr) maxE=max(maxE, i);
    vector<int> hash(maxE+1, 0); //[1 1 2 2 3 4 4 5 5]
    for(int i: arr){
        hash[i]++;
    }
    for(int i=0;i<hash.size();i++) if(hash[i]==1) return i;
    return -1; 
}

int findNumBetterUsingMap(vector<int> &arr){
    //using map because what if the maxElement exceeds 10^6 
    //find the maxElement
    map<long long, int> mpp;
    for(auto i: arr) mpp[i]++; // dont get confuse here, mpp will create a key for i and default value will be 0 and then increment will take place
    for(auto i: mpp) {
        if(i.second==1) return i.first;
    }
    return -1; 
}

int findNumOptimal(vector<int> &arr){
    
    //optimal approach is very simple just do a xor of all the numbers the one which does not have a pair will be left
    int xorv=0; 
    for(int i: arr) xorv^=i;

    return xorv; 
}




int main(){
    vector<int> arr;
    int n = getArray(arr);
    //cout<<"result: "<<findNumBrute(arr, n)<<endl;
    // cout<<"result: "<<findNumBetter(arr, n)<<endl;
    // cout<<"result: "<<findNumBetterUsingMap(arr)<<endl;
    cout<<"result: "<<findNumOptimal(arr)<<endl;
    return 0;
}