#include <iostream>
#include <vector>
using namespace std;

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

void leftRotateD(vector<int> &arr, int n){
    int d;
    cout<<"enter d"<<endl;
    cin>>d;

    d=d%n; // to ensure that if d is greater than n then it is also handled

    // 1 2 3 4 5 6
    //3 4 5 6 1 2
    vector<int> temp;
    for(int i=0;i<d;i++) temp.push_back(arr[i]);

    //shift to the left 
    for(int i=0;i<n-d;i++){
        arr[i]=arr[i+d];
    }

    //move back the elements from temp to array

    for(int i=0; i<d;i++){
        arr[n-d+i]=temp[i];
    }
    
}

void rightRotateD(vector<int> &arr, int n){
    int d;
    cout<<"enter d"<<endl;
    cin>>d;

    d=d%n;

    // 1 2 3 4 5 
    // d= 2
    // 4 5 1 2 3

    //store last elements to be moved into a new array
    //make space
    vector<int> temp;
    for(int i=n-d; i<n;i++) temp.push_back(arr[i]); // temp = [4,5]
    //shift to the right, do it from right to left
    for(int i=n-d-1; i>-1 ; i--){
        arr[i+d]=arr[i];
    }
    //moving back elements from temp to arr 
    for(int i=0;i<d;i++){
        arr[i]=temp[i]; //EASYYYYY
    }

}

void printArray(vector<int> &arr){
    for(int i: arr) cout<<i<<" ";
    cout<<endl;
}

int main(){

    vector<int> arr;
    int n=getArray(arr);

    leftRotateD(arr,n);
    printArray(arr);
    vector<int> arr1;
    int m=getArray(arr1);//overwriting again
    rightRotateD(arr1,m);
    printArray(arr1);
    return 0;
}