#include <iostream>
#include <vector>
#include <set>
using namespace std;

//Longest consecutive Subsequence 
//  102 4 100 1 101 3 2 1
// subsequence will be 100 101 102 (need not to be in order), 1 2 3 4
// return the longest length of the subsequence, 4 here

int getArray(vector<int> &arr){
    int n;
    cout<<"enter size"<<endl;
    cin>>n;

    for(int i=0;i<n;i++) {
        int e;
        cin>>e;
        arr.push_back(e);
    }

    return n;
}

int longestSubsequenceLength(vector<int> &arr, int n){
    // test example: [102 4 100 1 101 3 2 1]
    int maxl=1; // initially obviously
    // traversing via each element,x and checking for x+1
    for(int i=0;i<n;i++){
        int x=arr[i];
        int count=1; //for x 
        for(int j=0;j<n;j++){
            if(arr[j]==x+1) {
                //consecutive found
                count+=1;
                x=x+1;
                j=0;
            }
        }
        maxl=max(maxl,count);
    }  

    return maxl; 


}

int longestSubsequenceLengthBetter(vector<int> &arr, int n){
    // test example: [102 4 100 1 102 101 2 3 2 1]
    // step1: sort : 1 1 2 2 3 4 100 101 102 102 
    //traverse through the entire sorted array and and increase the count if previousSmallest is equal to arr[i]-1 

    sort(arr.begin(), arr.end());

    int previousSmallest= INT_MIN;
    int longestSubsequence=1; //initially

    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]-1 == previousSmallest){
            count+=1;
            previousSmallest=arr[i];
        }

        else if (arr[i]-1!= previousSmallest){
            count=1; //start the new subsequence
            previousSmallest=arr[i];
        }

        longestSubsequence=max(longestSubsequence, count);
    }

    return longestSubsequence; 


}

int longestSubsequenceLengthOptimal(vector<int> &arr, int n){
    // test example: [102 4 100 1 102 101 2 3 2 1]

    
    set<int> st;
    for(int i: arr) st.insert(i); // this will now only store unique elements

    int longestSubsequencelength=1;
    int count=1;
    int i= *(st.begin());
    while(st.find(i-1)==st.end()){
        // confirming i is the start of sequence
        i+=1;
        while(st.find(i)!=st.end()) {
            count++;
            i++;
        }
        longestSubsequencelength=max(longestSubsequencelength, count);           
    }

    return longestSubsequencelength;

}




int main(){
    vector<int> arr;
    int n=getArray(arr);
    cout<<longestSubsequenceLengthOptimal(arr,n)<<endl;
    
    return 0;
}
