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

Node* sort0s1s2sBrute(Node* head){
    // bruteforce approach uses counting the number of 0s, 1s and 2s and then updating the data

    Node* temp=head;
    int count0=0, count1=0, count2=0;
    while(temp){
        if(temp->data == 0) count0++;
        else if (temp->data == 1) count1++;
        else if (temp->data ==2) count2++;

        temp=temp->next; 
    }
    temp=head; //second traversal for updating the data values
    // {1,1,2,0,2,0,1,0,2,2,0,1,0,1,0,2}
    while(temp){
        if(count0) {
            temp->data=0;
            count0--;
        }
        else if(count1){
            temp->data=1;
            count1--;
        }
        else if(count2){
            temp->data=2;
            count2--;
        }
        temp=temp->next;
    }

    return head;
}

int main(){
    vector<int> arr={1,1,2,0,2,0,1,0,2,2,0,1,0,1,0,2};
    Node* head=getLinkedList(arr);
    head=sort0s1s2sBrute(head);
    printLinkedList(head);
    return 0;
}