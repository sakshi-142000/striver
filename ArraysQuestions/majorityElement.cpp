#include <iostream>
#include <vector>
#include <map>
using namespace std;


/*
    given a list of elements in the array, return the majority element, which occured >n/2 times
    eg 1 7 7 7 1 5 7 7 7 5 n=10 , majority element should occur atleast 6 times (>5)
    majority element: 7

*/

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

int majorityElementBrute(vector<int> &arr, int n){

// eg 1 7 7 7 1 5 7 7 7 5 n=10 , majority element should occur atleast 6 times (>5)
//    majority element: 7

    for(int i=0;i<n;i++){
        int count=1;
        for(int j=i+1;j<n;j++){
            if(arr[j]==arr[i]) count++;
            if(count>n/2) return arr[i];
        }
        
    }

    return -1;
    // T(n): O(n^2), 
}

int majorityElementBetter(vector<int> &arr, int n){

    // eg 1 7 7 7 1 5 7 7 7 5 n=10 , majority element should occur atleast 6 times (>5)
    //    majority element: 7

    //for better approach, we will use a hashmap to store the count of element
    //    key: element, value: count

    map<int, int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]+=1;// the insertion of arr[i] as key, defaulting it to 0 and then increment all happening in one statement
    }
    // now iterate through the map to check if there is any key whose value is >n/2

    for(auto it: mpp){
        if(it.second>n/2) return it.first;
    } 

    return -1;

    //T(n): O(nlogn), SC: O(n), in case all the elements in the array are unique

}

int majorityElementOptimal(vector<int> &arr, int n){

    // eg 1 7 7 7 1 5 7 7 7 5 n=10 , majority element should occur atleast 6 times (>5)
    //    majority element: 7

    //for optimal approach, we will use the moore's voting algorithm, counting towards the majority element and decrementing the count if get !element
    // in case of 0, choosing the next element for majority

    int element=arr[0];
    int count=1; //initially

    for(int i=1;i<n;i++){
        if(arr[i]==element) count++;
        else count--;

        if(count==0 and i<n-1) element=arr[i+1];
    }

    if(count<=n/2){
        int count2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==element) count2++;
        }
        if(count2>n/2) return element;
    }

    return -1;

    

}


int main(){
    vector<int> arr;
    int n = getArray(arr);
    //cout<<"Majority Element: "<<majorityElementBrute(arr, n)<<endl;
    cout<<"Majority Element: "<<majorityElementOptimal(arr, n)<<endl;


    return 0;
}
