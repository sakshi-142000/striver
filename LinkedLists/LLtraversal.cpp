#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    // defining constructors
    Node(int element, Node* addressOfNext){
        data=element;
        next=addressOfNext;
    }

    Node(int element){
        data=element;
        next=nullptr;//if only passing element default the value of next to null
    }
};

Node* createLL(int *arr, int n){
    Node* head= new Node(arr[0]); //initially next in head is pointing to null
    Node* it=head; //for moving from one node to another, initially pointing to head

    for(int i=1;i<n;i++){
        Node* temp= new Node(arr[i]); 
        it->next=temp; 
        it=temp;// incrementing it
    }

    return head;
}

void traverseLL(Node* head){
    Node* temp=head; //never alter the head pointer 

    // if you give condition while(temp->next) then if your linked list only contains one element or if temp if on last element then that last element will not be printed

    // while(temp->next){
    //     //while temp->next is not pointing to null
    //     cout<<temp->data<<endl;
    //     temp=temp->next;
    // }

    // instead

    while(temp){
        // while temp is not poiting to null 
        cout<<temp->data<<endl;
        temp=temp->next; //increment temp to point ot the next element
    }

}

bool searchInLL(Node* head, int x){
    // search for x in linked list
    Node* temp= head;//creating a temp node for traversal, never ever change the head
    while(temp!=nullptr){
        if(temp->data == x) return true;
        temp=temp->next;
    }
    return false;
}

int countLenthLL(Node* head){
    Node* temp=head;
    int count=0;
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}

int main(){
    int arr[]={1, 5, 7, 9};
    int n=sizeof(arr)/sizeof(int);
    Node* head= createLL(arr, n);
    traverseLL(head); //passing the head pointer 
    cout<<searchInLL(head, 4);
    cout<<countLenthLL(head);
    return 0;
}