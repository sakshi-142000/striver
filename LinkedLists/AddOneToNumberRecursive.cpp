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

Node* getLinkedList(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode= new Node(arr[i]);
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

// 1 2 3 
int AddOne(Node* current){
    if(current==NULL) return 1; // add carryover of one to the last number on the linked list
    int carryOver=AddOne(current->next);
    int sum=current->data+carryOver;
    carryOver=sum/10;
    sum=sum%10;
    current->data=sum;
    return carryOver;
}



int main(){
    vector<int> arr={1, 9};
    Node* head=getLinkedList(arr);
    cout<<"before addition"<<endl;
    printLinkedList(head);
    int carryOver=AddOne(head);
    if(carryOver){
        Node* newHead=new Node(carryOver);
        newHead->next=head;
        head=newHead;
    }
    printLinkedList(head);
    return 0;
}
