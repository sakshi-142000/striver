#include <iostream>
#include <stack>
#include <utility>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    public: 
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }

    Node(int value, Node* leftAddress, Node* rightAddress){
        data=value;
        left=leftAddress;
        right=rightAddress;
    }
};

int main(){

    stack<pair<Node*, int> > st;
    Node* n=new Node(1);
    Node* n1= new Node(2);
    Node* n2=new Node(3);
    n->left=n1;
    n->right=n2;
    st.push(make_pair(n,2));
    cout<<st.top().first<<endl;
    return 0;
}