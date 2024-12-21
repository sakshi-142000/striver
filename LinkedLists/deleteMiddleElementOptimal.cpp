#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int element)
    {
        data = element;
        next = nullptr;
    }

    Node(int element, Node *addressOfNext)
    {
        data = element;
        next = addressOfNext;
    }
};

Node *getLinkedList(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }

    return head;
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *deleteMiddleOptimal(Node *head)
{
    // optimal approach uses fast and slow pointer approach,
    // moving fast by 2 nodes and slow by 1
    // as we need slow to be before one pointer we will take one node back for the slow
    // odd: 1,2,3,4,5
    // even: 1,2,3,4,5,6

    Node *slow = head;
    Node *fast = head->next->next; // start fast before so that we get slow 1 node back

    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // now stand at slow and delete the middle node
    Node *toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = getLinkedList(arr);
    head = deleteMiddleOptimal(head);
    printLinkedList(head);
    return 0;
}