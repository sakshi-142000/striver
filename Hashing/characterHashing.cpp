#include <iostream>
#include <string>
using namespace std;

int main(){
    //giving a string of characters, for a given char, calculate it's frequency

    string s;
    cin>>s;
    //considering that string is of all lowercase characters (97-122)

    int charHash[26]={0};// 26 integer elements referencing to all the lowercase characters count, count of each alphabet initially initialised as 0
    for(int i= 0; i<s.length();i++){
        charHash[s[i]-'a']+=1;
    }
    cout<<"enter the number of queries"<<endl;
    int q;
    cin>>q;
    while(q>0){
        char c;
        cin>>c;
        cout<<c<<" occurs "<<charHash[c-'a']<<" times";
        q--;
    }
    return 0;
}