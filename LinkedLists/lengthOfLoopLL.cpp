#include <iostream>
#include <vector>
#include <set>
#include <map>
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

int LoopLengthOptimal(Node* head){
    // optimal approach uses fast and slow pointer, moving slow by 1 and fast by 2 steps
    // so that in the loop even though we have difference in fast and slow pointer, the fast and slow meets up 
    // fast goes by speed of 2 and slow by 1, so every time in the loop, the difference between them decreases by 1
    // so if you think about it, initially, before, slow was chasing fast 
    // but once fast completes one round and starts in the loop again, fast chases behind slow

    // 

    // edge case: 
    if(head==NULL || head->next==NULL) return 0;

    Node* fast=head->next->next;
    Node* slow=head->next;

    while(fast!=slow){
        if(fast==NULL) return false;
        fast=fast->next->next;
        slow=slow->next;
        
    } 
    // when fast ==slow 
    // cout<<fast->data<<" "<<slow->data<<endl;
    fast=fast->next;
    int count=1;
    while(fast!=slow){
        fast=fast->next;
        count++;
        // cout<<count<<endl;
    }
    return count;

}

int loopLengthBrute(Node* head){

    if(head==NULL || head->next==NULL) return 0;//no loop
    map<Node*, int> mpp; //key will be the node address and count will be it's occurence
    Node* temp=head;
    int count=1;
    while(mpp.find(temp)==mpp.end()){
        mpp[temp]=count;
        count++;
        // cout<<count<<endl;
        temp=temp->next;
    }
    // cout<<mpp[temp]<<" "<<count<<endl;
    int result= count-mpp[temp];
    return result;

}


int main(){

    vector<int> arr={1,2,3,4,5,6,7,8,9,10,11,12};
    Node* head=getLinkedList(arr);

    makeLoop(head);
    
    cout<<loopLengthBrute(head)<<endl;
    cout<<LoopLengthOptimal(head)<<endl;
    
    //cout<<DetectLoopOptimal(head)<<endl;
    return 0;
}
