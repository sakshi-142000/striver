#include <iostream>
#include <vector>
using namespace std;



int main(){

    int n=3;
    int arr[3]={3,40,5};
    //making power set for printing subsets of arr

    for(int si=0; si<(1<<n); si++){
        vector<int> subset; 
        for(int bit=0; bit<n ; bit++){
            if(si & 1<<bit) subset.push_back(arr[bit]);
        }

        for(auto i: subset) cout<< i<<" ";
        cout<<endl;
    }

    return 0;
}