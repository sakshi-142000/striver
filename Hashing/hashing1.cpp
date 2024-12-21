#include <iostream>
#include <vector>
using namespace std;

//program to find the count of each number using hashing

int main(){

    int hash[1000000] = {0};//intialising array of size 10^6, not that here each index from 0 to 10^6-1 will represent a number
    int n;
    cout<<"enter the size of array \n";
    cin >> n;
    vector <int> arr(n);

    int max =0;

    for (int i = 0;i<n;i++){
        int num;
        cin>>num;
        arr.push_back(num);
        hash[num] +=1;
        if (num>max) max = num;
    }

    for(int i = 0; i <= max ;i++ ){
        cout<<"i = "<< i <<": " << hash[i]<<"\t";
    }

    return 0;
}
