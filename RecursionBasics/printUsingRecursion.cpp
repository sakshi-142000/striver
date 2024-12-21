//#include <bits/stdc++.h>

#include <iostream>
using namespace std;

void PrintN(int n){
    if (n==0) return;

    /*in ascending*/

    // else {
    //     PrintN(n-1);
    //     cout<<n<<"\t";

    // }

    //in descending order

    else {
        cout<<n<<"\t";
        PrintN(n-1);
    }

}

int main(){
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    PrintN(n);
    return 0;
}



