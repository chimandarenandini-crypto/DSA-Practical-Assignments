#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class Stack {
    queue<int> q1, q2;
public:
    // Push an element into the stack
    void push(int value) {
        q2.push(value);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        cout << value << " pushed into stack." << endl;
    }

    // Remove the top element
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Popped element: " << q1.front() << endl;
        q1.pop();
    }

    // Show the top element
    void top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element: " << q1.front() << endl;
    }

    void display() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        queue<int> temp = q1;
        cout << "Stack elements (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;
    do {
        cout << "\nStack Using Two Queues" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.top();
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Program terminated." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
