#include <iostream>
#include <vector>
using namespace std;

int getArray(vector<int> &arr){
    cout<<"enter array size"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }

    return n;
}

void swapElement(int &a, int &b){
    int t=a;
    a=b;
    b=t;
}

void GapMethod(vector<int> &arr1, vector<int> &arr2, int n, int m){
    // both pointers will initally have a gap of gap= ceil(n+m/2) and then will be decreasing the gap slowly till gap becomes 1
// {1 3 5 7} {0 2 6 8 9}
// gap= ceil(4+5/2) => 5
// left-> arr1[0] right-> left+gap

    int len=n+m;
    int gap=len/2 +len%2; // if gap is even then no need of ceil else add1
    int left=0;
    int right=left+gap;
    while(gap>0){
        while(right<len){
        //right does not crosses arr2
        if(arr1[left]>arr2[right-n]){
            swapElement(arr[left], arr[right-n]); 
        }
        left++, right++;
        }
        gap=gap
    }
    

}

void mergeWithoutExtraSpace(vector<int> &arr1, vector<int> &arr2, int n, int m){

    // this approach will take all the bigger elements from arr1 and will swap it with all the smaller elements of arr2
    // start from the n-1th element of arr1 and swap it with the smallest oth element of arr2 if arr1[n-1]>arr2[0] and move the pointers left and right accordingly
    // {1 3 5 7} {0 2 6 8 9}
    int left=n-1, right=0;
    while(left>=0 and right<m){
        if(arr1[left]>arr2[right]){
            swapElement(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else{
            // if arr[left]<arr[right] then no need because elements are already sorted 
            break;
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

void mergeSortedArraysBrute(vector<int> &arr1, vector<int> &arr2, int n, int m){
    // {1 3 5 7} {0 2 6 8 9}

    int i= 0; //pointing to first element of arr1
    int j=0;  // pointing to second element of arr2

    // create a temp array to store the sorted merged elements
    vector<int> temp;

    while(i<n and j<m){
        if(arr1[i]<= arr2[j]){
            temp.push_back(arr1[i]);
            i++;
        }
        else{
            temp.push_back(arr2[j]);
            j++;
        }
    }

    while(i<n) temp.push_back(arr1[i++]);
    while(j<m) temp.push_back(arr2[j++]);

    for(int i=0;i<n+m;i++){
        if(i<n) arr1[i]=temp[i];
        else arr2[i-n]= temp[i];
    }

}


int main(){
    vector<int> arr1, arr2;
    int n= getArray(arr1);
    int m= getArray(arr2);
    
    //mergeSortedArraysBrute(arr1, arr2, n, m);

    mergeWithoutExtraSpace(arr1, arr2, n, m);
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<endl;
    }
    for(int i=0;i<m;i++){
        cout<<arr2[i]<<endl;
    }

    return 0;
}