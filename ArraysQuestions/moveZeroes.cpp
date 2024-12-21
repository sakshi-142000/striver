#include <iostream>
#include <vector>
using namespace std;

//brute force approach would be getting a new temp array and moving the non zero elements in it
// optimal approach would be using 2 pointers, one for the zero index and 

//[ 1 3 2 0 0 4 0 5 0]
// [1 3 2 4 5 0 0 0 0]

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

void moveZ(vector<int> &arr, int n){
    //bruteforce
    vector<int> temp;
    for(int i: arr) if(i!=0) temp.push_back(i); // temp only contatins non zeroes

    int nz= n-temp.size();
    for(int i=0; i<temp.size();i++){
        arr[i]=temp[i];
    }
    for(int i=temp.size();i<n;i++) arr[i]=0;


}

//using optimal 2-pointer approach

void moveZOptimal(vector<int> &arr, int n){
//[ 1 3 2 0 0 4 0 5 0]
// [1 3 2 4 5 0 0 0 0]

// keep a pointer at the oth position and swap the index with the non zeros to move to the rightnost right
// find the first 0 in the array
    int fz=-1; //index of the first zero
    for(int i=0;i<n;i++){
        if(arr[i]==0) {
            fz=i;
            break;
        }
    }
    if(fz!=-1){
    
        for(int i=fz+1;i<n;i++){
            if(arr[i]!=0) {
                arr[fz]=arr[i];
                arr[i]=0;
                fz++;
            }
        }
    }
}

void printArray(vector<int> &arr){
    for(int i: arr) cout<<i<<" ";
    cout<<endl;
}

int main(){

    vector<int> arr;
    int n = getArray(arr);
    //moveZ(arr,n);
    moveZOptimal(arr,n);
    printArray(arr);
    return 0;
}