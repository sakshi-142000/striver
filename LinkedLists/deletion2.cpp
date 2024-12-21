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

Node* deleteNnode(Node* head, int n){
    // given the nth node, delete it, it can be head or tail as well 
    if(head==NULL) return head; //do nothing, we do not have any elements in the linked list
    if(head->next==NULL) {
    //linked list only contains 1 element
        free(head);
        return NULL;
    }

    Node* temp=head;
    if(n==1) {
        head=head->next;
        free(temp);
        return head;
    }
    int count=1; 
    // {1,2, 3, 4, 5, 6, 7, 8, 9}
    while(count<n-1){
        //stand at the previous element
        count++;
        temp=temp->next;

    }
   
    Node* toDelete=temp->next; //temp is previous element to the element to delete
    cout<<temp->data<<endl;
    temp->next=temp->next->next; 
    free(toDelete);
    return head;
}



int main(){
    vector<int> arr={1,2, 3, 4, 5, 6, 7, 8, 9};
    Node* head = getLinkedList(arr);
    head=deleteNnode(head, 9);
    printLinkedList(head);
    head=deleteNnode(head, 1);
    printLinkedList(head);
    head=deleteNnode(head,4);
    printLinkedList(head);
    return 0;
}