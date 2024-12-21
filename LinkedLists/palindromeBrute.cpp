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

bool isLLPalindrome(Node* head){
    // prob statement: given a linked list with nodes return true is linked list is palindrome else false
    // bruteforce approach: use a stack to preserve the elements and then compare the ll elements with stack
    stack<int> st;
    Node* temp=head;

    while(temp){
        st.push(temp->data);
        temp=temp->next;
    }

    temp=head; //traverse again and compare the elements
    while(temp){
        if(temp->data!=st.top()) return false;
        st.pop();
        temp=temp->next;
    }
    return true;
}



int main(){
    vector<int> arr={1,2,3,4,4,3,2,1};
    Node* head=getLinkedList(arr);
    cout<<isLLPalindrome(head)<<endl;
    return 0;
}
