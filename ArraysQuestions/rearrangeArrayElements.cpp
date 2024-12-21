#include <iostream>
#include <vector>
using namespace std;

//given an array of equal number of positive and negative integers, rearrange the number such that positive and negative numbers are in alternative positions
// eg, [3 1 -2 -5 2 -4]
//     [3 -2 1 -5 2 -4], a negative number after every positive number

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

void rearrangeNumbers(vector<int> &arr, int n){
    // [3 1 -2 -5 2 -4]
    vector<int> positives, negatives;
    for(int i=0;i<n;i++){
        if(arr[i]>0) positives.push_back(arr[i]);
        else negatives.push_back(arr[i]);
    }

    for(int i=0;i<n/2;i++){
        arr[2*i]=positives[i];
        arr[2*i+1]=negatives[i];
    }


}

void rearrangeNumbersOptimal(vector<int> &arr, int n){
    // optimal approach uses only one pass O(n) rather than two passes to get the positives and negatives in their positions
    // using kind two pointer approach for this one, however, need a another array to return the answer
    int positive=0, negative=1; // initial index where we keep the first positive and negative element
    vector<int> answer(n,0);

    for(int i=0;i<n;i++){
        if(arr[i]>0){
            //positive
            answer[positive]=arr[i];
            positive+=2; // marking the next position for the positive element
        }
        else{
            //negative
            answer[negative]=arr[i];
            negative+=2;
        }
    }

    for(int i: answer) cout<<i<<" ";
}

//program for when the no(positives)!= no(negatives)

void rearrangeNumbersVariety2(vector<int> &arr, int n){
    
    vector<int> positives, negatives; // for storing the positives and negative
    for(int i=0;i<n;i++){
        if(arr[i]>0) positives.push_back(arr[i]);
        else negatives.push_back(arr[i]);
    }

    int p=positives.size();
    int ne=negatives.size();
    if(p>ne){
        //if number of positives are greater than negative then push the n +ve and -ve elements in the array first alternatively and push the remaing positive elements
        // [1 2 3 4 5 -1 -2 -3] p=5 n=3
        // [1 -1 2 -2 3 -3 4 5]
        for(int i=0;i<ne;i++){
            arr[2*i]=positives[i];
            arr[2*i+1]=negatives[i];
        }

        //pushing back the remaining positive elements

        int j=2*ne;
        for(int i=ne;i<p;i++){
            arr[j]=positives[i];
            j++;
        }
    }
    else{
        // [1 2 3  -1 -2 -3 -4 -5] p=3 ne=5 n=8
        // [1 -1 2 -2 3 -3 -4 -5]
        for(int i=0;i<p;i++){
            arr[2*i]=positives[i];
            arr[2*i+1]=negatives[i];
        }

        //pushing back the remaining negative elements
        int j=2*p;
        for(int i=p;i<ne;i++){
            arr[j]=negatives[i];
            j++;
        }


    }
}

int main(){
    vector<int> arr;
    int n = getArray(arr);
    // rearrangeNumbers(arr, n); // manipulating the same array
    // rearrangeNumbersOptimal(arr,n);
    rearrangeNumbersVariety2(arr, n);
    for(int i:arr) cout<<i<<" ";
    cout<<endl;



    return 0;
}
