#include <iostream>
#include <vector>
using namespace std;

// best time to buy and sell stocks
//given a array containing stock prices, find the day when we should buy and sell stocks
// return the maximum profit

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

int maximumProfit(vector<int> &arr, int n){
    // approach is to prestoring the minimum value of stock price for buying for the index when you are selling the stock
    // for example, you are selling the stock at index 4, now look for the minimum value of stockprice before the index 4

    //   [ 7 1  4 6 2]
    //   [ 0 -6 3 5 1]// temp profit at each index
    int minI=arr[0]; //lets say the minimum stockprice is arr[i]
    int maxProfit=0; //initially

    for(int i=1; i<n;i++){
        int profit=arr[i]-minI;// calculating the profit that we can make at index i
        maxProfit= max(profit, maxProfit);
        minI=min(minI, arr[i]); //dp 
    }

    return maxProfit;

}


int main(){
    vector<int> arr;
    int n = getArray(arr);
    cout<<maximumProfit(arr,n)<<endl;
    
    return 0;
}
