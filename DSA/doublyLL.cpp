#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

Node *convertArr2DLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }
    return head;
}

void print(Node *head, ofstream &outfile)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        outfile << temp->data << " ";
        temp = temp->next;
    }
    outfile << endl;
}

int sizeOfDLL(Node *head)
{
    Node *slow = head, *fast = head;
    int count = 0;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        count++;
    }

    return count * 2;
}

Node *insertAtBegin(Node *head, int val)
{
    Node *new_Node = new Node(val);
    new_Node->next = head;
    head = new_Node;
    return head;
}

Node *insertAtEnd(Node *head, int val)
{
    Node *new_Node = new Node(val);
    Node *mover = head;

    while (mover->next != NULL)
    {
        mover = mover->next;
    }
    mover->next = new_Node;
    return head;
}

Node *insertAtMid(Node *head, int val)
{
    Node *new_Node = new Node(val);
    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    new_Node->next = slow->next;
    slow->next = new_Node;

    return head;
}

int main()
{
    ofstream outfile;
    outfile.open("output.txt", ios::app);
    outfile << "-----------------------" << endl;
    vector<int> arr = {5, 10, 4, 32, 16};
    Node *head = convertArr2DLL(arr);
    head = insertAtBegin(head, 88);
    head = insertAtEnd(head, 85);
    head = insertAtMid(head, 41);
    print(head, outfile);

    // Open the file in append mode
    outfile << "Head of DLL: " << head->data;
    outfile << endl
            << "Size of DLL: "
            << sizeOfDLL(head);
    outfile.close();
    return 0;
}