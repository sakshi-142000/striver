#include <iostream>
#include <vector>
using namespace std;


// problem statement:
// given array arr where i flower blooms on arr[ith] day
// [7 7 7 7 13 12 11] 
// 1st flower blooms on 7th day, 2nd, 3rd, 4th as well on 7th day, 5th flower blooms on 13th day and so on
// you have to make m bouquets each with k flowers, lets say m=2 k=3, so you need 6 flowers for that
// condition is you can only take adjacent flowers, 


// prob: retun the minimum day where we can make m bouquet with k flowers


// thought process: on the maxE day, eg 13 here, all the flowers will be bloomed, 7(size of array)>6(number of flowers required to make the bouquet, m*k), possible
// range of answers will be minE to maxE
// check if you are able to make bouquet on the minimim blooming day that is provided to you, eg here 7
// and then go till the maxE 

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

vector<int> getMinMax(vector<int> &arr, int n){
    vector<int> minMax={INT_MAX, INT_MIN};
    for(int i=0;i<n;i++){
        minMax[0]=min(minMax[0],arr[i]);
        minMax[1]= max(minMax[1], arr[i]); 
    }
    return minMax;
}

bool isBouquetPossible(vector<int> &arr, int n, int day, int m, int k){
    //check if on a given blooming day you can make m bouquets each with k flowers
// [7 7 7 7 13 12 11 7]  day 12
    int count=0, bouquet=0; //count of adjacent flowers we can get and number of bouquets possible till now
    for(int i=0;i<n;i++){
        
        if(arr[i]<=day){
            //flower bloomed
            count+=1;
        }
        else{
            //flower not bloomed, so adjacency broke
            bouquet+=(count/k);
            count=0;
        }
    }
    //for the last day, what if we did not go to else
    bouquet+=(count/k); 

    if(bouquet>=m) return true;
    else return false;
}

int BSForMinDay(vector<int> &arr, int n, int m, int k){
    int low=getMinMax(arr, n)[0];
    int high=getMinMax(arr,n)[1];

    if(m*k> n) return -1; 

    while(low<=high){
        int mid=(low+high)/2;
        if(!isBouquetPossible(arr, n, mid, m, k)) {
            //if mid is not possible all the day below mid will also be not possible, eliminate the range from low to mid
            low=mid+1;
        }
        else {
            // mid is possible, eliminate the range from mid+1 to high
            // and check for more minDay in the range low to mid-1;
            high=mid-1;
        }
    }

    return low; //why low, when we started low was not possible, but high was possible and at the end of the function, high will not be possible but low will be psosible

}

int main(){

    vector<int> arr;
    int n=getArray(arr);

    int m, k;
    cin>>m>>k;
    int minE=getMinMax(arr, n)[0];
    int maxE=getMinMax(arr,n)[1];
    int day=minE;
    int minDay=-1;
    while(day<=maxE){
        if(isBouquetPossible(arr, n, day, m, k)){
            minDay=day;
            break;
        } 
        day++;
    }

    //cout<<minDay;


   cout<<BSForMinDay(arr, n, m, k);
    
    // isBouquetPossible()

    return 0;
}