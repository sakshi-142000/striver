#include <iostream>
#include <vector>
#include <set>
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

Node* getLinkedList(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode= new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
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

Node* getIntersectionPoint (Node* head1, Node* head2, int diff){
// head1 has longer length than head2
    Node *temp= head1;
    // moving temp diff steps ahead
    while(diff>0){
        temp=temp->next;
        diff--;
    }
    // temp is now standing at same level as of head2
    Node *temp1= head2;
    while(temp){
        if(temp==temp1){
            return temp;
        }
        temp=temp->next;
        temp1=temp1->next;
    }
    return NULL;

}

Node* YIntersectionPoint(Node* head1, Node* head2){
    // given two linked lists, return their first intersection point, if not exists, then return NULL
//LL1:   1 2 3 4 5 |9 10 11 
//LL2:   6 7 8 |9 10 11 
//  Better approach uses finding the length of the the two linked lists first
// eg l1- 8, l2=6 , move l1 2 nodes ahead so that we start at the same position node with the l2 for comparison

    Node* temp=head1;
    int n1=0;
    while(temp){
        n1++;
        temp=temp->next;
    }
    temp=head2;
    int n2=0;
    while(temp){
        n2++;
        temp=temp->next;
    }

    if(n1>n2){
        return getIntersectionPoint(head1, head2, n1-n2);
    }
    else return getIntersectionPoint(head2, head1, n1-n2);

}


Node* makeIntersection(Node* head1, Node* head2){
    Node* temp=head1;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=head2;
    return head1;
}

int main(){
    vector<int> arr1={1,2,3,4,5};
    vector<int> arr2={6,7,8};
    vector<int> arr3={9,10,11};
    Node* head1=getLinkedList(arr1);
    Node* head2=getLinkedList(arr2);
    Node* head3=getLinkedList(arr3);
    head1=makeIntersection(head1,head3);
    head2=makeIntersection(head2,head3);
    printLinkedList(head1);
    printLinkedList(head2);

    Node* intersectionPoint= YIntersectionPoint(head1, head2);
    cout<<intersectionPoint->data<<endl;
    return 0;
}
