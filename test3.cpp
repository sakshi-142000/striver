#include <iostream>
using namespace std;

int main(){
    int n=5;
    cout<<" ";
    for(int i=0;i<n;i++){

        for(int space=n-i-1;space>0;space--){
            cout<<" ";
        }
        for(int j=0;j<2*i+1;j++){
            cout<<"* ";
        } 
        cout<<endl;
    }
    return 0;
}