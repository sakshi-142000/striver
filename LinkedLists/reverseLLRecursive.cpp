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

Node* reverseLL(Node* current, Node* prev){
    if(current==NULL) return prev;
    Node* front=current->next;
    current->next=prev;
    return reverseLL(front,current);
}



int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    Node* head=getLinkedList(arr);
    head=reverseLL(head, nullptr);
    printLinkedList(head);
    return 0;
}
