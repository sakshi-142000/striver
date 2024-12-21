#include <iostream>
using namespace std;

int main(){
    int n = 1000000;
    bool arr[n];

    for (int i = 2; i< n ; i++){
        arr[i] = 1;
    }

    // build seive

    for (int i = 2; i*i<=n ; i++){
        if(arr[i] == 1){
            for (int j = i*i ; j< n ; j=j+i){
                arr[j] = 0;
            }
        }
    }
    int p;
    cout<<"enter numer to check"<<endl;
    cin>>p;

    if (arr[p]==1) cout<<"prime"<<endl;
    if (arr[p]==0) cout<<"not prime"<<endl;

    return 0;
}

