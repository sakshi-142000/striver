#include <iostream>
#include <vector>
#include <stack>
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
    Node(int element, Node* nextAddress){
        data=element;
        nextAddress=next;
    }

};

Node* getLinkedList(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode= new Node(arr[i]);
        temp->next=newNode;
        temp=temp->next;
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

Node* reverseLL(Node* head){
    Node* prev=nullptr;
    Node* current=head;

    while(current){
        Node* front=current->next;
        current->next=prev;
        prev=current;
        current=front;
    }
    return prev;
}

Node* addOneToNumber(Node* head){
    // prob statement: given a number represented by linked list, return the 1+the number represented using the same linked list
    // eg 1->2->9 
    // reverse linked list: 9->2->1 >> +1 >>> 0 3 1 >>reverse again>> 130
    Node* tempHead=reverseLL(head);
    int carryover=1; 
    Node* temp=tempHead;
    while(temp){
        int sum=0;
        sum=temp->data+carryover;
        carryover=sum/10;
        sum=sum%10;
        temp->data=sum;
        if(carryover==0) break;
        temp=temp->next;
    }
    tempHead=reverseLL(tempHead);
    if(carryover){
        Node* carry=new Node(carryover);
        carry->next=tempHead;
        tempHead=carry;
    } 

    return tempHead;

}


int main(){
    vector<int> arr={9,9,9};
    Node* head=getLinkedList(arr);
    head=addOneToNumber(head);
    printLinkedList(head);
    return 0;
}
