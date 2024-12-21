#include <iostream>
#include <map>
#include <string>
using namespace std;


int main(){
    map<int, string> map1;
    for(int i =0 ; i<5; ++i){
        //map1[i] = "value" + to_string(i);
        string value;
        cin>> value;
        map1[i] = value;
    }

    map<int, string> :: iterator it;

    for(it = map1.begin(); it!= map1.end() ;++it ){
        cout<< it->first << " "<< it->second<<endl;
    }
    return 0;
}