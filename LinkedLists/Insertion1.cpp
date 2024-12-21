#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    
    public:
    Node(int element, Node* addressOfnext){
        data=element;
        next=addressOfnext;
    }
    Node(int element){
        data=element;
        next=nullptr;
    }
};

void printLinkedList(Node* head){

    Node* temp=head; //getting the pointer to head, never tamper the head
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* getLinkedList(int *arr, int n){
    Node* head= new Node(arr[0]); //creating the head node
    Node* mover=head; //{[1,null]}
    for(int i=1;i<n;i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp; //[1, address of temp]
        mover=mover->next; // or mover=temp;
    }

    return head;
}

Node* insertAtHead(Node* head){
    int data;
    cout<<"enter the value for the new node"<<endl;
    cin>>data;
    Node* newNode= new Node(data);
    newNode->next=head;
    return newNode;
}

Node* insertAtTail(Node* head){
    int data;
    cout<<"enter the value for the new node"<<endl;
    cin>>data;
    //insert at tail traverse till tail and stand at tail and then update the next 
    Node* newNode= new Node(data);
    Node* temp= head;

    while(temp->next){
        temp=temp->next;
    }

    temp->next=newNode;

    return head;

}

Node* insertAtKindex(Node* head){
    int data, k;
    cout<<"enter data and the kth position where you would like to add the element"<<endl;
    cin>>data>>k;
    Node* newNode= new Node(data);
    //stand at (k-1)th index and then update next 
    Node* temp=head;
    int count=1; //initially temp is standing at head, count=1

    while(count<k-1){
        count++;
        temp=temp->next; //move temp ahead by one node
    }

    // standing at k-1 node
    Node* saverightNode=temp->next;
    temp->next=newNode;
    newNode->next=saverightNode;

    return head;
}

Node* insertBeforeX(Node* head){
    int data, x;
    cout<<"enter data and x, x is the value before which you would like to enter the new data"<<endl;
    cin>>data>>x;

    Node* newNode= new Node(data);

    Node* temp=head;

    while(temp){
        // stand at the previous node to the node where data is x
        if(temp->next->data ==x) break;
        temp=temp->next;    
    }
    Node* saveXnode=temp->next;
    temp->next=newNode;
    newNode->next=saveXnode;

    return head;
    
}

int main(){

    int arr[]= {1,2,3,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(int);
    Node* head= getLinkedList(arr,n);
    cout<<"insertAtHead"<<endl;
    head=insertAtHead(head);
    printLinkedList(head);
    cout<<"insertAtTail"<<endl;
    head= insertAtTail(head);
    printLinkedList(head);
    cout<<"insertAtKindex"<<endl;
    head=insertAtKindex(head);
    printLinkedList(head);
    cout<<"insertBeforeX"<<endl;
    head=insertBeforeX(head);
    printLinkedList(head);

    return 0;
}