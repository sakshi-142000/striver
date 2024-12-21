#include <iostream>
#include <vector>
using namespace std;

// given an array of integers, find the next permutation of the numbers in that array
// 2 5 1 4 3 2 0
// 2 5 2 0 1 3 4 // next greater number to arr 

int getArray(vector<int> &arr){
    int n;
    cout<<"enter size"<<endl;
    cin>>n;

    for(int i=0;i<n;i++) {
        int e;
        cin>>e;
        arr.push_back(e);
    }

    return n;
}

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

void reverseArray(vector<int> &arr, int n){
//     0 1 2 3 4 5
    // 9 8 7 6 5 4 n=6
    // 4 5 6 7 8 9
    for(int i=0;i<=n/2;i++){
        swap(arr[i],arr[n-1-i]);
    }
}

void nextPermutation(vector<int> &arr, int n){
    // 2 5 1 4 3 2 0 
    // the next permutation will have a prefix that is same as that of array
    // breaking point of that prefix will be >> if you notice the array here, start from the last element towards 0 and notice everything 
    // is from ascending to descending the point where this pattern is broken, you have to get that element and swap it with the next greater one from the right

    // step 1: find the break point 
    // step 2: swap it with it next greater one from right(do not touch the common prefix)
    // step 3: sort the array in ascending after the swap from the breakpoint 

    // 2 5 1 4 3 2 0  breakpoint: 1
    // 2 5 2 4 3 1 0 //swap 1 with its next greater, if you swap it with 0 it would be the previous permutation
    // 2 5 2 0 2 3 4 // done and dusted after sorting 

    int breakPoint=-1;

    for(int i=n-1;i>0;i--){
        if(arr[i]>arr[i-1]) breakPoint=arr[i-1];
    }
    if(breakPoint==-1) {
        reverse(arr.begin(), arr.begin()+n); // reverse the complete array simply no next permutation, array is already descending, the next permuation will be the sorted array
    }
    else{

        // step 2 
        for(int i=n-1; i>breakPoint; i--){
            if(arr[i]>arr[breakPoint]) {
                swap(arr[i], arr[breakPoint]);
                break;
            } 
        }
        // step 3
        reverse(arr.begin()+breakPoint+1, arr.begin()+n);

    }

    for(int i: arr) cout<<i<<" ";
    cout<<endl;

}

int main(){
    vector<int> arr;
    int n=getArray(arr);
    nextPermutation(arr, n);
    return 0;
}
