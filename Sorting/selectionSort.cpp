#include<iostream>
#include<vector>
using namespace std;

vector<int> arr; //globally declared

int getElements(){
    cout<<"enter size of array"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        arr.push_back(e);
    }
    return n;
}

void printArray(){
    for(auto i: arr) cout<<i<<" ";
    cout<<endl;
}
void swap(int i, int minIndex){

    //swapping using xor
        // num1=num1^num2;
        // num2=num1^num2;
        // num1=num1^num2

        // note that xor logic is all good but if in case i and minIndex are same, the minimum is at ith index itself then this will return 0
        // if(i!=minIndex){
        //     arr[i]=arr[i]^arr[minIndex];//12^9
        //     arr[minIndex]=arr[i]^arr[minIndex];//12^9^9=12
        //     arr[i]=arr[i]^arr[minIndex];
        // }

        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;

}

void selectionSort(int n){
    // 12, 23, 10, 9, 67, 34
    //select the minimum and swap and do it for the rest of the unsorted array
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]) minIndex=j;
        }
        swap(i,minIndex);//pass the indices
        
    }
}

void bubbleSort(int n){
    int bubble=n-1;//last index to go to
    // 12, 23, 10, 9, 67, 34
    int i=0;
    while(i<bubble){
        if(arr[i]>arr[i+1]) swap(i,i+1);
        if(i+1==bubble) {
            //start again
            i=0;
            bubble-=1; 
        }
        else i++;
    
    }
}

int main(){
    int n= getElements();
    printArray();
    //selectionSort(n);
    bubbleSort(n);
    printArray();


    return 0;
}