#include <iostream>
#include <vector>
using namespace std;

//given number from 1 to N with one number missig, find the missing number

int getArray(vector<int> &arr){
    int n;
    cout<<"enter n"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        int e;
        cin>>e;
        arr.push_back(e);
    }
    return n;
}

//BruteForce approach, using nested for loops

void MissingNumberBrute(vector<int> &arr,int n){
    // 1 2 4 5 6 7 8 , 3 is the missing number
    // O(n^2)
    for(int i=1;i<n;i++){
        //checking for each number from 1 to N
        int flag =0; // initially flag for i is 0
        for(int j=0;j<n;j++){
            if(arr[j]==i){
                //number found 
                flag=1;
                break;
            }
        }

        if(flag==0) {
            cout<<i<<" "; //if number not found in inner loop then that num is missing
            break;
        }
    }
}

// better approach >> Hashing


void MissingNumberBetter(vector<int> &arr,int n){
    // TC: O(2n)
    //SC: O(n+2)~ O(n): hash array
    // 1 2 4 5 6 7 8 , 3 is the missing number
    // do hashing 
    //N=n+1
    vector<int> hash(n+2,0);// initialising every number's hash value to 0
    // hash indices: 0 1 2 3 4 5 6 7 8
    // hash values:  0 0 0 0 0 0 0 0 0
    // after loop:   0 1 1 0 1 1 1 1 1
    for(int i: arr){
        hash[i]=1;
    }
    for(int i=1;i<n+2;i++){
        if(hash[i]==0) cout<<"Missing number: "<<i<<endl;
    }
  
}

void MissingNumberOptimal1(vector<int> &arr,int n){
    // 1 2 4 5 6 7 8 , 3 is the missing number
    // using summation as optimal way
    // TC: O(n), SC: O(1)
    long sumN= (n+2)*(n+1)/2;
    long sum=0;
    for(int i:arr) sum+=i;

    cout<<"Missing number optimal : " << sumN-sum <<" "<<endl;  
}


void MissingNumberOptimal2(vector<int> &arr,int n){
    // 1 2 4 5 6 7 8 , 3 is the missing number
    // using XOR approach as optimal way
    // best approach as there is no overflow issue with sum, 
    // TC: O(n) SC: O(1)
    int xorv=0; //doing xor with any number will be that  number itself

    for(int i=0;i<n;i++){
        xorv=xorv^(i+1)^arr[i];
    }

    xorv= xorv^(n+1);
    cout<<"Missing number optimal 2 : " << xorv <<" "<<endl;
      
}


int main(){
    vector<int> arr;
    int n = getArray(arr);
    //MissingNumberBrute(arr,n);
    // MissingNumberBetter(arr,n);
    // MissingNumberOptimal1(arr,n);
    MissingNumberOptimal2(arr,n);
    return 0;
}