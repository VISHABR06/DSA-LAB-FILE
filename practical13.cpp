#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    // Enqueue: Push element into s1
    void enqueue(int x) {
        s1.push(x);
        cout << x << " enqueued\n";
    }

    // Dequeue: Move s1 -> s2, pop from s2
    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue Underflow\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << s2.top() << " dequeued\n";
        s2.pop();
    }

    // Peek: Show front element
    void peek() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Front element: " << s2.top() << endl;
    }

    // Display queue
    void display() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        // Move s1 → s2 to get correct order
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        stack<int> temp = s2;

        cout << "Queue elements: ";
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
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
