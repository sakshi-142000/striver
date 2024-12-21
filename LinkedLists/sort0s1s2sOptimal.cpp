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

Node* sort0s1s2sOptimal(Node* head){

    // extreme edge case no elements or only one element
    if(head==NULL or head->next==NULL) return head; 
// optimal approach uses separating the linked lists for 0s 1s 2s 
    Node* dummyZeroHead = new Node(-1);
    Node* dummyOneHead = new Node(-1);
    Node* dummyTwoHead = new Node(-1);

// these node are for iterations
    Node* tempZero=dummyZeroHead;
    Node* tempOne=dummyOneHead;
    Node* tempTwo=dummyTwoHead;

    // {1,1,2,0,2,0,1,0,2,2,0,1,0,1,0,2};

    Node* temp=head;
    while(temp){
        if(temp->data == 0) {
            tempZero->next=temp;
            tempZero=tempZero->next;
        }
        else if(temp->data==1){
            tempOne->next=temp;
            tempOne=tempOne->next;
        }
        else if (temp->data==2){
            tempTwo->next=temp;
            tempTwo=tempTwo->next;
        }
        temp=temp->next;
    }
    // after separating the 0s, 1s, and 2s in separate lists, connect them based on conditions
// tempzero will connect to tempOnes, if there are no one then it will connect to twos,
// if there are no twos as well then tempZero will directly point to dummyTwoHead->next which is null 
    tempZero->next=(tempOne->next!=NULL)?dummyOneHead->next: dummyTwoHead->next;
    // connecting 1s to 2s
    tempOne->next=dummyTwoHead->next; 
    tempTwo->next=NULL; //make sure you end the linked list
    
    head=dummyZeroHead->next;
    delete dummyZeroHead;
    delete dummyOneHead;
    delete dummyTwoHead;
    return head;
}

int main(){
    vector<int> arr={1,1,2,0,2,0,1,0,2,2,0,1,0,1,0,2};
    Node* head=getLinkedList(arr);
    head=sort0s1s2sOptimal(head);
    printLinkedList(head);
    return 0;
}