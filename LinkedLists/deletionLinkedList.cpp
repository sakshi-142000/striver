#include <iostream>
#include <vector>
using namespace std;

//create the class for node 

class Node{
    public:
    int data;
    Node* next; //pointer to the next node

    public:
    // constructors

    Node(int element, Node* addressOfNext){
        data= element;
        next=addressOfNext;
    }
    Node(int element){
        data=element;
        next= nullptr;
    }
}; 

void printLinkedList(Node* head){

    Node* temp=head; //getting the pointer to head, never tamper the head
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

Node* getLinkedList(vector<int> &arr){
    Node* head= new Node(arr[0]); //creating the head node
    Node* mover=head; //{[1,null]}
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp; //[1, address of temp]
        mover=mover->next; // or mover=temp;
    }

    return head;
}

Node* deleteHead(Node* head){
    //delete head and return the new head
    Node* temp=head; //saving the head pointer for freeing up memory 
    head=head->next;
    free(temp);
    return head;
}

Node* deleteTail(Node* head){
    Node* temp=head;
    //to delete the tail you need to stop at the second last element of the linked list
    while(temp->next->next){
        // temp->next->next imagine you are at head and you only have 2 elements in the linked list then this will point to null
        temp=temp->next;
    }
    free(temp->next); //freeing up the tail
    temp->next=nullptr;
    return head;
}

Node* deleteNElement(Node* head, int n){
    // delete nth element and return the head
    // 1 2 3 4 5 6 n=3
    Node* temp=head; 
    int count=1; 
    // go till element n-1 and stand at there and then update the nth node
    while(count<n-1 and temp){
        temp=temp->next;
        count++;
    }
    Node* toDeleteNode= temp->next;
    temp->next=temp->next->next;
    free(toDeleteNode);

    return head; 
}

int main(){
    vector<int> arr={1,2, 3, 4, 5, 6, 7, 8, 9};
    Node* head = getLinkedList(arr);
    printLinkedList(head);
    head= deleteHead(head);
    cout<<"after deleting head"<<endl;
    printLinkedList(head);
    head=deleteTail(head);
    cout<<"after deleting tail"<<endl;
    printLinkedList(head);
    head = deleteNElement(head, 3);
    cout<<"after deleting 3rd element"<<endl;
    printLinkedList(head);
    return 0;

}