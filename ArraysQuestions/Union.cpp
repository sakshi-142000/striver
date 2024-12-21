#include <iostream>
#include <vector>
#include <set>
using namespace std;

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

vector<int> unionOfSortedArrays(vector<int> &arr1, vector<int> &arr2, int n, int m){
    // [1, 2, 3, 3, 4, 4, 5]
    //[2, 2, 3, 4]
    //union will be [1, 2, 3, 4, 5] 

    //bruteforce >> taking a set and putting all the elements in the set
    set<int> st;
    for(int i=0; i<n;i++) st.insert(arr1[i]); // nlogn
    for(int i=0;i<m;i++) st.insert(arr2[i]);// mlogm

    vector<int> unionArr;
    for(auto it: st) unionArr.push_back(it); //n+m
    return unionArr;
    
}

vector<int> unionOfSortedArraysOptimal(vector<int> &a, vector<int> &b, int n, int m){
    //optimal approach involves 2 pointer approach 
    int u=min(a[0],b[0]);
    vector<int> unionArr;
    unionArr.push_back(u);
    int i=0; // pointing the elements on arr1
    int j=0; // pointing the elements on arr2

    while(i<n and j<m){
        if(a[i]<b[j]){
            if(unionArr.back()!=a[i]) unionArr.push_back(a[i]);
            i++; // increment i anyway even when element is already in the union array and you did not insert
        }
        else{
            //b jth element is less than a ith element
            if(unionArr.back()!=b[j]) unionArr.push_back(b[j]);
            j++;
        }
    }

    //if we still have elements in a or b
    while(i<n) {
        if(unionArr.back()!=a[i]) unionArr.push_back(a[i]);
        i++; 
    }

    while(j<m) {
        if(unionArr.back()!=b[j]) unionArr.push_back(b[j]);
        j++; 
    }

    //time complexity>> O(n+m), every element is only visited once

    return unionArr;
}




int main(){
    vector<int> arr1;
    vector<int> arr2;
    int n = getArray(arr1);
    int m =getArray(arr2);

    //vector<int> result=unionOfSortedArrays(arr1,arr2,n,m);

    vector<int> result=unionOfSortedArraysOptimal(arr1,arr2,n,m);
    for(int i: result) cout<<i<<" ";
    

    return 0;
}