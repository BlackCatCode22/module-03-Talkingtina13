#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Delete a node by value
    void deleteNode(int val) {
        Node* temp = head;

        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Node with value " << val << " not found." << std::endl;
            return;
        }

        if (temp == head && temp == tail) {
            head = tail = nullptr;
        } else if (temp == head) {
            head = head->next;
            head->prev = nullptr;
        } else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList list;

    // Insert nodes at the end
    list.insertAtEnd(22);
    list.insertAtEnd(55);
    list.insertAtEnd(7);
    list.insertAtEnd(18);

    // Display all nodes
    std::cout << "List after insertion: ";
    list.display();

    // Delete a node by value
    list.deleteNode(7);
    std::cout << "List after deletion: ";
    list.display();

    return 0;
}
