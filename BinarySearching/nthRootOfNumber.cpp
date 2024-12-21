#include <iostream>
using namespace std;

int findPower(int n, int x){
    //function to get n^x
    int ans=1; //intially

    while(x>1){
        if(x%2==0) x=x/2;
        else {
            x=x/2;
            ans*=n;
        }
        n*=n;
    }
    return ans=ans*n;;
}


//problem statement: given n and m,
/*
Given two numbers N and M, find the Nth root of M. 
The Nth root of a number M is defined as a number X such that when X is raised to the power of N, it equals M. 
If the Nth root is not an integer, return -1.

eg given 2 16, you have to raise 4^2 to get 16, so 2 root of 16 is 4 here 

*/
int nthRootOfMUsingBS(int n, int m){
    int low=1, high=m;
    while(low<=high){
        int mid=(low+high)/2;
        if(findPower(mid, n)==m) return mid;
        else if(findPower(mid, n)>m) high=mid-1;
        else low=mid+1;
    }

    return -1;
}



int nthRootOfMBrute(int n, int m){
    int i=1;
    for(i=1;i<=m;i++){
        if(findPower(i,n) == m) return i;
        else if(findPower(i,n) > m) break;
    }
    return -1; //if none found in the above loop
}
int main(){
    int n, m;
    cout<<"enter n amd m, ref n is the power and m is the number"<<endl;
    cin>>n >>m;
    cout<<nthRootOfMUsingBS(n,m)<<endl;

    return 0;
}