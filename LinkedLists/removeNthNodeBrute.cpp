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

Node* DeleteKfromLast(Node* head, int k){
    // brute force approach will be to count the length of the array and
    // making another traversal will (n-k) and standing at n-k delete the kth node
// {1,2,3,4,5,6,7,8}, k=3, remove 3rd element from last, stand at n-k=5 and delete 6
    Node* temp= head;
    int n=0;
    while(temp){
        n++;
        // traverse the node first and then increase the n when leaving the node
        temp=temp->next;
    }
    if(k==n) {
        // Edge condition
        // delete head
        Node* toDelete=head;
        head=head->next;
        delete toDelete;
        return head;
    }
    int count1=1;
    temp=head;
    while(count1<n-k){
        // here we are increasing the count first and then moving forward
        temp=temp->next;
        count1++;
    }
    // at last temp will stand at n-k
    Node* toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;
    return head;

}

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    Node* head=getLinkedList(arr);
    head=DeleteKfromLast(head, 8); //delete the 3rd element from last
    head=DeleteKfromLast(head, 4);
    printLinkedList(head);
    return 0;
}
