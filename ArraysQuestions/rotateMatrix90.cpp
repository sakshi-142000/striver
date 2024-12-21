#include <iostream>
#include <vector>
using namespace std;

//given square matrix (n X n), rotate the matrix by 90 degrees

void getMatrix(vector<vector<int> > &arr, int n){

    for(int i=0;i<n;i++){
        vector<int> t;
        cout<<"enter row "<<i<<endl;
        for(int j=0;j<n;j++){
            int e;
            cin>>e;
            t.push_back(e);
        }
        arr.push_back(t);

    }
    cout<<endl;
}

void swapElements(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

void rotateArrayOptimal(vector<vector<int> > &arr, int n){

    // Inplace algorithm.

    /*
        1  2  3  4       1 5 9 13           13 9  5 1 (reverse coloumn)
        5  6  7  8       2 6 10 14          14 10 6 2
        9  10 11 12      3 7 11 15          15 11 7 4
        13 14 15 16      4 8 12 16          1  6 12 8 4

        matrix >>>>> transpose >>> reversing the transpose
    
    */ 

    // step1: get the transpose, only looping on the other side of diagonal

    for(int i=0;i<n-1;i++) // last index not needed
    {
        for(int j=i+1;j<n;j++){
            // swapping arr[i][j] and arr[j][i]
            // int temp=arr[i][j];
            // arr[i][j]=arr[j][i];
            // arr[j][i]= temp;

            swapElements(arr[i][j], arr[j][i]);
        }
    }

    for(int i=0;i<n;i++){
        reverse(arr[i].begin(), arr[i].end());
    }

}



vector<vector<int> > rotateArray(vector<vector<int> > &arr, int n){

    // brute approach uses a different matrix to store the result. sc: O(n^2)
    vector<vector<int> > result(n, vector<int>(n,0));

    /*
        1  2  3  4          13 9  5 1
        5  6  7  8          14 10 6 2
        9  10 11 12         15 11 7 4
        13 14 15 16         16 12 8 4
    
    */ 

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            result[i][j]=arr[n-1-j][i];
        }
    }

    return result;
}

void printArray(vector<vector<int> > &arr, int n){

      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int> > arr;
    int n;
    cin>>n;
    getMatrix(arr, n);
    // vector<vector<int> > result = rotateArray(arr, n);
    // printArray(result,n);

    rotateArrayOptimal(arr, n);
    printArray(arr,n);
  
    return 0;
}