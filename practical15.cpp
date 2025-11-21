#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert for testing
void insertEnd(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }
    Node* t = head;
    while (t->next != NULL) t = t->next;
    t->next = temp;
}

// Delete by value
void deleteByValue(int x) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    // If head holds the value
    if (head->data == x) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << x << " deleted\n";
        return;
    }

    Node* t = head;
    while (t->next != NULL && t->next->data != x)
        t = t->next;

    if (t->next == NULL) {
        cout << "Value not found\n";
        return;
    }

    Node* temp = t->next;
    t->next = temp->next;
    delete temp;

    cout << x << " deleted\n";
}

// Delete by position (1-based)
void deleteByPos(int pos) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node at position " << pos << " deleted\n";
        return;
    }

    Node* t = head;
    for (int i = 1; i < pos - 1 && t != NULL; i++)
        t = t->next;

    if (t == NULL || t->next == NULL) {
        cout << "Position out of range\n";
        return;
    }

    Node* temp = t->next;
    t->next = temp->next;
    delete temp;

    cout << "Node at position " << pos << " deleted\n";
}

void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* t = head;
    cout << "Linked List: ";
    while (t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    int choice, value, pos;

    do {
        cout << "\n1.Insert (End)\n2.Delete by Value\n3.Delete by Position\n4.Display\n5.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> value;
            insertEnd(value);
            break;

        case 2:
            cin >> value;
            deleteByValue(value);
            break;

        case 3:
            cin >> pos;
            deleteByPos(pos);
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
