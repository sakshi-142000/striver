#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int element){
        data=element;
        next=nullptr;
    }
    Node(int element, Node* AddressOfNext){
        data=element;
        next=AddressOfNext;
    }
};

Node* getLinkedList(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);
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

// prob statement: given two sorted linked lists, return the third merged sorted linked list

Node* mergeLLOptimal(Node* head1, Node* head2){
    Node* dummy= new Node(-1);
    Node* temp=dummy;
    // dummy node with value -1 and next pointing to null, we will build a new linked list on the top of this dummy

    Node* temp1=head1;
    Node* temp2=head2;

// {1,3,5,8,9,10};
// {2,4,6,7};

    while(temp1 and temp2){
        // if any of them reaches null stop
        if(temp1->data <=temp2->data){
            temp->next=temp1;
            temp=temp->next;
            temp1=temp1->next;
        }
        else {
            temp->next=temp2;
            temp=temp->next;
            temp2=temp2->next;
        }
    }
    if(temp1){
        temp->next=temp1;
        temp=temp->next;
        temp1=temp1->next;
    }
    if(temp2){
        temp->next=temp2;
        temp=temp->next;
        temp2=temp2->next;
    }
    return dummy->next;
}




int main(){
    vector<int> arr1={1,3,5,8,9,10};
    vector<int> arr2={2,4,6,7};
    Node* head1=getLinkedList(arr1);
    Node* head2=getLinkedList(arr2);
    Node* head=mergeLLOptimal(head1, head2);
    printLinkedList(head);
    return 0;
}