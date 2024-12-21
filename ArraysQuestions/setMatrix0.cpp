#include <iostream>
#include <vector>
using namespace std;

void getArray(vector<vector<int> > &arr, int n, int m){

    for(int i=0;i<n;i++){
        vector<int> t;
        cout<<"enter row "<<i<<endl;
        for(int j=0;j<m;j++){
            int e;
            cin>>e;
            t.push_back(e);
        }
        arr.push_back(t);
    }
    cout<<endl;
}

void setRow0(vector<vector<int> > &arr, int i, int m){
    //setting row
    for(int k=0;k<m;k++){
        if(arr[i][k]!=0) arr[i][k]=-1;
    }
}

void setColoumn0(vector<vector<int> > &arr, int j, int n){
    //setting coloumn
    for(int k=0;k<n;k++){
        if(arr[k][j]!=0) arr[k][j]=-1;
    }
}

void setMatrix0brute(vector<vector<int> > &arr, int n, int m){

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                setRow0(arr,i,m); // n^3 approach
                setColoumn0(arr,j,n);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==-1){
                arr[i][j]=0;
            }
        }
    }
}

void printArray(vector<vector<int> > &arr, int n, int m){
    cout<<"resultant array: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}




int main(){
    vector<vector<int> > matrix;
    int n, m;
    cout<<"enter n and m"<<endl;
    cin>>n >>m;
    getArray(matrix, n, m);
    setMatrix0brute(matrix, n, m);
    printArray(matrix, n, m);
    return 0;
}
