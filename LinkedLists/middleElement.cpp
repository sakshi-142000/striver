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

Node* findMiddleBruteForce(Node* head){
    // prob statement: given a linked list return the middle node of the linked list
    // return the 2nd middle in case of even number of nodes

    // brute force approach includes,  counting the number of elements and return the n/2 +1th element

    Node* temp=head;
    int count=0;
    while(temp){
        // visit the node first and then increase the count, stop when you reach null after the last node visit
        count++;
        temp=temp->next;
    }
    // 1,2,3,4,5,6,7
    int middleIndex=(count/2)+1; 
    temp=head;
    while(middleIndex>1){
        // when you reach 3, the middleIndex count will be 2 and 1 when you leave the node
        middleIndex--;
        temp=temp->next;
    }
    return temp; //temp is pointing to the middle index node here 
}



int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    Node* head=getLinkedList(arr);
    Node* middleNode= findMiddleBruteForce(head);
    cout<<middleNode->data<<endl;
    return 0;
}
