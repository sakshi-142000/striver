#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

int getElements(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        arr.push_back(e);
    }

    return n;
}

void merge(int low,int mid,int high){
    vector<int> temp;
    int left= low;
    int right=mid+1;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            //swap(left, right); swapping will not work in merging two sorted arrays, it will mess up things
            temp.push_back(arr[left]);
            left++;
        } 
        else {
            temp.push_back(right);
            right++;
        }
    }
    //making sure there are no elements left in the two sorted arrays
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
     while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    //replacing all the elements in the index low to high by temp array elements
   for(int i=low; i<=high; i++){
        arr[i]=temp[i-low];
   }
}


void mergeSort(int low, int high){
// 1 2 3 4 5 6 7
        if(low==high) return;
        int mid= (low + high)/2;
        mergeSort(low, mid);
        mergeSort(mid+1,high);
        merge(low, mid, high);
}


int main(){
    int n = getElements();
    mergeSort(0,n-1);//giving low and high
    for(auto i:arr) cout<<i<<" ";
    return 0;
}