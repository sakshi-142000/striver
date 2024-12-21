#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    public:
    Node(int element){
        data=element;
        prev=nullptr;
        next=nullptr;
    }
    Node(int element, Node* prevAddress, Node* nextAddress){
        data=element;
        prev=prevAddress;
        next=nextAddress;
    }

};

Node* getLinkedList(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i],temp, nullptr);
        temp->next=newNode;
        temp=newNode;
    }
    return head;
}

void printLinkedList(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* reverseDLL(Node* head){
    // {1,2,3,4,5,6,7} 
    // Bruteforce includes changing the data and keeping the links as it is
    // traverse one forward and store all the elements in stack and then traverse again and change the data 
    stack<int> st;
    Node* temp=head;
    while(temp){
        st.push(temp->data);
        temp=temp->next;
    }

    //traverse again to change the data in nodes
    temp=head; //start from head again
    while(temp){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr={1,2,3,4,5,6,7};
    Node* head=getLinkedList(arr);
    head=reverseDLL(head);
    printLinkedList(head);
    return 0;
}