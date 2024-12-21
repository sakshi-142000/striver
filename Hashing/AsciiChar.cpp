#include <iostream>
using namespace std;

int main(){

    // 0-31: control chars, whitespaces and other things
    //32: space
    cout<<"special chars"<<endl;
    for(int i = 33; i<48 ; ++i){
        cout<<(char)i<< "\t";
    }
    cout<<endl<<"numbers"<<endl;
    for(int i=48;i<57;++i){
        cout<<(char)i<<"\t";
    }
    cout<<endl<<"Uppercase alphabets"<<endl;
    for(int i=65;i<91;i++){
        cout<<(char)i<<"\t";
    }
    cout<<endl<<"Lowercase alphabets"<<endl;
    for(int i=97;i<123;i++){
        cout<<(char)i<<"\t";
    }
    return 0;
}