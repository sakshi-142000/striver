#include <iostream>
#include <vector>
#include <stack>
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

Node* getMiddle(Node* head){
// using fast and slow pointer approach
    // 1,2,3,4,3,2,1 for odd 
// 1 2 3 4 4 3 2 1 for even
    Node* fast=head;
    Node* slow=head;
    while(fast->next and fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }

    // cout<<slow->data<<endl;working correctly
    return slow;
}

Node* reverseSecondHalf(Node* head){
    // 1,2,3,4,| 3,2,1 for odd 
    // 1 2 3 4 | 4 3 2 1 for even

    Node* prev=nullptr;
    Node* current=head;

    while(current){
        Node* front = current->next;
        current->next=prev;
        prev=current;
        current=front;
    }
    return prev;
}

bool isLLPalindrome(Node* head){
    // 1,2,3,4,| 3,2,1 for odd 
    // 1 2 3 4 | 4 3 2 1 for even

    // optimal approach:
    // first step: get the middle
    Node* mid= getMiddle(head);
    // second step: reverse the second half from mid->next
    Node* head2=reverseSecondHalf(mid->next);
    Node* head1=head;
    
    // third step: compare head1 and head2 ll
    // head1-> 1->2->3->4->4  head2->1->2->3->4->null

// odd scenario
    // head1 1,2,3,4| head2 1->2->3->null

    while(head1!=mid){
        if(head1->data!=head2->data) return false;
        head1=head1->next;
        head2=head2->next;
    }
    if(head2==NULL) return true;
    else {
        if(head1->data==head2->data) return true;
        else return false;
    }

    
}



int main(){
    vector<int> arr={1,2,3,4,5,3,2,1};
    Node* head=getLinkedList(arr);
    cout<<isLLPalindrome(head)<<endl;
    return 0;
}
