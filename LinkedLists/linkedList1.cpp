#include <iostream>
using namespace std;

//construction structure for linked list elements (integer types)
// struct Node{

//     public:
//     int data; 
//     Node* next; //node pointer to the next element

//     public:
//     //constructor for creating the node directly and passing the values
//     Node(int edata, Node* enext){
//         data=edata;
//         next=enext;
//     }
// };

class Node{
// class gives you the benefits of oops as well so we will go from struct to class, it works the exact same way
    public:
    int data; 
    Node* next; //node pointer to the next element

    public:
    //constructor for creating the node directly and passing the values
    Node(int edata, Node* enext){
        data=edata;
        next=enext;
    }

    Node(int edata){
        data= edata;
        next=nullptr; //defining multiple constructors
    }
};

int main(){

    //vector<int> arr={1,2,3,4,5};
    Node* y= new Node(5, nullptr); //making sure that you store the address of this node so that you can access the data and next pointer
    cout<<y->data <<" "<<y->next <<endl; 

    Node z= Node(4, nullptr);
    cout<<z.data<<z.next<<endl; //if you directly print z here it will throw error because you are printing an object 
    return 0;
}