#include <iostream>
#include <vector>
using namespace std;

void getMatrix(vector<vector<int> > &arr, int n, int m){
    
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

void printSpiralMatrix(vector<vector<int> > &arr, int n, int m){

    /*
        1  2  3  4  5
        6  7  8  9  10
        11 12 13 14 15
        16 17 18 19 20
        21 22 23 24 25
    
    printing in spiral will be like: 1 2 3 4 5 10 15 20 25 24 23 22 21 16 11 6 7 8 9 14 19 18 17 12 13
    */ 

   int top= 0, left=0, right = m-1, bottom=n-1;
   vector<int> result;
// moving right from left to right

    while(left<=right and top<=bottom){

        for(int i=left;i<=right;i++){
            result.push_back(arr[top][i]);
        }
        top++;

        for(int i=top; i<=bottom; i++){
            result.push_back(arr[i][right]);
        }
        right--;
        // imagine you only have a one row matrix, and left is still less than right, but bottom is above top, in this corner scenario, this shouldn't get executed
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                result.push_back(arr[bottom][i]);
            }
        }
        
        bottom--;

        // corner scenario if we have only a one coloumn matrix, then right execeed the left of left but top<=bottom
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                result.push_back(arr[i][left]);
            }
            left++;

        }
        
    }

    for(auto i:result) cout<<i<<" ";

   
}

int main(){
    int n, m;
    cout<<"enter size of matrix"<<endl;
    cin>>n>>m;
    vector<vector<int> > arr;
    getMatrix(arr, n, m);
    printSpiralMatrix(arr, n, m);

    return 0;
}