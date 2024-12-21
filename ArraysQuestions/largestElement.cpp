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

int returnLargest(vector<int> &arr){
    int largest=INT_MIN;
    for(auto &i:arr){
        if(i>=largest) largest=i;
    }
    return largest;
}

int main(){
    vector<int> arr;
    int n= getArray(arr);
    int largest= returnLargest(arr);
    cout<<largest<<endl;
    //printArray(arr);
    return 0;
}