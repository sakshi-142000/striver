#include <iostream>
using namespace std;

/* sum of digits

input = 1234; output= 1+2+3+4 = 10
get the digits first by using modulo 
and add the digits using a simple loop

*/

int SODwithRecursion(int n){
    if (n == 0) return 0;
    else {
        return n%10 + SODwithRecursion(n/10);
    }
}

int SODwithoutRecursion(int n){
    int result=0;
    for (int i = n ; i!=0 ; i = i/10){
        int digit = i % 10 ; 
        result += digit; 
    }

    return result;
}



int main(){
    int n;
    cin>> n;

    cout<<SODwithoutRecursion(n)<<endl;
    cout<<SODwithRecursion(n)<<endl;
    
    return 0;
}