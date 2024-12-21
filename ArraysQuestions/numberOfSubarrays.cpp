#include <iostream>
#include <vector>
#include <map>
using namespace std;

int getArray(vector<int> &arr){
    cout<<"enter n"<<endl;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        arr.push_back(e);
    }

    return n;

}

int maxNumberOfSubarrays(vector<int> &arr, int n){
    int k;
    cout<<"enter k"<<endl;
    cin>>k;
    map<int, int> hash; //hashmap with keys as prefix sum and value as count
    hash[0]=1;
    int count=0;
    int sum=0;
    // array:       1 2 3 -3 1 1 1 4  2  -3
    // prefix sum:  1 3 6  3 4 5 6 10 12 9
    // hash array: <0,1> <1,1> <3,1/2> <6,1/2> <4,1> <5,1> <10,1> <12,1> <9,1>
    // count = 1 >> 2 >> 3 >> 4 >> 6 >> 7
    for(int i=0;i<n;i++){
        sum+=arr[i];
        int remSum=sum-k;
        if(hash.find(remSum)!=hash.end()){
            //if there exists the remSum prefix previously
            count+=hash[remSum]; // count of all the subarrays with sum k at a given index = count of all the subarrays with sum s-k previously
            hash[sum]++;// store the prefix sum and it's count, make sure not to enter the sum but to increase it
        }


    }
    return count;

}

int main(){
    vector<int> arr;
   int n= getArray(arr);
    cout<<maxNumberOfSubarrays(arr, n);
    return 0;
}