#include <iostream>
#include <vector>
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

void printArray(vector<int> const &arr){
    for(auto &i: arr) cout<<i<<" ";
    cout<<endl;
}
//2 4 3 5 6 7 return 6

//better
int returnSecondLargest(vector<int> &arr){
    int largest=INT_MIN;

    for(int &i:arr) {
        if(i>largest) largest=i;
    }
    int secondLargest=INT_MIN;
    for(int i:arr){
        if(i>secondLargest and i<largest) secondLargest=i;
    }
    
    return secondLargest;
}
//optimal
int optimalSecondLargest(vector<int> &arr){

    int largest=arr[0];
    int secondLargest=INT_MIN;
    for(int i=1;i<arr.size();i++){
        if(arr[i]>largest){
            secondLargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest and arr[i]>secondLargest) secondLargest=arr[i];
        return secondLargest;
    }

}

int main(){
    vector<int> arr;
    int n= getArray(arr);
    int secondlargest= returnSecondLargest(arr);
    cout<<secondlargest<<endl;
    //printArray(arr);
    return 0;
}