#include <iostream>
using namespace std;

int N=100000000; //initially
bool sieve[100000000];

int main() {
	
	// int q;
	// cin>>q;
	
	sieve[0]=0;
	sieve[1]=0;

    for(int i=2;i<N;i++){
        sieve[i]=1;
    }
	
	for(int i=2;i*i<N;i++){
		if(sieve[i]){
			for(int j=i*i;j<N;j=j+i){
				sieve[j]=0;
			}
		}
	}
	
	//calculate the maximum size for sieve array where we have the last prime number is 5000000
	int primeNumCount=0;
	int maxSieveSize=0;
	for(int i=2;i<N;i++){
		if(sieve[i]){
			primeNumCount++;
			if(primeNumCount==5000000){
				maxSieveSize=i+1;//adding 1 to the index 
                break;
			}
				
			
		}
	}

    cout<<primeNumCount<<endl;
    cout<<maxSieveSize<<endl;

	
	// while(q--){
	// 	int k;
	// 	cin>>k;
	// }
	return 0;
}