#include <iostream>
using namespace std;

int gcdBruteforce(int a, int b){
    /*
    approach: get the min of a and b and then start looping from the min(a,b) to 1 to get the greatest divisor
    */
   int min=b;
   if(a<b) min=a;

   for(int i=min ;i >=1 ;i--){
    if(a%i == 0 && b%i ==0) return i;
   }

   return 1;
}

int EuclidsGcd(int a, int b){
    /*
    Approach: subtract the min of two and assign the min and repeat the process till both the number becomes equal
    eg a=5, b=15 | b=10, a=5 | b= 5, a=5 return 5
    eg a = 15 b=4| a=11, b=4 | a=7, b=4 | a=3, b=4 | a=3, b= 1 | a=2,b=1 | a=1, b=1 return 1
    */

   while(a!=b){
    if(a>b){
        a=a-b;
    }
    else b=b-a;
   }
   return a;// return either a or b

}

int EuclidsOptimised(int a, int b){
    /*
    Approach: instead of substraction, go for modulo, more effective approach
    */

   while (a!=0 and b!=0){
    if(a>b) {
        a=a%b;
    }
    else b=b%a;
   }

   if(a==0) return b;
   else return a;

}

int main(){
    int a, b;
    cin>> a >> b;

    cout<<"gcd using bruteforce" << gcdBruteforce(a,b)<<endl;//O(min(a,b))
    cout<<"gcd using Euclids Algo" << EuclidsGcd(a,b)<<endl;// O(max(a,b))
    cout<<"gcd using Euclids optimised Algo" << EuclidsOptimised(a,b)<<endl;// time compexity: log(min(a,b))

    return 0;
}

