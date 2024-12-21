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
    Node(int element, Node* addressOfNext){
        data=element;
        next=addressOfNext;
    }

};

Node* getLinkedList(vector<int> &arr){
    Node* head= new Node(arr[0]); 
    Node* mover=head; 
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp; 
        mover=mover->next; 
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

// problem statement: given two reverse numbers, digits placed in linked list nodes,
// return a third linked list which contatins the sum of the first num and second num
// digits placed in ll node in reverse order just like the input nums

Node* addLLs(Node* head1, Node* head2){
    Node* dummy=new Node(-1);
    Node* temp=dummy; //we will save dummy for returning and will move temp

    Node* t1=head1;
    Node* t2=head2;
// num1={3,8,7}; 
// num2={5,2,4,9};
    int carryover=0; //initially
    while(t1 || t2){
        Node* t3=new Node(-1);
        temp->next=t3;
        int sum=0;
        if(t1) {
            // if t1 is not pointing to null then 
            sum+=t1->data;
        }
        if(t2) sum+=t2->data;
        sum+=carryover;
        carryover=sum/10;
        sum%=10;
        t3->data=sum;
        temp=temp->next;
        if(t1) t1=t1->next;
        if(t2) t2=t2->next;
        // cout<<"Running1"<<endl;
    }
    if(carryover){
        Node* t3= new Node(carryover);
        temp->next=t3;
        // cout<<"Running1"<<endl;
    }
    // cout<<"Running1"<<endl;
    return dummy->next;
}

int main(){
    // add 783 and 9425 , head1 pointing to 3 and 5 
    vector<int> num1={3,8,7}; 
    vector<int> num2={5,2,4,9};
    Node* head1=getLinkedList(num1);
    Node* head2=getLinkedList(num2);
    // printLinkedList(head2);

    Node* head3=addLLs(head1, head2);
    printLinkedList(head3);
    return 0;
}
