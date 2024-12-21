#include <iostream>
#include <vector>
#include <utility>//pair is defined in utility header file
using namespace std;


int main(){
    int n;
    cin>>n;

    vector<pair<int, int> > intervals;
    for(int i=0;i<n;i++){
        pair<int, int> interval;
        cin>>interval.first;
        cin>>interval.second;

        intervals.push_back(interval);
    }

    cout<<"printing intervals"<<endl;
    for(int i=0;i<n;i++){
        cout<<intervals[i].first<<" "<<intervals[i].second<<endl;
    }
}

