#include <iostream>
using namespace std;

int main(){

    float var= 1.999999; //6 decimal places 

    cout<<var<<endl; // 1.22222 //only 5 places from decimal
    cout<<(double)var<<endl;
    cout<<(long double)var <<endl;

}