#include <iostream>
#include <vector>
using namespace std;

int getArray(vector<pair<int, int> > &arr){
    int n;
    cout<<"enter size"<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        pair<int, int> interval; 
        cin>>interval.first;
        cin>>interval.second;

        arr.push_back(interval);
    }


    return n;
}

vector<pair<int, int> > mergeOverlaps(vector<pair<int, int> > &arr, int n){
    vector<pair<int, int> > result;
    sort(arr.begin(), arr.end());
    // (1,3) (2,4) (2, 6) (8,9) (8,10) (9,11) (15, 18) (16, 17)
    // traversing the array and editing the result.back[i] element whenever arr[i] is mergable
    for(int i=0;i<n;i++){
        // if in case the result array does not have any element (at the start of tranversal) or if arr[i] is not mergable eg (8,9)
        if(result.empty() || result.back().second<arr[i].first) {
            result.push_back(arr[i]);
        }
        else{
            // if arr[i][0] < result.back[1] then update result.back[1]
            result.back().second=max(result.back().second, arr[i].second);
        }
    }


    return result;
}

vector<pair<int, int> > mergeOverlapsBrute(vector<pair<int, int> > &arr, int n){

//Brute approach: sort the array first, sorting will be done on the first element of the pair, if in case we have two pairs with same first element then we'll consider the second element
// (1,3) (2,4) (2, 6) (8,9) (8,10) (9,11) (15, 18) (16, 17)
    // this is also O(n), i tranversed every element only once
    vector<pair<int, int> > result;
    sort(arr.begin(), arr.end());
    int i=0; //traversing through the array
    while(i<n){
        int start=arr[i].first; //initially considering that <start, end> is the initial merged interval
        int end= arr[i].second; 
        // merging
        int j=i+1;
        while(j<n){
            if(arr[j].first<=end){
                end=max(arr[j].second, end); //merge based on whose second element is larger 
                j++;
                // do not do anything just proceed further with j
            }
            else break;
        }

        // if arr[j].first >end then the two intervals are not overlapping
        // in that case insert the merge pair {start, end} into the result array and move i further to get the new merge pair
        pair<int, int> mergedInterval(start, end);
        result.push_back(mergedInterval);
        i=j;

    }

    return result;
}


int main(){
    vector<pair<int, int> > arr;
    int n= getArray(arr);
    // vector<pair<int, int> > result = mergeOverlapsBrute(arr, n);
    vector<pair<int, int> > result = mergeOverlaps(arr, n);    
    cout<<"merged intervals "<<endl;
    for(int i=0;i<result.size();i++){
        cout<<"("<<result[i].first<<" , "<<result[i].second<<")"<<" ";
    }
    return 0;
}

