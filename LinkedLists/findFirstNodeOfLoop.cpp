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

// Problem Statement: given a linked list, return the first node of the loop

Node* firstLoopNodeBrute(Node* head){
    // uses hashing to store the nodes and break when you encounter the first node that appears again
    set<Node*> st;
    Node* temp=head;

    while(st.find(temp)==st.end()){
        // break once you find temp in st
        st.insert(temp);
        temp=temp->next;
    }
    return temp;

}

Node* firstLoopNodeOptimal(Node* head){
    // Optimal approach is AWESOME
    // uses fast and slow pointer, as usual, fast moves by 2 and slow by 1
    // if you assume the distance between head and first node to be l, 
    // if slow is at lth node then fast would be at 2l th node at that point,
    // now if distance between fast to slow is d then at collision point this distance will be 0
    // fast covering distance 1 at a time with the slow (himself moving by 2 and slow moving by 1)
    // total distance covered will be 2d by fast and d by slow

    // so now distance between collision point and fist node will be l
    // so if you move either fast or slow to head and move simultaneously from head to first node and
    // collision point to first node, you will reach the first node. 

    if(head==NULL or head->next==NULL) return NULL;
    Node* fast=head->next->next;
    Node* slow=head->next;

    while(fast!=slow){
        fast=fast->next->next;
        slow=slow->next;
    }
    // when fast and slow meet at first collision, move fast to head and slow remains at collision point and
    //  move the two pointers one by one the next collision will be the first node

    // distance between head and first node == distance between collision point and first node

    fast=head;
    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
    } 
    return fast;//or slow both are at first node
}


int main(){

    vector<int> arr={1,2,3,4,5,6,7,8,9,10,11,12};
    // first node is at 5 for this array
    Node* head=getLinkedList(arr);

    makeLoop(head);
    
    head=firstLoopNodeOptimal(head);
    cout<<head->data<<" ";
    head=firstLoopNodeBrute(head);
    cout<<head->data<<" ";
    //cout<<DetectLoopOptimal(head)<<endl;
    return 0;
}
