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

// floor: given a sorted array and number x, floor of the number is the greatest number which is lower than or equal to x
// ceil:  given a sorted array and number x, ceil of the number is the smallest number which is larger than or equal to x (basically the lower bound of x)

int findFloor(vector<int> &arr, int x){
    int low=0, high=arr.size()-1;
    int ans=-1;

    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<=x){
            // mid might be the floor but what if someone else exists which is<= x but greater than mid
            ans=mid;
            // move right to check for greater one if exists
            low=mid+1;
        }
        else if(arr[mid]>x) high=mid-1; //move left
    }

    return ans;
}



int main(){ 
    vector<int> arr;
    int n=getArray(arr);
    int x;
    cout<<"enter x"<<endl;
    cin>>x;
    cout<<"floor of x is"<<findFloor(arr, x)<<endl;
    return 0;
}