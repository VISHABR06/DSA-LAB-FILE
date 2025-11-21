#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert at beginning
void insertBegin(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
    cout << x << " inserted at beginning\n";
}

// Insert at end
void insertEnd(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        Node* t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = temp;
    }
    cout << x << " inserted at end\n";
}

// Insert at given position (1-based)
void insertPos(int x, int pos) {
    Node* temp = new Node();
    temp->data = x;

    if (pos == 1) {
        temp->next = head;
        head = temp;
        cout << x << " inserted at position " << pos << endl;
        return;
    }

    Node* t = head;
    for (int i = 1; i < pos - 1 && t != NULL; i++)
        t = t->next;

    if (t == NULL) {
        cout << "Position out of range\n";
        delete temp;
        return;
    }

    temp->next = t->next;
    t->next = temp;

    cout << x << " inserted at position " << pos << endl;
}

// Display list
void display() {
    Node* t = head;

    if (t == NULL) {
        cout << "List is empty\n";
        return;
    }

    cout << "Linked List: ";
    while (t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    int choice, x, pos;

    do {
        cout << "\n1.Insert at Beginning\n2.Insert at End\n3.Insert at Position\n4.Display\n5.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> x;
            insertBegin(x);
            break;

        case 2:
            cin >> x;
            insertEnd(x);
            break;

        case 3:
            cin >> x >> pos;
            insertPos(x, pos);
            break;

        case 4:
            display();
            break;

        case 5:
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
