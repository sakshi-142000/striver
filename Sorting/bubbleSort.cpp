#include<iostream>
#include<vector>
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

void printElements(){
    for(auto i: arr){
        cout<< i <<" ";
    }
    cout<<endl;
}

void swap(int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void bubbleSort(int n){
    for(int i=n-1;i>0; i--){
        int didSwap=0;
        for(int j=0; j<i;j++){
            if(arr[j]>arr[j+1]) {
                swap(j, j+1);
                didSwap+=1;
            }   
        }
        if(didSwap==0) break;//optimising the algo, if in case no swaps are performed then that means array is now sorted
    }
}


int main(){
    int n= getElements();
    bubbleSort(n);
    printElements();
    return 0;
}