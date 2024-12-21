#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    // please make sure to make the data public
    int data;
    Node* next; //pointer to the next node

    public:

    // constructors
    Node(int element, Node* addressOfNextNode){
        data=element;
        next=addressOfNextNode;
    }
    Node (int element){
        data=element;
        next=nullptr;
    }

};

Node* convertArrayToLl(int *arr, int n){
    Node* head= new Node(arr[0]); //creating the head pointer will will have the data as arr[0] and next pointing to null initially
    Node* mover=head; //mover pointer is initially pointing to head
    for(int i=1;i<n;i++){
        Node* temp= new Node(arr[i]);
        mover->next=temp; //mover's next will store the address of this new node which is containing arr[i]
        mover=temp; //or mover=mover->next
    }

    return head;
}



int main(){
// given an array, convert the array into linked list and return the pointer to the linked list
    // vector<int> arr={1,2,3,4,5};
    int arr[]={1,2,3,4,5};
    cout<<convertArrayToLl(arr,5)->data<<endl;
    return 0;
}