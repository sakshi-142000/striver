#include <iostream>
#include <vector>
using namespace std;

/*
given q queries q<50,000
for each q, we have a number k, return the prime number at that index 
1

1<=k<=5000000

therefore, to not to get segmentation fault, get the size of sieve first 
*/

int N= 86028122;// max array size globally, 10^8, locally, 10^7
bool sieve[86028122];
int main(){
     //build sieve
    sieve[0]=0;
    sieve[1]=0;

    for(int i=2;i<N;i++){
        sieve[i]=1;
    }

    for(int i=2;i*i<N;i++){
        if(sieve[i]){
            for(int j=i*i;j<N;j+=i){
                sieve[j]=false;
            }
        }
    }

    vector<int> storePrimes;
    for(int i=2; i<N; i++){
        if(sieve[i]){
            storePrimes.push_back(i);
        }
        
    }

    cout<<storePrimes.size()<<endl;
    vector<int>::iterator it;

    for(it = storePrimes.begin();it!=storePrimes.end(); it++){
        cout<<*it<<"\t"<<endl;
    }


    //take queries now

    // int q;
    // cin>>q;

    // while (q--){
    //     int k;
    //     cin>>k;
    //     cout<<storePrimes[k-1];
    // }

    
    /*
    
    int maxPrimeCount=0;// return the value of n (i) when maxPrimeCount reached 5000000
    int getMaxSieveSize;
    for(int i=0;i<N;i++){
        if(sieve[i]) {
            maxPrimeCount++;
            if(maxPrimeCount>=5000000){
                getMaxSieveSize=i;
                cout<< i << endl;
                break;
            }
            
        }
    }
    
    
    */
    
    
    // cout<<maxPrimeCount<<endl; //5000000
    // cout<<getMaxSieveSize<<endl; //86028121

    return 0;
}