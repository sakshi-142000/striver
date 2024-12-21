#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


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

int calculateMaxE(vector<int> &arr){
    int maxE=INT_MIN;
    for(int i=0;i<arr.size();i++){
        maxE=max(maxE, arr[i]);
    }
    return maxE;
}

int calculateSum(vector<int> &arr, int n, int divisor){
    int sumAll=0;
    for(int i=0;i<n;i++){
        sumAll+=ceil((double)(arr[i])/(double)(divisor));
    }
    // cout<<sumAll<<"this is sumALl"<<endl;
    return sumAll;
}

int smallestDivisor(vector<int> &arr, int n, int threshold){
    int low=1, high=calculateMaxE(arr); 
    while(low<=high){
        int mid=(low+high)/2;
        // cout<<"low, high, mid, calculateSum"<<low<<" "<<high<<" "<<mid<<" "<<calculateSum(arr, n, mid)<<endl;
        if(calculateSum(arr, n, mid) <= threshold){
            // move left to check if we can have a smaller number which can still give us value <=threshold
            high=mid-1;
        }
        else if(calculateSum(arr, n, mid) > threshold) low=mid+1;
    }
    // cout<<"ans "<<low<<endl;
    return low;
}


int main(){
    vector<int> arr;
    int n=getArray(arr);
    int threshold;
    cout<<"enter threshold"<<endl;
    cin>>threshold;
    cout<<smallestDivisor(arr, n, threshold)<<endl;

    return 0;
}