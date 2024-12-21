#include <iostream>
#include <vector>
using namespace std;

int getArray(vector<int> &arr){
    int n;
    cout<<"enter size"<<endl;
    cin>>n;

    for(int i=0;i<n;i++) {
        int e;
        cin>>e;
        arr.push_back(e);
    }

    return n;
}

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

void reverseArray(vector<int> &arr, int n){
//     0 1 2 3 4 5
    // 9 8 7 6 5 4 n=6
    // 4 5 6 7 8 9
    for(int i=0;i<=n/2;i++){
        swap(arr[i],arr[n-1-i]);
    }
    for(int i:arr) cout<<i<<" ";
    cout<<endl;
}

int main(){
    vector<int> arr;
    int n=getArray(arr);
    reverseArray(arr, n);
    
    return 0;
}
