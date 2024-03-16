#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(int value) {
    Node* temp = head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->data == value) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        return;
    }

    prev->next = temp->next;
    delete temp;
}

void displayList() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    insertNode(20);
    insertNode(55);
    insertNode(7);
    insertNode(18);

    std::cout << "Initial List: ";
    displayList();

    deleteNode(7);

    std::cout << "List after deleting node with value 7: ";
    displayList();

    return 0;
}
