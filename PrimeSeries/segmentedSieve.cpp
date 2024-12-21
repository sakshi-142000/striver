#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// notes: segemented sieve is for getting primes in the range [L,R]
// test cases are less lets say 1000??, not sure, but def less
// constraints: 0<L,R <=10^12 // can't build sieve till R
// (L-R) <=10^6

// create sieve for sqrt(R max) ~~ 10^6 so that we can get all the primes to cover all the multiples till 10^12
int N= 100000;
bool sieve[1000001];// global array elements default to 0; sieve[0]=sieve[1]=0
void createSive(){
    for(int i=2; i<=N; i++){
        sieve[i]=1;
    }

    for (int i=2; i*i<=N;i++){
        if(sieve[i]){
            for(int j=i*i;j<=N;j+=i){
                sieve[j]=0;
            }
        }
    }
}

vector<int> generatePrimes(int sqrtr){
    vector<int> getPrimes;
    for(int i=2;i<=sqrtr;i++){
        if(sieve[i]) getPrimes.push_back(i);
    }
    return getPrimes;
}


int main(){
    createSive();
    int t; // test cases 
    cin>>t;

    while (t--){
        int l, r; // take range 
        cin>> l >> r;

        // get all the primes till sqrt(r)
        vector<int> primes = generatePrimes(sqrt(r));
        //create dummy array for (l,r)
        vector<int> darry(r-l+1, 1); // darry of size r-l+1 all with value 1
        vector<int>::iterator it;
        for (auto pr : primes){
            int firstMultiple = (l/pr)*pr;
            if(firstMultiple<l) firstMultiple+=pr; // check notes if you wanna understand this

            for(int j=max(firstMultiple,pr*pr);j<=r;j+=pr){
                darry[j-l]=0;
            }
        }

        //print all the primes in the range FINALLYYYYY

        for(int i=0; i<darry.size();i++){
            if(darry[i]) cout<< (l+i) <<endl;
        }



    }
    return 0;
}