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
    Node(int element, Node* addressOfNext){
        data=element;
        next=addressOfNext;
    }

};

Node* getLinkedList(vector<int> &arr){
    Node* head= new Node(arr[0]); 
    Node* mover=head; 
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp; 
        mover=mover->next; 
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

Node* segregateOddEvenOptimal(Node* head){
    // optimal Approach Intuition: 
    // create a separate ll for odds and for even by saving the heads and then link both of them
    // {1,2,3,4,5,6,7,8,9}

    Node* odd=head;
    Node* even=head->next;
    Node* saveEvenHead= even;
    while(even!=NULL && even->next!=NULL){
        // just do a dry run and you will understand the while conditon
        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;
    }
    odd->next=saveEvenHead;

// IMMA GENIUS
    return head;
}



int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9};
    Node* head=getLinkedList(arr);
    head=segregateOddEvenOptimal(head);
    printLinkedList(head);
    return 0;
}