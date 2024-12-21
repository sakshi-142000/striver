#include <iostream>
using namespace std;

int fibonacciRecursive(int n){
 if (n == 0 || n == 1) return n;
 else return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

int fibonacciNonRecursive(int n){
    int temp0=0;
    int temp1=1;
    int i=2;
    while (i<= n){
        cout << endl;
        int temp= temp1;
        temp1= temp1 + temp0;
        temp0 = temp;
        cout <<  temp1 << "\t"; 
        i++;
    }

    return temp1;

}

// 0 1 2 3 4 5 6 7 8 
// 0 1 1 2 3 5 8 13 

int main(){
    int n;
    cin>>n;
    cout<<fibonacciRecursive(n)<<endl;
    cout<< "without recursion" << endl<< fibonacciNonRecursive(n)<< endl;
    return 0;
}