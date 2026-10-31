#include <iostream> 
using namespace std; 
 
struct Node { 
    int data; 
    Node* next; 
}; 
 
class Queue { 
private: 
    Node* front; 
    Node* rear; 
 
public: 
    // Constructor 
    Queue() { 
        front = NULL; 
        rear = NULL; 
    } 
 
    // Insert element into queue 
    void enqueue(int value) { 
        Node* newNode = new Node; 
        newNode->data = value; 
        newNode->next = NULL; 
 
        if (rear == NULL) { 
            front = rear = newNode; 
        } else { 
            rear->next = newNode; 
            rear = newNode; 
        } 
 
        cout << value << " inserted into queue." << endl; 
    } 
 
    // Delete element from queue 
    void dequeue() { 
        if (front == NULL) { 
            cout << "Queue is empty!" << endl; 
            return; 
        } 
 
        Node* temp = front; 
        cout << "Deleted element: " << front->data << endl; 
 
        front = front->next; 
 
        if (front == NULL) { 
            rear = NULL; 
        } 
 
        delete temp; 
    } 
 
    // Display front element 
    void peek() { 
        if (front == NULL) { 
            cout << "Queue is empty!" << endl; 
        } else { 
            cout << "Front element: " << front->data << endl; 
        } 
    } 
 
    // Display all queue elements 
    void display() { 
        if (front == NULL) { 
            cout << "Queue is empty!" << endl; 
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
 
    // Destructor 
    ~Queue() { 
        while (front != NULL) { 
            Node* temp = front; 
            front = front->next; 
            delete temp; 
        } 
 
        rear = NULL; 
    } 
}; 
 
int main() { 
    Queue q; 
    int choice, value; 
 
    do { 
        cout << "\n--- Queue Using Linked List ---" << endl; 
        cout << "1. Enqueue" << endl; 
        cout << "2. Dequeue" << endl; 
        cout << "3. Peek" << endl; 
        cout << "4. Display" << endl; 
        cout << "5. Exit" << endl; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: 
                cout << "Enter value: "; 
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
                cout << "Exiting program." << endl; 
                break; 
 
            default: 
                cout << "Invalid choice!" << endl; 
        } 
 
    } while (choice != 5); 
 
    return 0; 
} 
