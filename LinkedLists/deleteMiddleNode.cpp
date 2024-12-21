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
}

Node* deleteMiddleBrute(Node* head){
    // Bruteforce approach uses counting the length of the linked list and then 
    // going to the n/2 node which is the before node of middle and changing the links

    Node* temp=head;
    // 1,2,3,4,5
    // 1 2 3 4 5 6
    int length=0;
    while(temp){
        length++;
        temp=temp->next;
    }
    // go to node length/2 and delete the middle node from there 
    int mid=length/2;
    temp=head;
    while(temp){
        mid--;
        if(mid==0){
            // we are standing before the middle element
            Node* toDelete=temp->next;
            temp->next=temp->next->next;
            delete toDelete;
            break;
        }
        // before moving temp, check if the length has become 0
        temp=temp->next;
    } 
    return head;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=getLinkedList(arr);
    head=deleteMiddleBrute(head);
    printLinkedList(head);
    return 0;
}