#include <iostream>
#include <vector>
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

int linearSearch(vector<int> &arr,int n){

    //search for d in the array
    int d;
    cout<<"enter what you wanna search";
    cin>>d;
    for(int i=0;i<n;i++){
        if(arr[i]==d) return i;
    }
    return -1;
}


int main(){
    vector<int> arr;
    int n = getArray(arr);
    cout<< linearSearch(arr,n);

    return 0;
}
