#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// problem statement: given an arrary of books arr[i] reprsenting the number of pages in the ith book, 
// allocate book among m students in such a way that each student gets atleast one book and 
// you have the find the minimum of maxPageCount that a student can get
// approach: answers of maxPageCount will lie between maxE(arr) and the summ of all the pages
// a student can have the max pages as maxE right, if you select any lesser than that then the book with maxE number of pages will be allocated
// imagine you only have one student, in that case, you have to assign all the books to that one student, so the maxPage will be sumALlElements then


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

int findMax(vector<int> &arr, int n){
    int maxE=INT_MIN;
    for(int i=0;i<n;i++){
        maxE=max(maxE, arr[i]);
    }
    return maxE;
}

int findSumAll(vector<int> &arr, int n){
    int sumAll=0;
    for(int i=0;i<n;i++){
        sumAll+=arr[i];
    }
    return sumAll;
}

// check for studentCount we are getting when assigning the books(ofc pages)
int studentCount(vector<int> &arr, int n, int maxPages, int m){
    int low=findMax(arr, n);
    int currentPageCount=0, i=0, studentCount=0; //start assining from the first book
// 25 46 28 49 24
    while(i<n){
        // till all the books are not assigned
        if(currentPageCount+arr[i]>maxPages){
            // do not assign
            currentPageCount=0; //start again, to assign it to the next student from the same i(book)
            studentCount+=1;
        }
        else {
            currentPageCount+=arr[i];
            i++;
        }
    }
    currentPageCount++;

    return currentPageCount;
}

int minMaxPagesBS(vector<int> &arr, int n, int m){
    // answer range will be from maxE to sumAll
    if(n<m) {
        // if number of books are less than the  number of students then return -1
        return -1;
    }
    int low=findMax(arr, n);
    int high=findSumAll(arr, n);//assigning all the books to one student

    while(low<=high){
        int mid=(low+high)/2;
        // cout<<"low, highm mid: "<<low<<" "<<high<<" "<<mid<<endl;
        // cout<<"studentCount(arr, n, mid, m) "<<studentCount(arr, n, mid, m)<<endl;
        if(studentCount(arr, n, mid, m)>m){
            // if studentCount is greater than m then increase the maxPage so that we can assign more pages to a single student and decrease the studentCount
            low=mid+1;
            // cout<<"low, high mid inside studentCount>m: "<<low<<" "<<high<<" "<<mid<<endl;
        }
        else if(studentCount(arr, n,mid, m)<=m) {
            // cout<<"low, highm mid inside studentcount lesser than m "<<low<<" "<<high<<" "<<mid<<endl;
            high=mid-1; //decrease the maxPage
        }
    }
    return low;
}

int main(){
    vector<int> arr;
    int n=getArray(arr);
    
    int m; 
    cout<<"enter number of students"<<endl;
    cin>>m;
    cout<<minMaxPagesBS(arr, n, m);
    
    return 0;
}