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

Node* reverseLLUsingStack(Node* head){
    Node* temp=head;
    stack<int> st;
    while(temp){
        st.push(temp->data);
        temp=temp->next;
    }
    // do a second traversal to change the data 
    temp=head;
    while(temp){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;

}

Node* reverseLLOptimal(Node* head){
    // optimal approach uses changing the links by memorising the next node
    Node* temp=head;
    Node* prev=NULL; //initially when changing the link, the head next will point to NUll
    while(temp){
        Node* front= temp->next;//saving the next node before changing the link
        temp->next=prev;
        prev=temp;
        temp=front;//when front equals to null be stop
    }
    return prev;
}

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    Node* head=getLinkedList(arr);
    head=reverseLLUsingStack(head);
    head=reverseLLOptimal(head);
    printLinkedList(head);
    return 0;
}
