#include <iostream>
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int arr[5];

public:
    Queue() : front(-1), rear(-1)
    {
        for (int &item : arr)
        {
            item = 0;
        }
    }

    bool isEmpty() const
    {
        return (front == -1 && rear == -1);
    }

    bool isFull() const
    {
        return (rear == 4);
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue Overflow\n";
        }
        else
        {
            if (front == -1)
                front = 0;
            arr[++rear] = val;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return 0;
        }
        else
        {
            int popValue = arr[front];
            arr[front++] = 0;
            if (front > rear)
                front = rear = -1;
            return popValue;
        }
    }

    void display() const
    {
        cout << "All values in the Queue are:\n";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << "\n";
        }
    }
};

int main()
{
    Queue q;
    int option, value;

    do
    {
        cout << "What operation do you want to perform? Select Option number. Enter 0 to exit.\n"
             << "1. Enqueue()\n"
             << "2. Dequeue()\n"
             << "3. isEmpty()\n"
             << "4. isFull()\n"
             << "5. display()\n"
             << "6. Clear Screen\n\n";

        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter an item to enqueue in the queue\n";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            cout << "Dequeue Function Called - Dequeued Value: " << q.dequeue() << "\n";
            break;
        case 3:
            cout << (q.isEmpty() ? "Queue is Empty\n" : "Queue is not Empty\n");
            break;
        case 4:
            cout << (q.isFull() ? "Queue is Full\n" : "Queue is not Full\n");
            break;
        case 5:
            cout << "Display Function Called\n";
            q.display();
            break;
        case 6:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option Number\n";
        }
    } while (option != 0);

    return 0;
}