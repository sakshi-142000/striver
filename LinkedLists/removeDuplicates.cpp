#include <iostream>
#include <vector>
#include <utility>
using namespace std;


class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    public:
    // contructors
    Node(int data1){
        data=data1;
        prev=nullptr;
        next=nullptr;
    }
    Node(int data1, Node* prev1, Node* next1){
        data=data1;
        prev=prev1;
        next=next1;
    }
};

Node* getDoublyLL(vector<int> &arr){
    Node* head= new Node(arr[0]); //prev of head is null for sure, next is null initially
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i], temp, nullptr);
        temp->next=newNode;
        temp=temp->next;//or newNode
    }
    return head;
}

void printDoublyLL(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* getRight(Node* head){
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    return temp;
}

Node* removeDuplicates(Node* head){
    // approach is to check the next node if equal continue untile you find a different number and change link there 
    Node* current= head;
    Node* temp=current->next;
// {1, 1, 1, 2, 2, 3, 4, 9};
    while(temp){   
        if(temp->data == current->data){
            if(temp->next){
                Node* toDelete=temp;
                current->next=temp->next;
                temp->next->prev=current;
                temp=temp->next;
                toDelete->next=nullptr;
                toDelete->prev=nullptr;
                // delete toDelete; these delete statements are giving segmentation errors 
            }
            else{
                current->next=nullptr; //standing at last node
                Node* toDelete=temp;
                toDelete->prev=nullptr;
                delete toDelete;
                break;
                // delete toDelete;
            }

        }
        else if(temp->data != current->data){
            current->next=temp;
            temp->prev=current;
            current=temp;
        }
    }
    return head;
}


int main(){
    vector<int> arr={1, 1, 1, 2, 2, 3,4, 4, 9,9};
    Node* head=getDoublyLL(arr);
    head= removeDuplicates(head);
    printDoublyLL(head);
    return 0;
}