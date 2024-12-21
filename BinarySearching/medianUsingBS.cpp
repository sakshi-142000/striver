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

int getMedian(vector<int> &arr1, vector<int> &arr2, int n, int m){
    int nm= (n+m)/2; //total elements that we need on the left of array half of (n+m); (n+m)/2
    int low=0, high=n; //applying BS on how many elements we can get from arr1, either we can take 0 elements from arr1 or all the n elements
    while(low<=high){
        int mid=(low+high)/2; //taking mid number of elements to check if it will work 
        int left1= arr1[mid-1]; // taking 0 - (mid-1), total of mid number of elements from array1
        int right1=arr1[mid]; //rest mid to n-1 elements for the right 
        int left2= arr2[nm-mid-1]; //we need this many elements from array2
        int right2 = arr2[nm-mid];

        //checking if the combination is valid
       if(left1<=right2 && left2<=right1){
            //perfect, we need to take mid number of elements from arr1 and rest nm-mid number of elements from arr2 
            return (max(left1, left2) + min(right1, right2))/2;
        }
        else if (left1>right2) {
            //decrease number of elements from arr1 so that we can increase elements from arr2
            high=mid-1;
        }
        else if (left2>right1) {
            low=mid+1; //increase number of elements from arr1
        }
    }

    return -1; //this will never happen but still   
}

int main(){
    vector<int> arr1, arr2;
    int n= getArray(arr1);
    int m=getArray(arr2);
    cout<<getMedian(arr1, arr2, n, m)<<endl;
    return 0;
}


