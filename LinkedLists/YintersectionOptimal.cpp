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
//  Optimal Approach: traverse both l1 and l2 till you reach the end of any one of the LL,
// the one who reaches early is the shorter one, so move the node pointer to the next LL instead
//  and start traversing, do the same with the other LL as well this will make sure that at one point 
// both of them start at the same level


    Node* temp1=head1;
    Node* temp2=head2;

    while(temp1 || temp2){
        // stop when both temp1 and temp2 becomes null at the same point
        if(temp1==temp2) return temp1;
        else if(temp1==NULL) temp1=head2;
        else if(temp2==NULL) temp2=head1;

        temp1=temp1->next;
        temp2=temp2->next;
    }
    return NULL; 
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
    vector<int> arr1={1,2,3};
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
