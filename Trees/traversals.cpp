#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    public:
    Node(int value){
        data=value;
        left=nullptr;
        right=nullptr;
    }
    Node(int value, Node* leftptr, Node* rightptr){
        data=value;
        left=leftptr;
        right=rightptr;
    }
}; 

void InorderTraversal(Node* root){
    if(root==NULL) return;
    InorderTraversal(root->left);
    cout<<root->data<<" ";
    InorderTraversal(root->right);
}

void PreorderTraversal(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

void PostorderTraversal(Node* root){
    if(root==NULL) return;
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    InorderTraversal(root);
    cout<<endl;
    PreorderTraversal(root);
    cout<<endl;
    PostorderTraversal(root);
    return 0;
}