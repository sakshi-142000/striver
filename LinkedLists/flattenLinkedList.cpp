#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* child;

    public:
    Node(int element){
        data=element;
        next=nullptr;
        child=nullptr;
    }

    Node(int element, Node* nextAddress, Node* childAddress){
        data=element;
        next=nextAddress;
        child=childAddress;
    }

};

void getArray(vector<int> &arr){
    int n;
    cout<<"enter the number of chils and then the child values"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }
}

Node* getLinkedList(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode= new Node(arr[i]);
        temp->child=newNode;
        temp=temp->child;
    }

    return head;               
}

void printLinkedList(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->child;
    }
    cout<<endl;
}

// problem statement: given a linked list with child nodes in sorted order, 
// flatten the list view such that all the nodes in are in ascending order
// st, node->next=null and all the nodes are child of this node 

Node* MergeLL(Node* temp1, Node* temp2){
    Node* dummyNode=new Node(-1); //dummy->next will be null and dummy->child will also be null

    Node* temp=dummyNode;
    while(temp1 and temp2){
        // if any of them become null break
        if(temp1->data <= temp2->data){
            temp->child=temp1;
            temp1=temp1->child;
            temp=temp->child; //moving both temp1 and temp
        }
        else{
            temp->child=temp2;
            temp2=temp2->child;
            temp=temp->child; //moving both temp1 and temp
        }
    }
    while(temp1){
        // if we still have elements left
        temp->child=temp1;
        temp1=temp1->child;
        temp=temp->child; //moving both temp1 and temp
    }
    while(temp2){
        // if we still have elements left
        temp->child=temp2;
        temp2=temp2->child;
        temp=temp->child; //moving both temp1 and temp
    }

    return dummyNode->child;
}

Node* flattenLinkedList(Node* temp1){
    // initially we will pass head as temp1 in the recursion call
    if(temp1==NULL) return NULL;
    Node* temp2=flattenLinkedList(temp1->next);
    return MergeLL(temp1, temp2);
}

Node* flattenLinkedListBruteApproach(Node* head){
    // brute force approach includes traversing all the nodes,
    // storing the values in a array and then creating a linked list with new nodes and values as that of the nodes
    // ofc you need to sort the array first
    vector<int> nodes;
    Node* temp=head;

    while(temp){
        Node* temp1=temp;
        while(temp1){
            nodes.push_back(temp1->data);
            temp1=temp1->child;
        }
        temp=temp->next;
    }
    sort(nodes.begin(), nodes.end());
    Node* newHead=new Node(nodes[0]);
    temp=newHead;
    for(int i=1;i<nodes.size();i++){
        Node* newNode= new Node(nodes[i]);
        temp->child=newNode;
        temp=temp->child;
        
    }
    return newHead;

}


int main(){
    vector<int> arr;
    cout<<"enter the number of nodes"<<endl;
    int n;
    cin>>n;
    Node* head=nullptr;
    Node* previousNode=nullptr;
    for(int i=0;i<n;i++){
        vector<int> arr;
        getArray(arr);
        Node* newNode=getLinkedList(arr);
        if(previousNode) previousNode->next=newNode;
        else head=newNode;
        previousNode=newNode;
    }
    head=flattenLinkedListBruteApproach(head);
    printLinkedList(head);
    return 0;
}