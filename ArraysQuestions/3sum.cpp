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

vector<vector<int> > findTripletOptimal(vector<int>&arr, int n){
    sort(arr.begin(), arr.end());
    vector<vector<int> > triplets;
    for(int i=0;i<n;i++){
        //for every time we move i, set j to i+1 and k to the last of array
        if(i>0 && arr[i]==arr[i-1]) continue; //avoid repeting on the same i, it will give duplicates
        int j=i+1, k=n-1;
        while(j<k){
            //j and k shouldn't cross each other
            if(arr[i]+arr[j]+arr[k] == 0){
                vector<int>triplet;
                triplet.push_back(arr[i]);
                triplet.push_back(arr[j]);
                triplet.push_back(arr[k]);
                triplets.push_back(triplet);
                j++; k--;
                while(j<k and arr[j]==arr[j+1]) j++;
                while(arr[k]==arr[k-1]) k--;

            }

            else if(arr[i]+arr[j]+arr[k] > 0){
                k--; // reduce
                // after reducing, also check if k-1 == kth element
                while(j<k and arr[k]==arr[k-1]) k--;
            }
            else if(arr[i]+arr[j]+arr[k] < 0){
                j++; //increase
                while(j<k and arr[j]==arr[j+1]) j++; // while increment and decrementing j and k also check if j<k or not we do not want overflow
            }


        }
        
    }

    return triplets;
    
}

vector<vector<int> > findTripletbrute(vector<int>&arr, int n){
    vector<vector<int> > triplets;
    

    for(int i=0;i<n;i++){
        for(int j=i+1; j<n;j++){
            for(int k=j+1; k<n; k++){
                if(arr[i]+arr[j]+arr[k]==0) {
                    vector<int> triplet;
                    triplet={arr[i], arr[j],arr[k]}; 
                    //sort this so that we donot store the same triplet
                    triplets.push_back(triplet);
                }

            }
        }
    }

    return triplets;
}



vector<vector<int> > findTripletbetter(vector<int>&arr, int n){
    // -1 0 1 2 -1 -4
    // using 2 nested loops with i and j and finding k between i and j, arr[k]=-(arr[i]+arr[j]), finding arr[k] using hashing
    vector<vector<int> > triplets;
    
    for(int i=0;i<n;i++){
        set<int> storek; 
        for(int j=i+1;j<n;j++){
            int kelement=-(arr[i]+arr[j]);
            if(storek.find(kelement)!=storek.end()) {
                vector<int> triplet={arr[i],kelement, arr[j]};
                sort(triplet.begin(), triplet.end()); //sorting the triplet before storing in set to avoid duplicate triplets
                triplets.push_back(triplet);
            }
            //before leaving store j in the set
            storek.insert(arr[j]);
        }
    }
    return triplets;


}


int main(){


    vector<int> arr;
    int n=getArray(arr);
    // vector<vector<int> > triplets = findTripletbrute(arr, n);
    //vector<vector<int> > triplets = findTripletbetter(arr, n);
    vector<vector<int> > triplets = findTripletOptimal(arr, n);
    for(int i=0;i<triplets.size();i++){
        for(int j=0;j<3;j++){
            cout<<triplets[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}