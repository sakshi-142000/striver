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



// problem statement: given an array representing coordinates of stalls for cows, find the max of minimum distance between 2 cows 
// eg: 0 3 4 7 9 10 (note all sorted)
// k =4 cows
// we can place cows at min distance of 1 and 2 as well but that will not be the max.
// for minDistance of 3, we can place all the cows and if we extend it to 4 and we can only place 3 cows, therefore, max min distance between 2 cows is 3

//  0 3  4 7  9 10
// c1 c2 x c3 x c4 for min dist of 3 

bool isDistanceDPossible(vector<int> &arr, int n, int d, int k){

    int countCows=1, previousPosition=arr[0]; //intially assuming that the first cow is placed at index 0
    for(int i=1;i<n;i++){
        if(arr[i]-previousPosition>=d){
            countCows+=1;
            previousPosition=arr[i];
        }
    }
    if(countCows<k) return false;
    else return true;
}

int maxMinDistanceBS(vector<int> &arr, int n, int k){

    int low=1, high=arr[n-1]-arr[0];

    while(low<=high){
        int mid=(low+high)/2;
        if(isDistanceDPossible(arr, n, mid, k)){
            // if mid minimum distance is possible then eliminate the left because left will also be possible
            low=mid+1;
        }
        else high=mid-1; //decrease the distance
    }

    return high; //low was possible, so considering opposite polarity, after performing bs, now high will the be ans
}

// int maxMinDistance(vector<int> &arr, int n, int k){
//     int minDistance=1; //initially
//     int maxMinDistance=INT_MIN;
//     while(minDistance){
//         if(isDistanceDPossible(arr, n, minDistance, k)) {
//             maxMinDistance=max(maxMinDistance, minDistance);
//             minDistance++;

//         }
//         else break;
//     }
//     return maxMinDistance;
// }


int main(){
    vector<int> arr;
    int n=getArray(arr);
    
    int k; 
    cout<<"enter number of cows"<<endl;
    cin>>k;

    cout<<maxMinDistanceBS(arr, n, k);
    return 0;
}