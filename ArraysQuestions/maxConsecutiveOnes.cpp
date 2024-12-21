#include <iostream>
#include <vector>
using namespace std;

// given an array of 0s and 1s, find the max numbers of consecutive 1s in the array
// break when there is a 0 but keep the count of max ones till now

void getArray(vector<int> &arr){
    int n;
    cout<<"enter n"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        arr.push_back(e);
    }
}

int maxConsecutiveOnes(vector<int> &arr){

    int maxOnes=0; //initially
    int tempCount=0;
    for(int i: arr){
        if(i==1){
            tempCount++;
            maxOnes=max(maxOnes,tempCount);
        }
        else{
            tempCount=0; //start again
        }
    }
    return maxOnes;
}



int main(){
    vector<int> arr;
    getArray(arr);
    cout<< "maxConsecutiveOnes : "<<maxConsecutiveOnes(arr)<<endl; 

    return 0;
}