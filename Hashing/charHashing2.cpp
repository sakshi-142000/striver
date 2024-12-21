#include <iostream>
#include <string>
using namespace std;

int main(){
    
    //program to count the number of time a charater appeared in the string, can be a uppercase or lowercase 20189121
    
    cout<< "Enter any string uppercase or lowercase or number, anything \n";
    string s;
    cin>>s;
    int charHashArray [128] = {0};// 128 characters in ASCII 
    for(int i = 0; i<s.length(); i++){
        charHashArray[s[i]]+=1; // type casting will be done automatically
    }
    cout<<"enter number of queries"<<endl;
    int q;
    cin>>q;
    while(q>0){
        char c;
        cin>>c;
        cout<<c<<" appeared "<<charHashArray[c]<<" times"<<endl;
        q--;
    }


    return 0;
}