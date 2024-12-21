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
//    optimal approach of reversing doubly linked list uses only one traversal and swapping the forward and backward links
// Edge case: when we have head null or head->next null in such cases return head itself
    if(head==NULL || head->next==NULL) return head;

    Node* temp=head;

    while(temp){
        //stand at each node and reverse the links
        Node* current=temp->prev;
        temp->prev=temp->next;
        temp->next=current;
        if(temp->prev == NULL) break;
        else temp=temp->prev;

    }
    return temp;
}

int main(){
    vector<int> arr={1};
    Node* head=getLinkedList(arr);
    head=reverseDLL(head);
    printLinkedList(head);
    return 0;
}