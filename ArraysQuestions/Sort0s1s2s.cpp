#include <iostream>
#include <vector>
using namespace std;

//given an array consisting of 0's, 1's and 2's 
// [2 0 0 1 2 0 2 2 1 1 0 0]
//after sorting it should be [ 0 0 0 0 0 1 1 1 2 2 2 2]

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

void sortArrayBrute(vector<int> &arr, int n){
    //most brute approach would be to apply mergeSort just that

    //sort(arr.begin(),arr.end());

    //next brute approach can be to get the count of 0's 1's and 2's and replace them accordingly
    int count0=0;
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) count0++;
        else if (arr[i]==1) count1++;
        else if(arr[i]==2) count2++;
    }

    for(int i=0;i<count0;i++){
        arr[i]=0;
    }
     for(int i=count0;i<count0+count1;i++){
        arr[i]=1;
    }
     for(int i=count0+count1;i<n;i++){
        arr[i]=2;
    }
}

void swap(int &i, int &j){
    int temp= i;
    i=j;
    j=temp;
}

void sortArrayDNF(vector<int> &arr, int n){
    //dutch national flag algorithm

    // consider left mid and high pointers
    // 000...00111...111123454222....2222
    // low is pointing to start of 1 series, mid pointing to start of unsorted array, and high is pointing to end of unsorted array

    int low=0;
    int mid=0;
    int high=n-1;

    // initially consider the array to be in the unsorted region of dnf array starting from mid to high

    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1) mid++;
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            mid++;
            high--;
        }
    }
}


int main(){
    vector<int> arr;
    int n = getArray(arr);

    //sortArrayBrute(arr,n);
    sortArrayDNF(arr,n);

    for(int i: arr) cout<<i<<" "; 
    

    return 0;
}
