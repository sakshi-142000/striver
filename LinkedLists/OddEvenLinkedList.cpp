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

int LinkedListLength(Node* head){
    int count=0;
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        count++;
        temp=temp->next;
    }
    cout<<endl;
    return count;
}

void printLinkedList(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
    cout<<endl;
}

Node* seggregateOddEven(Node* head){
    // bruteforce approach includes saving all the elements in a array first and then changing the data per required
    // edge case:
    if(head==NULL || head->next==NULL) return head;
    vector<int> arr;
    Node* temp=head;
    // {1, 2, 3, 4, 5, 6, 7, 8}
    while(temp!=NULL && temp->next!=NULL){
        arr.push_back(temp->data);
        temp=temp->next->next;
        // cout<<"running1 while"<<endl;
    }
    if(temp) arr.push_back(temp->data);
    temp=head->next;
    while(temp!=NULL && temp->next!=NULL){
        arr.push_back(temp->data);
        temp=temp->next->next;
        // cout<<"running2 while"<<endl;
    }
    if(temp) arr.push_back(temp->data);
    temp=head;
    int i=0;
    while(temp and i<arr.size()){
        temp->data=arr[i];
        i++;
        temp=temp->next;
        // cout<<"running3 while"<<endl;
    }

    return head;
}



int main(){
    //Given the head of a singly linked list. 
    // Group all the nodes with odd indices followed by all the nodes with even indices and return the reordered list.

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    Node* head = getLinkedList(arr);
    head=seggregateOddEven(head);
    printLinkedList(head);

    return 0;
   
}