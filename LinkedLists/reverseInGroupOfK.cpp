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

Node* reverseLinkedList(Node* head){

    if(head ==NULL || head->next==NULL) return head;
    Node* temp=head;
    Node* prev=nullptr;
    while(temp){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
// prob statement: given a linked list, reverse the linked list in groups of k
// 1,2,3,4,5,6,7,8,9,10
Node* reverseInGroup(Node* head, int k){
    Node* temp=head;
    Node* previousNode=NULL; //initially
    while(temp){
        Node* temp1=temp;
        int count=0; 
        while(temp1){
            count++;
            if(count==k) break;
            temp1=temp1->next;
        }
        if(temp1==NULL) {
            // couldn't make a group
            previousNode->next=temp;
            return head;
        }
        // temp1 is now standing at the kth node 
        Node* nextNode=temp1->next; //saving the nextnode 
        temp1->next=nullptr; //separating the linked list
        reverseLinkedList(temp); //this will return temp1 for sure 
        if(previousNode) {
            previousNode->next=temp1;
            previousNode=temp;
            
        }else {
            head=temp1;
            previousNode=temp;
        }
        temp->next=nextNode; //connecting the linked list
        temp=nextNode;
    }
    return head;
}


int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    Node* head=getLinkedList(arr);
    head=reverseInGroup(head,3);
    printLinkedList(head);
    return 0;
}