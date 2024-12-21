#include<iostream>
#include <vector>
using namespace std;

// count reverse pairs
// for a given array, find the count of all the pairs(arr[i], arr[j]) where arr[i]>2*arr[j] and i<j

int getArray(vector<int> &arr){
    int n;
    cout<<"enter array size"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }

    return n;
}

int countReversePair(vector<int> &arr, int low, int mid, int high){
    //{12 19 25 40} {2 6 9}
    // approach is to traverse from low to mid in the first array and check for corresponding 2*arr[i] in the second array from mid+1 to high
    // key point to note is that, as both the arrays are sorted, if an element from left array is 2X of any element in the right array then the element right to the this element will also be >2X of this element as array is in increasing order

    int count=0, j=mid+1; //j is declared in visiblity of i, for the next time j's position will be visible to i
    for(int i=low;i<=mid;i++){
        while(j<=high && arr[i]>2*arr[j]){
            count+=mid-i+1; // all the elements to the right of i will also be counted
            j++;
        }
    }
    
    return count;
}

void merge(vector<int> &arr, int low, int mid, int high){

    //{12 19 25 40} {2 6 9}
    int left=low;
    int right=mid+1;
    vector<int> temp;

    while(left<=mid and right<=high){
        if(arr[left]<arr[right]) temp.push_back(arr[left++]);

        else temp.push_back(arr[right++]);
    }

    while(left<=mid) temp.push_back(arr[left++]);
    while(right<=high) temp.push_back(arr[right++]);

// moving the elements back to array from temp
    int k=0;
    for(int i=low;i<=high;i++){
        arr[i]=temp[k];
        k++;
    }


}



int mergeSort(vector<int> &arr, int low, int high){
    // optimal approach uses merging technique, using merge to divide the array repeatedly into two sorted arrays and before merging the sorted elements we can find the reverse pairs
    int count=0;
    if(low==high) return count; //if there is only one left then return, it is already sorted and reverse pair count will be 0 in that case
    int mid= (low+high)/2;
    count+=mergeSort(arr, low, mid);
    count+=mergeSort(arr, mid+1, high);
    //given these two sorted arrays find the reverse pair count in these as well
    count+=countReversePair(arr, low, mid, high);
    merge(arr, low, mid, high);
    return count;
}

int main(){
    vector<int> arr;
    int n= getArray(arr);
    cout<<mergeSort(arr, 0,n-1);

    cout<<endl;
    for(auto i: arr) cout<<i<<" ";
}