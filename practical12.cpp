#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* temp = new Node();
        temp->data = value;
        temp->next = NULL;

        if (rear == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        cout << value << " enqueued\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;
        cout << front->data << " dequeued\n";
        front = front->next;

        if (front == NULL) 
            rear = NULL;  // queue becomes empty

        delete temp;
    }

    // Peek operation
    void peek() {
        if (front == NULL)
            cout << "Queue is empty\n";
        else
            cout << "Front element: " << front->data << endl;
    }

    // Display operation
    void display() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
