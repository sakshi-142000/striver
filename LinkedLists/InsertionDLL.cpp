#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    public:
    // contructors
    Node(int data1){
        data=data1;
        prev=nullptr;
        next=nullptr;
    }
    Node(int data1, Node* prev1, Node* next1){
        data=data1;
        prev=prev1;
        next=next1;
    }
};

Node* getDoublyLL(int *arr, int n){
    Node* head= new Node(arr[0]); //prev of head is null for sure, next is null initially
    Node* temp=head;
    for(int i=1;i<n;i++){
        Node* newNode=new Node(arr[i], temp, nullptr);
        temp->next=newNode;
        temp=temp->next;//or newNode
    }
    return head;
}

void printDoublyLL(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* InsertAtHead(Node* head){
    
    cout<<"enter data value to insert at head"<<endl;
    int newNode;
    cin>>newNode;
    Node* temp=new Node(newNode);
    temp->next=head;
    head->prev=temp;
    return temp;
}

Node* InsertAtTail(Node* head){
    //go till tail, stand at it and then add the new nod
    cout<<"enter data value to insert at tail"<<endl;
    int newNodeValue;
    cin>>newNodeValue;
    Node* temp=head;
    Node* newNode=new Node(newNodeValue);
    while(temp->next){
        //if temp->next== NULL, break cause you wanna stand at tail
        temp=temp->next;
    }
    newNode->prev=temp;
    temp->next= newNode;

    return head;
}

Node* InsertAtPositionK(Node* head, int k){
    

    Node* temp=head; //initially standing at head
    cout<<"enter data value to insert at position k"<<endl;
    int newNodeValue;
    cin>>newNodeValue;
    int count=1; //keep a count of positions and stop at k
    Node* newNode=new Node(newNodeValue);
    while(count<k){
        // stop at the node when count equals to k
        temp=temp->next;
        count++;
    }
    if(temp->prev==NULL) {
        // head=InsertAtHead(head);
        newNode->next=head;
        head->prev=newNode;
        return newNode;
    }
    // else if(temp->next==NULL){
    //     // temp=InsertAtTail(head);
    //     // return temp;
    //     // insertion at tail
    //     temp->prev->next=newNode;
    //     newNode->prev=temp->prev;
    //     newNode->next=temp;
    //     temp->prev=newNode;
    //     return head;
    // } 
   temp->prev->next=newNode;
   newNode->prev=temp->prev;
   newNode->next=temp;
   temp->prev=newNode;

   return head;
}

int main(){
    int arr[]= {1,2,3,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(int);
    Node* head=getDoublyLL(arr,n);
    // printDoublyLL(head);
    // head=InsertAtHead(head);
    // printDoublyLL(head);
    // head=InsertAtTail(head);
    // printDoublyLL(head);
    head=InsertAtPositionK(head,8);
    
    printDoublyLL(head);
    return 0;
}