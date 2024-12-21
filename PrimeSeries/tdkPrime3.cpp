#include <iostream>
#include <vector>
using namespace std;

//int N=100000000; //initially
int N=86028122; // i found the max size by running the program for N=100000000
bool sieve[86028122];
//int storePrime[5000001]; //5000000 inclusive

int main() {
	
	vector<int> storePrimes;
	
	sieve[0]=0;
	sieve[1]=0;
	
	for(int i=2;i<N;i++){
		sieve[i]=1;
	}
	
	for(int i=2;i*i<N;i++){
		if(sieve[i]){
			for(int j=i*i;j<N;j+=i){
				sieve[j]=0;
			}
		}
	}

	//calculate the maximum size for sieve array where we have the last prime number is 5000000
	// int primeNumCount=0;
	// int maxSieveSize=0;
	// for(int i=2;i<N;i++){
	// 	if(sieve[i]){
	// 		primeNumCount++;
	// 		if(primeNumCount==5000000){
	// 			maxSieveSize=i+1;//adding 1 to the index 
	// 		}
				
			
	// 	}
	// }

    for(int i=0;i<N;i++){
        if(sieve[i]) storePrimes.push_back(i);
    }


    


	int q;
	cin>>q;
	 
	while(q--){
		int k;
		cin>>k;
		cout<<storePrimes[k-1];
	}
	return 0;
}