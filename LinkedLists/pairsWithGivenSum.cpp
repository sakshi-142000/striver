#include <iostream>
#include <vector>
#include <utility>
using namespace std;


class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    public:
    // contructors
    Node(int data1){
        data=data1;
        prev=nullptr;
        next=nullptr;
    }
    Node(int data1, Node* prev1, Node* next1){
        data=data1;
        prev=prev1;
        next=next1;
    }
};

Node* getDoublyLL(vector<int> &arr){
    Node* head= new Node(arr[0]); //prev of head is null for sure, next is null initially
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i], temp, nullptr);
        temp->next=newNode;
        temp=temp->next;//or newNode
    }
    return head;
}

void printDoublyLL(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* getRight(Node* head){
    Node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    return temp;
}

vector<pair<int, int>> findPairBrute(Node* head, int sumk){
    // bruteforce approach uses two loops 
    // 1, 2, 3, 4, 9
    vector<pair<int, int>> result;
    Node* temp1=head;
    while(temp1){
        Node* temp2= temp1->next;
        while(temp2 and temp1->data + temp2->data<= sumk){
            // break if any of the two conditions become true
            if(temp1->data + temp2->data == sumk){
                result.push_back({temp1->data, temp2->data});
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }

    return result;

}

// prob statement: given a sorted doubly linked list, return all the pairs 
// s.t sum of both the element in the pair equals k 

// to be solved using two pointer approach

vector<pair<int, int>> findPairOptimal(Node* head, int sumk){
    vector<pair<int, int>> result;

    Node* left=head;
    Node* right=getRight(head);

    while(left->data < right->data){
        if(left->data + right->data == sumk) {
            result.push_back({left->data,right->data});
            left=left->next;
            right=right->prev;
        }
        else if(left->data + right->data > sumk){
            // reduct the sum
            right=right->prev;
        }
        else left=left->next;
    }

    return result;

}


int main(){
    vector<int> arr={1, 2, 3, 4, 9};
    Node* head=getDoublyLL(arr);
    vector<pair<int, int>> result= findPairBrute(head, 5);

    for(auto i: result){
        cout<<i.first <<" "<<i.second<<endl;
    }
    return 0;
}