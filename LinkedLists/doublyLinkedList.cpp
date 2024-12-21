#include <iostream>
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
Node* getDoublyLinkedList(int *arr, int n){
    Node* head=new Node(arr[0]); //prev and next both are null initially
    Node* temp=head;
    for(int i=1;i<n;i++){
        // so at a given node you are setting the previous of the given node and the nextof the previous node and moving forward
        Node* newNode= new Node(arr[i], temp, NULL); //previous will be pointing to temp and next will be pointing to null
        temp->next=newNode; // setting the next of previous node
        temp=newNode; //moving forward 
    }

    return head;
}

int printDoublyLL(Node* head){

    //lets return the length of the doublylinked list
    Node* temp=head;
    int length=0; 
    while(temp){
        cout<<temp->data<<" ";
        length++;
        temp=temp->next;
    }
    cout<<endl;
    return length;
}


int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(int);
    Node* head=getDoublyLinkedList(arr,n);
    cout<<printDoublyLL(head)<<endl;
    return 0;
}