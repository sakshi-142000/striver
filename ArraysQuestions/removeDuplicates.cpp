#include <iostream>
#include <vector>
#include <set>
using namespace std;

int getArray(vector<int> &arr){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        arr.push_back(e);
    }

    return n;
}

//better approach >> using set

void removeDuplicateSet(vector<int>&arr){
    set<int> s;
    int n; //counting the number of unique elements
    //inserting in set takes logn time
    for(int i: arr){
        s.insert(i);
    }

    //shifting the elements in the set at the start of the array
    int i=0;
    for(auto j: s){
        arr[i]=j;
        i++;
    }

}


//optimal approach>> using 2 pointer approach
void removeDuplicates(vector<int> &arr, int &n){

    //optimal using 2 pointer approach O(n)
    //i will be pointing to the rightmost unique element and j will iterate and check for unique elements
    int i=0;//first element will be unique ofcourse
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]) {
                arr[i+1]=arr[j];
                i++;
            }
    }

}

void printArray(vector<int> &arr){
    for(int i: arr) cout<<i<<" ";
}

int main(){
    vector<int> arr;
    int n= getArray(arr);
    //removeDuplicates(arr,n);
    removeDuplicateSet(arr);
    printArray(arr);
    return 0;
}