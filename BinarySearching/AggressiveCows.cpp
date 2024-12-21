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

int maxMinDistance(vector<int> &arr, int n, int k){
    // range of minDistance can be from 1 to (max-min)
    int maxMinDistance= 0; 
    int minDistance=1; //lets go by taking distance at 1 intially
    int cows=1, previousPostion=arr[0]; //intially assume that the 

    while(minDistance){
        int cows=1, previousPostion=arr[0]; //intially assume that the 1st cow is placed at 0th index
        for(int i=0;i<n;i++){
            //tranversing through the array for check if we place k cows
            if(arr[i]-previousPostion>=minDistance){
                cows+=1;
                previousPostion=arr[i];
            }
        }
        if(cows<k) break;
        else {
            maxMinDistance= max(minDistance, maxMinDistance);
            minDistance++;
        }
        
        
    }

    return maxMinDistance;
}


int main(){
    vector<int> arr;
    int n=getArray(arr);
    
    int k; 
    cout<<"enter number of cows"<<endl;
    cin>>k;

    cout<<maxMinDistance(arr, n, k);
    return 0;
}