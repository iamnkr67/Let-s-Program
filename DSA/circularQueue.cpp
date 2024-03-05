#include <iostream>
using namespace std;

class Queue
{
    int front;
    int rear;
    int size;
    int *arr;

public:
    Queue(int s) : front(-1), rear(-1), size(s)
    {
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }

    void enqueue(int val);
    bool isEmpty();
    bool isFull();
    int dequeue();
    void display();
};
bool Queue::isFull()
{
    return ((rear == size - 1 && front == 0) || (rear + 1 == front));
}

bool Queue::isEmpty()
{
    return (front == -1 && rear == -1);
}

void Queue::enqueue(int val)
{
    if (isFull())
    {
        cout << "Queue is Full\n";
        return;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        arr[rear] = val;
    }
    else if (rear == size - 1 && front != 0)
    {
        rear = (rear + 1) % size;
        arr[rear] = val;
    }
    else
    {
        arr[++rear] = val;
    }
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!\n";
        return -1;
    }

    int data = arr[front];
    arr[front] = 0;
    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == size - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    return data;
}

void Queue::display()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!\n";
    }
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        for (int i = front; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        for (int i = 0; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
}

int main()
{
    int enqueuedDATA;
    Queue q(5);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(6);
    q.enqueue(7);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(8);
    q.enqueue(10);
    q.enqueue(16);
    q.enqueue(44);
    q.enqueue(88);
    q.display();
    return 0;
}