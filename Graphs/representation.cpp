#include <iostream>
using namespace std;

int main(){
    // input format will be n (nodes) and m (edges), followed by m lines representing the what nodes are connected by edge

    int n, m;
    cin>>n >>m;
    int adj[n+1][n+1]={0}; //considering 1 based indexing for the nodes

    // adjacency matrix

    for(int i=0; i<m;i++){
        int u, v;
        cin>>u >>v;
        adj[u][v]=1;
        adj[v][u]=1;   
    }

    // adjacency list

    vector<int> adj2[n+1]; //for each node, store its

    for(int i=0; i<=n ;i++){
        int u, v;
        cin>>u >>v; // u and v are connected by edge 
        // adj2[i].push_back(u);
        // adj2[i].push_back(v);

        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    

    return 0;
}