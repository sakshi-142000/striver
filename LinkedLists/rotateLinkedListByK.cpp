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

// prob statement: given a linked list and value k, rotate the linked list by k 
// eg: 1 2 3 4 5 6, k=2, rotate by 2 means, 1 will move 2 positions to the right 
// and consecutively 6 will move 2 positions to the right and will take the space of 2
// rotated list: 5 6 1 2 3 4

Node* rotateByK(Node* head, int k){
    // step1: locate the tail and the length of linked list
    Node* tail=head;
    int length=1;
    // 1 2 3 4 5 6
    while(tail->next){
        length++;
        tail=tail->next;
    }
    // step2: get the k
    k=k%length;
    // we want the node length-k
    int index=length-k;
    Node* newTail=head;
    index--;
    while(index){
        index-=1;
        newTail=newTail->next;
    }
    tail->next=head;
    head=newTail->next;
    newTail->next=NULL;
    return head;
}




int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    Node* head=getLinkedList(arr);
    head=rotateByK(head,3);
    printLinkedList(head);
    return 0;
}