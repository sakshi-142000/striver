#include <iostream>
#include <vector>
using namespace std;

vector<int> getArray(){
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        arr.push_back(e);
    }

    return arr;
}

//void partition(vector<int> arr,)


int main(){
    vector<int> arr;
    vector<int>arr=getArray();
    //partition(arr,)
    return 0;
}

