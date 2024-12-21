#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;

int getArray(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        arr.push_back(e);
    }

    return n;
}

void swap(int i, int j){
    int temp= arr[i];
    arr[i]= arr[j];
    arr[j]= temp;
}

void partition(int low, int high,int pivot){
    int i=low;
    int j=high; // the two pointers
    //eg 5 3 9 2 3 10 1 , i= 0 j=6
    // 1 3 9 2 3 10 5 i at 9 and j at 3 swap i=2 j=4
    //1 3 3 2 9 10 5 // i is at 4 j is at 3 next time loop will not run as j is less than i 
    //pivot = 4
    while (i<j){
        while(arr[i]<=pivot and i<j){
            i++;
        }
        while(arr[j]>=pivot and i<j){
            j--;
        }

        if(i<j) swap(i,j);
    }

    //at the end, i will be pointing at first element greater than pivot and j will be pointing at last element lesser than pivot, better place pivot at i and shift

    //shifting from i+1
    // make space first
    // 1 3 3 2 9 10 5 0
    // 1 3 3 2 9 9 10 5
    arr.push_back(0);
    for(int k= (high+1); k>i;k--){
        cout<<"k "<<k;
        arr[k]=arr[k-1];
    }

    arr[i]=pivot;

}


int main(){
    int n = getArray();
    int pivot;//pivot is the element to be inserted in it's right position
    cin>>pivot;
    partition(0,n-1,pivot); //passing low and high in the partition
    for(auto i: arr) cout<<i<<" ";
    cout<<endl;

   
    return 0;
}