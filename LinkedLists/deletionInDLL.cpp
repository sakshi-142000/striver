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

Node* deleteHeadDLL(Node* head){
    
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head->next;
    temp->prev=nullptr;
    head->next=nullptr;
    free(head);
    return temp; // new head

}

Node* deleteTailDLL(Node* head){
    if(head->next==NULL) return NULL; //no tail just remove the head
    Node* temp=head;
    while(temp->next){
        //if temp->next points to null then that is the tail, stand at the tail and then update the previous node
        temp=temp->next;
    }
    temp->prev->next=NULL;
    temp->prev=NULL;
    delete temp;
    return head;
}

Node* deleteKthNode(Node* head, int k){
    //delete the kth node, k can be the 1st node, head or last node tail as well
    Node* temp=head;
    int count=1;//temp is initially at 1st node
    while(count<k){
        // stop when temp reaches the kth node
        temp=temp->next;
        count++;
    }
    Node* back=temp->prev;
    Node* front=temp->next;

    if(temp->prev == NULL){
        temp=deleteHeadDLL(temp); //delete head, temp is a head
        return temp;
    }
    else if (temp->next==NULL){
        //temp is the tail
        temp=deleteTailDLL(temp);
        return temp;
    }
    
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
    return head;
    

}

Node* removeGivenNode(Node* head){
    // given a node, delete node from the linked list

    cout<<"enter the node value that you want to delete"<<endl;
    int NodeToDelete;
    cin>>NodeToDelete;

    Node* temp=head;
    while(temp->data!=NodeToDelete){
        temp=temp->next; //if temp->data!=NodeToDelete, move forward
    }
    Node* back= temp->prev;
    Node* front = temp->next;

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;

    temp->prev=NULL;
    temp->next=NULL;

    delete temp;

    return head;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    // int arr[]={1}; //for edge case testings
    int n=sizeof(arr)/sizeof(int);
    Node* head= getDoublyLL(arr, n);
    printDoublyLL(head);
    head = deleteHeadDLL(head);
    printDoublyLL(head);
    head = deleteTailDLL(head);
    printDoublyLL(head);
    head=deleteKthNode(head,4);
    printDoublyLL(head);
    head=removeGivenNode(head);
    printDoublyLL(head);
    return 0;
}