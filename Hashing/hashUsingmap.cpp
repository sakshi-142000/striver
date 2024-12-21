#include <iostream>
#include <map>
#include <string>

using namespace std;


int main(){
    map<int, int> hashMap;
    vector <int> inArr;
    int n;
    cout<<"enter the array size"<<endl;
    cin>>n;

    //taking input array
    cout<<"enter the array values"<<endl;
    for(int i =0; i<n ; ++i){
        int value;
        cin>>value;
        inArr.push_back(value);
    }

    vector<int> :: iterator it;

    for ( it = inArr.begin(); it!= inArr.end(); ++it){
        hashMap[*it] ++; 
        //amazing amazing work here !!!!!
        // don't get confused here, c++ automatically creates a new key value pair and assigns the value of the key *it to 0 (default), when you do increment it increments the value

    }


    //print the map

    map<int, int> :: iterator it2;

    for (it2 = hashMap.begin(); it2!=hashMap.end() ; it2++){
        cout<<"key: "<<(*it2).first << " value: "<<it2->second<<endl;
    }



    return 0;
}