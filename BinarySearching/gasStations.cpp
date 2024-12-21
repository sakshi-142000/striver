#include <iostream>
#include <vector>
using namespace std; 

int getArray(vector<int> &arr){
    int n;
    cout<<"enter size"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }

    return n;
}

// problem statement: given an array representing coordinates of n gas stations, given k gas stations, 
// add the gas stations in such a way that the max distance between any two gas stations is minimum

// eg : [1 13 17 23 ] k= 5 add 5 gas stations
// note that adding stations to the extremes of array is useless as it will not give the minimum distance rather we would need to add the gas stations 
// create a new array to store how many elements(gas stations) we are adding between two consecutive gas stations and return the max space

long double minMaxDistance(vector<int> &arr, int n, int k){
    // eg 1 13 17 23 // 3 spaces
    vector<int> howManyGasStations(n-1, 0); //we have n-1 spaces between n gasstations and initially none of them are holding the additional gas stations
    for(int section=1;section<=k;section++){
        long double maxDistance=-1; //this var will hold what is the max distance that we can get between any two consecutive gas stations
        int index=-1; //at which space we are getting the maxDistance //this index is for howManyGasStations array

        for(int i=0;i<n-1; i++){
            long double sectionLength= (long double) (arr[i+1] - arr[i])/ (long double) (howManyGasStations[i]+1); //note that type caseting is very important
            if(sectionLength > maxDistance) {
                maxDistance = sectionLength; 
                index = i; 
            }
        }
        // we found the maxDistance therefore add the gasStation in that index
        howManyGasStations[index]++; 
    }
    long double answer=-1; // get the answer now, what is the maximum distance between any two consecutive gasStations 
    for(int i=0;i<n-1;i++){
        long double sectionLength= (long double)(arr[i+1]-arr[i]) / (long double) (howManyGasStations[i]+1); 
        answer=max(sectionLength, answer);
    }
    return answer;

}
int main(){
    vector<int> arr;
    int n=getArray(arr);

    int k; 
    cout<<"enter the gas stations to add"<<endl;
    cin>>k;

    cout<<minMaxDistance(arr, n, k);
    return 0;
}
