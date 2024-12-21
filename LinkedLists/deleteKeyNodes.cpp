#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int element){
        data=element;
        next=nullptr;
        prev=nullptr;
    }

    Node(int element, Node* nextAddress, Node* prevAddress){
        data=element;
        next=nextAddress;
        prev=prevAddress;
    }

};

Node* getDoublyLinkedList(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;

    for(int i=1;i<arr.size();i++){
        Node* newNode= new Node(arr[i],nullptr,temp); //prev=temp
        temp->next=newNode;
        temp=temp->next;
    }

    return head;
}

void printDoublyLinkedList(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* deleteKeys(Node* head, int k){
    // delete all the nodes where key value; data=k

    Node* temp=head;
    Node* back=nullptr;
    while(temp){
        if(temp->data==k){
            // delete the node
            Node* front=temp->next;
            if(front) front->prev=back;
            if(back) back->next=front;
            else head=front;
            Node* toDelete=temp;
            temp=front; //moving forward
            delete toDelete;
        }
        else{
            back=temp;
            temp=temp->next;
        }
    }

    return head;
}




int main(){

    vector<int> arr={10,4, 10, 10, 6, 10};
    Node* head=getDoublyLinkedList(arr);
    printDoublyLinkedList(head);
    head=deleteKeys(head,10);
    printDoublyLinkedList(head);
    return 0;
}