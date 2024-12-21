#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int getArray(vector<int> &arr){
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }
    return n;
}

int maxElement(vector<int> &arr, int n){
    int maxE=INT_MIN;
    for(int i=0;i<n;i++) maxE=max(maxE, arr[i]);
    return maxE;
}

int calculateHours(vector<int> &arr, int n, int mid){
    int totalHours=0;
    for(int i=0;i<n;i++){
        totalHours+=ceil((double)arr[i]/(double)mid); //ceil takes double, if you give it will not give correct result
    }
    return totalHours;
}

int minimumRateToEatBananas(vector<int> &arr, int n, int hours){
    // problem: given a array, each element representing pile of bananas, and koko has to complete eating all the bananas in h hours, 
    // how many bananas should she eat in one hour so that she can complete all the bananas in atmost h hours. 
    //  [7, 15, 6, 3], h = 8
    // its like if she is eating 3 bananas in 1 hour then 
    // for 7 banans she will eat in 7/3 hour obv take ceil
    // 15 banans she will complete in 15/3 hours and ......
    // all the hours sum <=h
    // smallest divisor that should divide all the numbers so that sum of all <=threshold


    int low=1, high=maxElement(arr, n); // min she can eat 1 banana per hour and max she can eat 15 bananas per hour, but we want the minimum number of banans she can eat in an hour so that in total the number of hours she takes to complete all the bananas do not exceed h hours
    
    while(low<=high){
        int mid=(low+high)/2;
        if(calculateHours(arr, n, mid)<=hours){
            //can she eat more less banana in 1 hour and still the count of all the hours taken for each pile does not exceed h?? 
            high=mid-1;
        }
        else if(calculateHours(arr, n, mid)>hours) {
            //increase the banana count, so that she take less hours
            low=mid+1;
        }
    }

    return low;
}


int main(){
    vector<int> arr;
    int n=getArray(arr);
    int hours;
    cout<<"enter the hours in which koko should complete eating all the bananas"<<endl;
    cin>>hours;
    cout<<minimumRateToEatBananas(arr, n, hours)<<endl;

    return 0;
}