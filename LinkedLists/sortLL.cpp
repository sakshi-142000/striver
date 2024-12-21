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
    Node(int element, Node* nextAddress){
        data=element;
        next=nextAddress;
    }
};

Node* getLinkedList(vector<int> &arr){
    if(arr.size()==0) return NULL;
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

Node* getMiddle(Node* head){
    if(head->next==NULL || head->next->next ==NULL || head->next==NULL) return head;
    Node* slow=head;
    Node* fast=head;
    while(fast->next and fast->next->next){
        // if any of them becomes null break
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* mergeLL(Node* head1, Node* head2){
    Node* dummy=new Node(-1);
    Node* temp=dummy;

    while(head1 and head2){
        // if any of them become null break
        if(head1->data <= head2->data){
            temp->next=head1;
            head1=head1->next;
            temp=temp->next; 
        }
        else{
            temp->next=head2;
            head2=head2->next;
            temp=temp->next; //moving both temp1 and temp
        }
    }
    while(head1){
        // if we still have elements left
        temp->next=head1;
        head1=head1->next;
        temp=temp->next; //moving both temp1 and temp
    }
    while(head2){
        // if we still have elements left
        temp->next=head2;
        head2=head2->next;
        temp=temp->next; //moving both temp1 and temp
    }

    return dummy->next;


}

Node* SortLL(Node* head){
    // 9,8,7,6,5,3
    if(head==NULL or head->next==NULL) return head; //ll just contains one element
    Node* middleNode= getMiddle(head); //this will return 7 
    Node* head2=middleNode->next;
    middleNode->next=NULL;
    head=SortLL(head);
    head2=SortLL(head2);
    return mergeLL(head, head2);

}
int main(){

    vector<int> arr={};
    Node* head= getLinkedList(arr);
    head=SortLL(head);
    printLinkedList(head);
    return 0;

}