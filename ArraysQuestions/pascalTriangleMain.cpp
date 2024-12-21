#include <iostream>
#include <vector>
using namespace std;

/*

We have three question type in this topic:
q1: given n and r, print the rth element of nth row
q2: print nth row of pascal's triangle
q3: print the entire pascal's triangle

*/

int fact(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
}

int nRowRelement(int n, int r){
    //brute force approach would be to print the entire pascal triangle and then traverse in the array to get the rth element from nth row
    // as previously done, rth element of nth row can be found using n-1Cr-1, why because, we have to go n-1 down from 1st row and then move r-1 elements right 

    // bruteForce Approach of finding nCr; nCr=n!/r! * (n-r)!
    // int element = fact(n-1)/(fact(r-1) * fact(n-r)); // TC: O(n)+O(r)+O(n-r) ~~ 2O(n) 
    // return element;


    // optimal Approach, n-1Cr-1
    // n=6 n=4=>> 5C0 5C1 5C2 5C3 5C4 5C5
    //            1    5   10 10  5   1
    // TC: r-1
    int ans=1; //0th element 
    for(int i=1;i<r;i++){
        ans=ans*(n-i); // 5/1, 5*4/1*2, 5*4*3/1*2*3
        ans=ans/i;
    }

    return ans;
    
}

vector<int> printNRow(int n){
    //printing nth row of pascal's triangle
    // points to note: n row will contain n elements, 1st element will always be 1 ofc n-1C0 
    vector<int> row;
    row.push_back(1); // n-1C0
    int currentElement=1; //0th element
    // looping from r=1 to r=5
    for(int i=1;i<n;i++){
        // next element is derived from the currentElement
        currentElement=currentElement*(n-i); // for i=1: cE= 5; i=2 cE=5*4/2; i=3 cE= 5*4*3/2*3
        currentElement/=i; 
        row.push_back(currentElement); 
    }
    return row;

}

vector<vector<int> > printPascalTriangle(int n){
//  n=6

/*
i=1: 1
i=2: 1 1
i=3: 1 1*(3-1)/1 1*2*1/2 >> 1 2 1
i=4: 1 1*3/1 1*3*2/2 1*3*2*1/1*2*3  1 3 3 1
i=5: 1 1*4/1 1*4*3/2 1*4*3*3/1*2*3 ......
*/ 
    vector<vector<int> > PascalTriangle;
    for(int i=1; i<=n ;i++){
        //calculate row for i=1 to i=n
        vector<int> row;
        row.push_back(1);//0th element
        int temp=1;
        for(int j=1;j<i;j++){
            temp=temp*(i-j);
            temp=temp/j;
            row.push_back(temp);
        }
        PascalTriangle.push_back(row);


        
    }

    return PascalTriangle;
}



int main(){
    int n=6, r=4;
    // cout<<nRowRelement(n,r)<<endl;
    // vector<int> row= printNRow(2);
    // for(auto i: row) cout<<i<<" ";
    // cout<<endl;

    /*
        1
        1 1
        1 2 1
        1 3 3 1
        1 4 6 4 1
        1 5 10 10 5 1    
    */ 

    vector<vector<int> > pascal = printPascalTriangle(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<pascal[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}