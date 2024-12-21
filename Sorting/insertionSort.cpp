#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int getElements(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        arr.push_back(e);
    }
    return n;
}

void swap(int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void insertionSort(int n){
    for(int i=1;i<n;i++){
        int focus=i; //element to be inserted
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[j+1]){
                swap(j,j+1);
            }
            else break;
        }
    }
}

void printElements(){
    for(auto i: arr) cout<<i<<" ";
    cout<<endl;
}

int main(){
    int n=getElements();
    insertionSort(n);
    printElements();
    return 0;
}