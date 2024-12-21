#include <iostream>
#include <vector>
using namespace std;

// Problem Statement: given a array of +ve, -ves and 0s calculate the max subarray product that we can get. 


// eg: 3 2 -1 4 -6 3 -2 6
// max product subarray: 4 -6 3 -2 4



int getArray(vector<int> &arr){
    int n;
    cout<<"enter size of the array"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }
    return n;
}

int maxSubarrayProductBrute(vector<int> &arr, int n){
    // eg: 3 2 -1 4 -6 3 -2 6
    // approach: generate all the subarrays, calculate product of each subarray and store the max in ans var

    int maxProd=INT_MIN; //initially

    for(int i=0;i<n;i++){
        int prod=1;
        for(int j=i;j<n;j++){
            prod*=arr[j];
            maxProd=max(maxProd, prod);
            // cout<<arr[j]<<" "<<prod<<" "<<maxProd<<"          ";
        }
        cout<<endl;
    }

    return maxProd; 
}

int maxSubarrayProductOptimal(vector<int> &arr, int n){
    // eg: 3 2 -1 4 -6 3 -2 6
    // approach: traverse from both back and front so that at any iteration, we can get both the product from suffix and prefix, it helps when we have negatives in the array, for a negative numbe, we can either have the max product on prefix or from suffix

    int maxProd=INT_MIN; //initially
    int prefixProd=1;
    int suffixProd=1;
    for(int i=0;i<n;i++){
        if(prefixProd==0) prefixProd=1; //start again
        if(suffixProd==0) suffixProd=1; //start again 

        prefixProd*=arr[i];
        suffixProd*=arr[n-1-i]; //from back

        maxProd=max(maxProd, max(prefixProd, suffixProd));

        cout<<"maxProd: "<<maxProd<<" prefixProd "<<prefixProd<<" suffixProd "<<suffixProd<<" arr[i] "<<arr[i]<<endl;

        
    }

    return maxProd; 
}





int main(){
    vector<int> arr;
    int n=getArray(arr); 
    cout<<maxSubarrayProductOptimal(arr, n)<<endl;
}


