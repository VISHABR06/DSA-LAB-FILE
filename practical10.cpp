#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() { top = NULL; }

    void push(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
        cout << x << " pushed\n";
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        cout << top->data << " popped\n";
        top = top->next;
        delete temp;
    }

    void peek() {
        if (top == NULL)
            cout << "Stack is empty\n";
        else
            cout << "Top element: " << top->data << endl;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n";
        cin >> choice;

        if (choice == 1) {
            cin >> value;
            s.push(value);
        }
        else if (choice == 2) {
            s.pop();
        }
        else if (choice == 3) {
            s.peek();
        }
        else if (choice == 4) {
            s.display();
        }

    } while (choice != 5);

    return 0;
}
