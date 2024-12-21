#include <iostream>
#include <vector>
using namespace std;

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

vector<int> intersection(vector<int> a, vector<int> b, int n, int m){
    vector<int> result;

    //bruteforce approach >> two for loops and a visit array

    vector<int> visit(m,0);// visit vector for b and initialising visit of each element as 0 initially

    // a= {1,2,2,3,4,5,6}
    //b={2,3,3,4,6,6}
    //visit={0,0,0,0,0,0} initially

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i]==b[j] and visit[j]==0){
                result.push_back(a[i]);
                visit[j]=1;
                break;
            }
            if(b[j]>a[i]) break; // as b's element is greater than a's ith element there is no way you can find a match for a[i]
        }
    }

    return result;
}


vector<int> intersectionOptimal(vector<int> a, vector<int> b, int n, int m){

    //optimal approach is using 2 pointer method
    vector<int> result; 
    int i=0; // i an j pointing to the initial index of a and b intially
    int j=0;
    // a= {1,2,2,3,4,5,6}
    //b={2,3,3,4,6,6}

    while(i<n and j<m){
        if(a[i]<b[j]) i++; // no pair for a[i]
        else if (b[j]<a[i]) j++; // no match for b[j]
        else if (a[i]==b[j]) {
            // it's a match, hurray
            result.push_back(a[i]);
            i++;
            j++;
        }
    }
    

    return result;
}


int main(){
    vector<int> arr1;
    vector<int> arr2;
    int n = getArray(arr1);
    int m = getArray(arr2);

    //vector<int> result=intersection(arr1,arr2,n,m);
    vector<int> result=intersectionOptimal(arr1,arr2,n,m);
    for(int i: result) cout<<i<<" ";
    

    return 0;
}