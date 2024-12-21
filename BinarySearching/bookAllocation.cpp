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

int isAllocationPossible(vector<int> &arr, int n, int maxPagesAllocated, int m){
    int studentCount=0, currentPageCount=0, i=0; //number of students we allocated the books to and the currentPageCount for each student
    while(i<n){
        
        if((currentPageCount+arr[i])>maxPagesAllocated){
            // if maxPagesAllocated is exceeded then increase the studentCount and start assigning to new student
            studentCount+=1;
            currentPageCount=0; //start again for the next student, do not increase i in this case, start from the same i 
        }
        else {
            currentPageCount+=arr[i];
            i++;
        }
    }
    studentCount++;
    //return studentCount; //for lesser value of maxPagesAllocated, the count will be more whereas for greater values of maxPagesAllocated the count will be less
    // cout<<"studentCount:"<<studentCount<<endl;
    if(studentCount>m) return false;
    else return true;
}

int maximumPages(vector<int> &arr, int n, int m){
    if(m>n) return -1;
    int maxPagesAllocated=findMax(arr, n);
    //  [25, 46, 28, 49, 24], m=4
    while(maxPagesAllocated){
        if(isAllocationPossible(arr, n, maxPagesAllocated, m)) {
            return maxPagesAllocated;
        }
        else maxPagesAllocated++;
    }
}

// int maximumPagesBS(vector<int> &arr, int n, int m){
//     int low=findMax(arr, n);
//     int high=findSumAll(arr, n);

//     if(m>n){
//         return -1; //one book for each student
//     }

//     while(low<=high){
//         int mid=(low+high)/2;

// // if for some mid value, the studentCount is greater then ofc you need to increase the mid value so that each student get more number of pages and we can assign more books in less number of students
// // opposite to that, if studentCount is lesser than you have to decrease the mid value so as to assign books to more students and accomodate till we get studentCount==m

//         if((isAllocationPossible(arr, n, mid, m))==m) return mid;
//         else if((isAllocationPossible(arr, n, mid, m))>m) {
//             // students are more, increase the page count
//             low=mid+1; //eliminate the left half of shorter mids
//         }
//         else if ((isAllocationPossible(arr, n, mid, m))<m){
//             // kam students ko jyda pages allocate kr diye h, decrease the page count
//             high=low-1;
//         }
//     }
// }

int main(){
    vector<int> arr;
    int n=getArray(arr);
    
    int m; 
    cout<<"enter number of students"<<endl;
    cin>>m;
    cout<<maximumPagesBS(arr, n, m);
    
    return 0;
}