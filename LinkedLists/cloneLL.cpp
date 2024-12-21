#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    public:
    Node(int value){
        data=value;
        next=nullptr;
        random=nullptr;
    }

    Node(int value, Node* nextAddress, Node*randomAddress){
        data=value;
        next=nextAddress;
        random=randomAddress;
    }
};

Node* getLinkedList(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode= new Node(arr[1]);
        temp->next=newNode;
        temp->temp->next;
    }
    return head;
}

void connectRandoms(Node* head){
    // 9,8,2,6,0,4,1,2
    Node* temp=head;
    map<int, Node*> mpp;
    int i=1;
    while(temp){
        mpp[i]=temp;
        temp=temp->next;
        i++;
    }
    temp=head;
    while(temp){
        temp->random=mpp[i];
        i--;
        temp=temp->next;
    }
}

// prob statement: given a linked list with address to the next nodes and a random pointer pointing to a random node
// clone the list view 
// can't directly doing it in one traversal because if you create a new node, you can't point to the randome one because it has not yet been created

int main(){
    vector<int> arr={9,8,2,6,0,4,1,2};
    Node* head=getLinkedList(arr);
    connectRandoms(head);
    return 0;
}