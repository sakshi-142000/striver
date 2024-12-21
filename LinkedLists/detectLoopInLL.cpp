#include <iostream>
#include <vector>
#include <set>
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

Node* getLinkedList(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode= new Node(arr[i]);
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

void makeLoop(Node* head){
    Node* temp1=head;
    int count=4;
    while(count--){
        temp1=temp1->next;
    }
    Node* temp2=temp1;
    while(temp2->next){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

bool DetectLoopOptimal(Node* head){
    // optimal approach uses fast and slow pointer, moving slow by 1 and fast by 2 steps
    // so that in the loop even though we have difference in fast and slow pointer, the fast and slow meets up 
    // fast goes by speed of 2 and slow by 1, so every time in the loop, the difference between them decreases by 1
    // so if you think about it, initially, before, slow was chasing fast 
    // but once fast completes one round and starts in the loop again, fast chases behind slow

    // edge case: 
    if(head==NULL || head->next==NULL) return false;

    Node* fast=head->next->next;
    Node* slow=head->next;

    while(fast!=slow){
        if(fast==NULL) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    return true;

}

bool DetectLoopBrute(Node* head){

    if(head==NULL || head->next==NULL) return false;
    set<Node*> st;
    Node* temp=head;
    while(st.find(temp)==st.end()){
        if(temp==NULL) return false;
        st.insert(temp);
        temp=temp->next;
    }
    return true;

}


int main(){

    vector<int> arr={1,2,3,4,5,6,7,8};
    Node* head=getLinkedList(arr);

    makeLoop(head);
    
    cout<<DetectLoopBrute(head)<<endl;
    cout<<DetectLoopOptimal(head)<<endl;
    return 0;
}
