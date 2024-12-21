#include <iostream>
using namespace std;

int main(){
    int hashArray[1000000]={0};//initialising all the array elements as 0
    cout<<"enter the array size"<<endl;
    int n, max= 0;
    cin>> n;
    int arr[n];
    for(int i= 0;i<n;i++){
        cin>>arr[i];
        if(max<arr[i]) max = arr[i];
        hashArray[arr[i]] +=1;
    }
    for(int i =0;i<max+1;i++){
        cout<<hashArray[i]<<endl;
    }

    return 0;
}