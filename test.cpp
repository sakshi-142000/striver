#include <iostream>
#include <vector>
using namespace std;



int main(){
    // vector<int> darray (5,1);
    int a=2<<1;
    cout<<a<<" ";
    // int n, m;
    // cin>>n >> m;

    // vector<int> v={1,2,2};

    // vector <vector<int> > twoD (n, vector<int>(m,0)); // treating every row as a vector
    // for(int i=0;i<n;i++){
    //     vector<int> t;
    //     cout<<"Enter "<< m <<" elements for "<<"row "<<i <<endl;
    //     for(int j=0;j<m;j++){
    //         int e;
    //         cin>>e;
    //         t.push_back(e);
    //     }
    //     twoD.push_back(t);
    // }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<twoD[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }




    // vector<int>::iterator it;
    // for(auto i: darray){
    //     cout<<i<<endl;
    // }

    

    // using two variable at one in for loop

    // for(int i=0, j=1; i<5 && j<4 ; i++,j++){
    //     cout<<i << " "<< j<< endl;
    // }


    //understanding postfix and prefix unary operators

    // int i = 3; 
    // cout<< i <<endl;

    // i++;
    // cout<< i <<endl;

    // cout<< i <<endl;

    // ++i;
    // cout<< i << endl;

    // cout<<i<<endl;


// checking the default value of array elements 

    //  int arr[1000000] = {1};// this will only initialise the 0th index rest all indices will be 0 only
    //     cout << arr[0];




    // int c = -123;
    // long cr=0;
    // while (c!=0){
    //     int digit= c%10;
        
    //     //check overflow if integer
    //     if(cr > INT_MAX /10 || cr*10 < INT_MIN /10 ){
    //         cout<<"integer limit overflow"<<endl; 
    //     }
    //     else {
    //         cr = cr*10 + digit;
    //         cout<<" c: "<<c<<" digit: "<<digit<<" cr: "<<cr;
    //         c= c/10;

    //     }

        
    // }




    
    
    return 0;
}