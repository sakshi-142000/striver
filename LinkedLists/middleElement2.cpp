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

Node* findMiddleOptimal(Node* head){
    // prob statement: given a linked list return the middle node of the linked list
    // return the 2nd middle in case of even number of nodes

    // Optimal approach used slow and fast pointer (turtoise and hare algo)
    // slow moves by one and fast moves by 2 nodes
    // since fast covers twice the distance than slow, when fast reaches end, slow reaches the middle

    Node* slow=head;
    Node* fast=head;
// 1,2,3,4,5,6,7,8 //slow will be at the 2nd mid element in case of even number of nodes
    while(fast!=NULL && fast->next){
        // stop when either fast is null(even case) or fast->next is null(odd case)
        slow=slow->next;
        fast=fast->next->next;
        
    }
    return slow;
}



int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    Node* head=getLinkedList(arr);
    Node* middleNode= findMiddleOptimal(head);
    cout<<middleNode->data<<endl;
    return 0;
}
