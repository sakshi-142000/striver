#include <iostream>
#include <vector>
using namespace std;

int getArray(vector<int> &arr){
    int n;
    cout<<"enter size"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }
    return n;
}

float findMedian(vector<int> &arr1, vector<int> &arr2, int n, int m){
    // eg arr1: 1 3 4 7 10 12  arr2: 2 3 6 15

    // now trick is n+m can be either odd or even
    // if even get the (n+m)/2th element first and then add the (n+m)/2 +1 element then
    // if odd then we need to return the (n+m)/2 +1 element as median

    int i=0, j=0, count=0, median=0;
    int compareWith=(n+m)/2;
    cout<<"compareWith "<<compareWith<<endl;
    while(count<compareWith){
        if(arr1[i]<=arr2[j]){
            
            count++;
            cout<<"if running, count"<<count<<endl;
            if(count==compareWith and (n+m)%2==0){
                median+=arr1[i];
            }
            i++;
        }
        else{
            
            count++;
            cout<<"else running, count"<<count<<endl;
            if(count==compareWith and (n+m)%2==0){
                median+=arr2[j];
            }
            j++;
        }
    }
    cout<<"arr1[i]<<arr2[j]<<count<<median"<<arr1[i]<<arr2[j]<<count<<median<<endl;
    cout<<"median"<<median<<endl;
    if(arr1[i]<=arr2[j]) median+=arr1[i];
    else median+=arr2[j];

    if((n+m)%2==0) return median/(float)2;
    else return median;


    
}

int main(){
    vector<int> arr1, arr2;
    int n=getArray(arr1);
    int m=getArray(arr2);

    cout<<findMedian(arr1, arr2, n, m)<<endl;


    return 0;
}