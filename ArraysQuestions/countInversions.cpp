#include <iostream>
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

int countInversionsOnMerge(vector<int> &arr, int low, int mid, int high){
    //{2 3 4 } {1 5}
    // temp: 1 2 3 4
    // not changing the low and mid as we will be needing them later
    int count=0; //initially no inversions
    int left= low; //pointer to the first half of array
    int right= mid+1; //pointer to the second half of the array

    vector<int> temp; //for storing the merged elements

    while(left<=mid and right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]); //store the smaller element
            left++;
        }
        else {
            // arr[left] > arr[right]
            count+=mid-left+1; // all the elements to the right of left till mid will also be greater than arr[right]
            temp.push_back(arr[right]);
            right++;
        }
    }
    //{1 2 3 4}
    // if there are still elements in left->mid or right-> high them move them as it is in the temp array
    while(left<=mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high) {
        temp.push_back(arr[right]);
        right++;
    }
    // {1 2 3 4 5}

    // moving elements from temp back to arr
    int k=0; 
    for(int i=low;i<=high;i++){
        arr[i]=temp[k];
        k++;
    }
    // cout<<"inside merge "<<left<< right <<endl;
    return count;


}

int mergeSort(vector<int> &arr, int low, int high){

    int count=0; // for every shortenened array, count=0;
    if(low==high) return count;
   
    //low<high, means you going from low to high till there are two element to compare, we can also do low<=high but it is not required
    int mid= (low+high)/2;
    // cout<<"inside ms"<<low << mid << high<<endl;
    count+=mergeSort(arr, low, mid); // for the first half mid will be the new high // get the count from the first half of array where we counted the inversions for further two half arrays
    count+=mergeSort(arr, mid+1, high); // for the second half array new low will be mid+1
    count+=countInversionsOnMerge(arr, low, mid, high); // merge the both of the sorted arrays //get the number of inversions in the two merged arrays

    return count;
}



int main(){
    vector<int> arr;
    int n=getArray(arr);
    cout<<mergeSort(arr,0,n-1); //passing 0 as low and n-1 as high
    cout<<endl;
    for(auto i: arr) {
        cout<<i<<" ";
    }


}