#include<iostream>
#include <vector>
using namespace std;

void getArray(vector<vector<int> > &arr, int n, int m){
    for(int i=0;i<n;i++){
        vector<int> t;
        for(int j=0;j<m;j++){
            int e;
            cin>>e;
            t.push_back(e);
        }
        arr.push_back(t);
    }
}

void setMatrix(vector<vector<int> > &arr, int n, int m){
    // better approach includes making a row and a coloumn matrix to store the corresponding row and column 
// 1 1 1   row[]={1, 0, 0}
// 0 1 1   col[]={0, 1, 1}
// 0 1 1 
    vector<int> row(m,1);
    vector<int> coloumn(n,1); 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0) {
                //set row and coloumn to 0
                row[j]=0;
                coloumn[i]=0;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[j]==0 or coloumn[i]==0) {
                arr[i][j]=0;
            }
        }
    }

}

void printArray(vector<vector<int> > &arr, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

int main(){

    int n, m;
    cin>>n>>m; //n X m matrix
    vector<vector<int> > arr;
    getArray(arr, n, m); 
    setMatrix(arr, n, m);
    printArray(arr, n, m);



}