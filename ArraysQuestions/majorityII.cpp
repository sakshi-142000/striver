#include <iostream>
#include <vector>
#include <map>
using namespace std;

// given an array of size n find the element that occured more than n/3 times
// there will be atmost 2 elements that can occur more than n/3 times in the array
// 1 1 1 2 2 6 2 2 1 4 5
// 0 1 2 3 4 5 6 7 8 9 10 // n=11 // >n/3 ~~ 4
// 1 -> 4 times
// 2 -> 4 times // 8 elements already covered, remaining 3 elements can't be the majority II element

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

vector<int> majorityIIBetter(vector<int> &arr, int n){
    // using hashmap to store the count

    map<int, int> count;
    vector<int> result;

    for(int i=0;i<n;i++){
        count[arr[i]]++; //initialising to 0 and incrementing the same time
        if(count[arr[i]]>n/3) result.push_back(arr[i]);
        if(result.size()==2) break;
    }

    return result;

    
}

vector<int> majorityIIBrute(vector<int> &arr, int n){
    // 1 1 1 2 2 6 2 2 1 4 5

    // traversing the array to check the count of every element

    vector<int> result;
    
    for(int i=0;i<n;i++){
        cout<<"i= "<<i<<endl;
        if(result.empty() || result[0]!=arr[i]){
            int count=0;
            for(int j=0;j<n;j++){
                if(arr[i]==arr[j]) count++;
                if(count>n/3){
                    result.push_back(arr[i]);
                    break;
                }
                
            }
        }
        if(result.size()==2) break;
        
    }

    return result;
}

vector<int> majorityII(vector<int> &arr, int n){
    int element1=INT_MIN;
    int element2=INT_MIN;
    int count1=0;
    int count2=0;

    // moores voting algorithm, please revise the majorityI element question
    // doing cancellation on count if we find a element which is not element1 or element2 and on zero updating element

    for(int i=0;i<n;i++){
        if(count1==0 and arr[i]!=element2){ //element1 and element2 can not be the same
            element1=arr[i];
            count1++;
        }
        // why else if, you can only use arr[i] in one of the all conditions
        else if(count2==0 and arr[i]!=element1){
            element2=arr[i];
            count2++; 
        }
        else if(arr[i]==element1) count1++;
        else if(arr[i]==element2) count2++;

        else{
            // if both count1 and count2 are not zero and the new element is not equal to anyone of the two then cancel
            count1--;
            count2--;
        }
    }
    count1=0; 
    count2=0;

    vector<int> result;

    for(int i=0;i<n;i++){
        if(arr[i]==element1) count1++;
        else if(arr[i]==element2) count2++;
    }

    if(count1>n/3) result.push_back(element1);

    if(count2>n/3) result.push_back(element2);

    return result;

}



int main(){
    vector<int> arr;
    int n=getArray(arr);
    // vector<int> result = majorityII(arr, n);
    // vector<int> result = majorityIIBrute(arr, n);
    vector<int> result = majorityIIBetter(arr, n);
    for(auto i: result) cout<<i<<" ";
    cout<<endl;
    
    return 0;
}
