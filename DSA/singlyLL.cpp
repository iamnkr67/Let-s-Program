#include <iostream>
#include <vector>
using namespace std;
/* Singly Linked List is the linear data structure in which every node is connected with next node using pointer that points the next element address.*/
class Node
{
public:
    int data;
    Node *next;

    Node(int value, Node *n)
    {
        data = value;
        next = n;
    }

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lengthOfLL(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int checkIfPresent(Node *head, int val)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
            return 1;
        temp = temp->next;
    }
    return 0;
}

Node *insertAtBegin(Node *head, int val)
{
    return new Node(val, head);
}

Node *insertAtEnd(Node *head, int val)
{
    if (head == NULL)
        return new Node(val);

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node *insertAtKth(Node *head, int val, int k)
{
    if (head == NULL)
    {
        if (k == 1)
            return new Node(val);
        else
            return NULL;
    }

    if (k == 1)
    {
        Node *temp = new Node(val, head);
        return temp;
    }
    int count = 0;
    Node *temp = head;

    while (temp->next != NULL)
    {
        count++;
        if (count == k - 1)
        {
            Node *x = new Node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node *insertAtGivenNextValue(Node *head, int curr, int val)
{
    Node *temp = head, *prev = NULL;
    Node *newNode = new Node(val);

    while (temp != NULL)
    {
        if (temp->data == curr)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        temp = temp->next;
    }
    return head;
}

Node *deleteHead(Node *head)
{
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node *deleteKth(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int count = 0;
    Node *temp = head, *prev = NULL;

    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *deleteValue(Node *head, int val)
{
    if (head == NULL)
        return head;

    Node *temp = head, *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == val)
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int searchLinkedListByValue(Node *head, int val)
{
    Node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value not found in the list.\n";
    return -1;
}

int searchLLByPosition(Node *head, int pos)
{
    Node *current = head;
    int count = 1;

    while (current != NULL && count < pos)
    {
        current = current->next;
        count++;
    }

    if (current == NULL)
    {
        cout << "Position out of range.\n";
        return -1;
    }

    return current->data;
}

Node *reverseLL(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArr2LL(arr);
    // head = insertAtBegin(head, 55);
    // head = insertAtEnd(head, 83);
    // head = insertAtKth(head, 23, 2);
    // head = deleteKth(head, 3);
    // head = deleteValue(head, 23);
    // int search = searchLLByPosition(head, 2);
    // cout << search;
    head = reverseLL(head);
    print(head);

    return 0;
}