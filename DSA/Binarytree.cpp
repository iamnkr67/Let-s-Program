#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    Node *left;
    Node *right;
    int data;
 
    Node(int value)
    {
        right = nullptr;
        data = value;
        left = nullptr;
    }
};

Node *buildBinaryTree(vector<int> &arr)
{
    if (arr.empty())
        return nullptr;
    Node *root = new Node(arr.at(0));
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (i < arr.size())
    {
        Node *curr = q.front();
        q.pop();

        if (i < arr.size())
        {
            curr->left = new Node(arr.at(i));
            q.push(curr->left);
            i++;
        }
        if (i < arr.size())
        {
            curr->right = new Node(arr.at(i));
            q.push(curr->right);
            i++;
        }
    }
    return root;
}

void print(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *root = buildBinaryTree(arr);
    print(root);
    return 0;
}