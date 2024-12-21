#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 3sum: given an array of integers, find all the triplets whose sum equals to 0 
// -1 0 1 2 -1 -4
// {{-1,0,1}}

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

vector<vector<int> > findQuadOptimal(vector<int> &arr, int n){
    // drawbacks of using the hashing approach 
    // we are using extra hashset which might take O(n) space and extra space for storing the unique quads as well in the set

    // to avoid using extra space, we will use the two pointer approach here 
    // keeping i and j as constants and moving k and l

    // sort the array so that we do not have to sort every time we find the quad and insert it to the another set to avoid duplicates
    vector<vector<int> > quads;
    int target;
    cout<<"enter target"<<endl;
    cin>>target;
    sort(arr.begin(), arr.end());
// 1 1 1 2 2 2 3 3 3 4 4 4 5 5 
    for(int i=0;i<n;i++){
        if(i>0 and arr[i]==arr[i-1]) continue; // no need to repeat for the same i again
        for(int j=i+1;j<n;j++){
            if(j!=i+1 and arr[j]==arr[j-1]) continue; //if j is not the first element after i and we found the same value of j again then do not continue with the k loop as it will generate duplicates
            int k= j+1, l=n-1; 
            while(k<l){
                long long sum= arr[i]+arr[j]+arr[k]+arr[l];
                if(target==sum){
                    //quad found
                    vector<int> quad={arr[i], arr[j], arr[k], arr[l]};
                    quads.push_back(quad); //no need to sort the quad as we sorted the array before

                    k++; 
                    while(arr[k]==arr[k-1] and k<l) k++;
                    l--; 
                    while(arr[l]==arr[l+1] and k<l) l--; //doing this till we find a new value for k and l to avoid duplicates 
                }
                else if(sum<target) {
                    k++; //increase the sum
                    while(arr[k]==arr[k-1] and k<l) k++; //if we use the same value again it will make no sense, sum will remain the same
                }
                else if(sum>target){
                    l--; //decrease
                    while(arr[l]==arr[l+1] and k<l) l--; 
                }
            }
        }
    }


    return quads;


}

vector<vector<int> > findQuadBetter(vector<int> &arr, int n){
    //brute force was n^4 so on better you can optimise it to n^3
    
    // approach: loop till k (to get the three elements and then for the fourth element find it using 0-(arr[i]+arr[j]+arr[k]) 
    // to find 0-(arr[i]+arr[j]+arr[k]) , use a hash set to store the values between j and k while traversing k, so that you can easily find the element
    // also do not search for l in the entire array, because you can then get the same index, 
    
    set<vector<int> > st;
    //set<int> hashSet; // do not do this mistake, for every iteration of k the hashset will be refreshed
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> hashSet;
            for(int k=j+1;k<n;k++){
                long long sum= arr[i]+arr[j]+arr[k];
                long long arrl = 0-sum;
                if(hashSet.find(arrl)!=hashSet.end()){
                    //lth element found 
                    vector<int> quad={arr[i], arr[j], arr[k], (int)arrl};
                    sort(quad.begin(), quad.end()); // sort before inserting so that you do not store the duplicate elements
                    // quads.push_back(quad);

                    st.insert(quad);
                }
                hashSet.insert(arr[k]); //before moving forward store arr[k] for hashing
            }
        }
    }
    vector<vector<int> > quads(st.begin(), st.end());
    return quads;
}

vector<vector<int> > findQuadBrute(vector<int> &arr, int n){
    set<vector<int> > quads; //storing in set to avoid duplicates
//  1 0 1 2 -1 -4
    for(int i=0;i<n;i++){
        //for every i, j, k fixed, get quads by moving k
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    long long sum= arr[i]+arr[j];
                    sum+=arr[k]+arr[l]; // so as not to exceed the range of int
                    // arr[i]+arr[j]+arr[k]+arr[l] this might exceed the int range therefore store it in a long long type
                    if(sum==0){
                        vector<int> quad={arr[i],arr[j],arr[k],arr[l]};
                        //sort(quad.begin(), quad.end());//sort before pushing onto quads to avoid duplicates.
                        quads.insert(quad);
                    }
                }
            }

        }
    }

    vector<vector<int> > ans(quads.begin(), quads.end()); // copying quads elements into ans array to return 

    return ans;
    
}




int main(){


    vector<int> arr;
    int n=getArray(arr);
    // vector<vector<int> > quads = findQuadBrute(arr, n);
    // vector<vector<int> > quads = findQuadBetter(arr, n);
    vector<vector<int> > quads = findQuadOptimal(arr, n);

    for(int i=0;i<quads.size();i++){
        for(int j=0;j<4;j++){
            cout<<quads[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}