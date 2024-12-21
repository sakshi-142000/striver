#include <iostream>
#include <vector>
#include <utility>//pair is defined in utility header file
using namespace std;

long long powerFn(int n, int x){
    // finding n^x
    if(x==0) return 1; //do not forget the edge cases
    long long ans=1;
    while(x>1){
      if(x%2==0){
         x/=2;
      cout<<"x n"<<x<<" "<<n<<endl;
      }
      else{
        x/=2;
        cout<<"inside else, x ="<<x<<endl;
        ans*=n;
        cout<<"inside else, ans ="<<ans<<endl;
      }
      cout<<"n "<<n<<endl;
      n*=n;
    }

    return ans*n;
}

int main(){
    int n,x;
    cin>>n>>x;
    long long m=4194304*4194304;
    int testvar= 123;
    double testvar2=120;
    cout<<testvar/testvar2<<endl;




    //cout<<powerFn(n,x);

    // vector<int> arr;
    // for(int i=0;i<n;i++){
    //     int element;
    //     cin>>element;
    //     arr.push_back(element);
    // }

    // 


}

