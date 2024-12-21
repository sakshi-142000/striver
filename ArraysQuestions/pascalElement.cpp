#include <iostream>
using namespace std;

// given n and r, find the rth element of row r in pascals triangle
/*
1> 1
2> 1 1
3> 1 2 1
4> 1 3 3 1
5> 1 4 6 4 1
6> 1 5 10 10 5 1
................

6th rows 3rd element>> 10 
n-1 C r-1 (5 rows down 1 element right)

*/ 
int fact(int n){
    int result=n;
    for(int i=1;i<n;i++){
        result*=i;
    }
    return result;
}

int main(){
    int n, r;
    cout<<"enter n and r "<<endl;
    cin>>n >>r; 

    // brute force approach to solve n-1 Cr-1 will be to use factorial function
    int result= fact(n-1)/(fact(r-1)*fact(n-r));

    // optimal approach to find n-1 C r-1 
    // n=6 r=4
    // 5C3 : iterating from 1 to 3 ofcourse for r! but for n!/(n-r)!, only iterating from n, r times
    // 5*4*3/ 3*2*1
    cout<<"nth row, rth element of pascal's triangle is: "<<result<<endl;
    int result2=n-1; // result=5
    for(int i=1;i<r-1;i++){
        result2*=(n-1-i);
        result2/=i;
    }
    result2/=r-1;
    cout<<result2<<endl;
}