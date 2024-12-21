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

Node* DeleteKfromLast(Node* head, int k){
    // optimal approach uses two pointer keeping the difference between the two k
    // fast pointer starts from 2 ahead of head and slow pointer start from head
    // when fast reaches end, slow points at one element before the kth index

    Node* fast=head;
    int count=0;
    while(count<k){
        count++;
        fast=fast->next;
    }
    // we already passed the last node
    if(fast==NULL){
        // delete the head node itself, this is when the k=length of linked list itself
        Node* toDelete=head;
        head=head->next;
        delete toDelete;
        return head;
    }
    Node* slow=head;
    while(fast->next){
        //stop when fast reached the last node
        slow=slow->next;
        fast=fast->next;
    }
    // at end, slow will be at k indices before the last node
    // stand at slow and delete k
    Node* toDelete=slow->next;
    slow->next=slow->next->next;
    delete toDelete;

    return head;
}

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    Node* head=getLinkedList(arr);
    head=DeleteKfromLast(head, 8); //delete the 3rd element from last
    head=DeleteKfromLast(head, 4);
    printLinkedList(head);
    return 0;
}
