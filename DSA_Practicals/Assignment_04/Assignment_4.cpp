
#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node
{
    string name;
    int age;
    int seatNo;
    string destination;
    Node* prev;
    Node* next;
};

// Add passenger
void addPassenger(Node*& head)
{
    Node* newNode = new Node;

    cout << "Enter passenger name: ";
    cin >> newNode->name;

    cout << "Enter age: ";
    cin >> newNode->age;

    cout << "Enter seat number: ";
    cin >> newNode->seatNo;

    cout << "Enter destination: ";
    cin >> newNode->destination;

    newNode->prev = NULL;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        // Go to last node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    cout << "Passenger added successfully!\n";
}

// Display passengers
void displayPassengers(Node* head)
{
    if (head == NULL)
    {
        cout << "No passengers found.\n";
        return;
    }

    Node* temp = head;

    cout << "\n===== TRAIN RESERVATION =====\n";

    while (temp != NULL)
    {
        cout << "Name: " << temp->name << endl;
        cout << "Age: " << temp->age << endl;
        cout << "Seat Number: " << temp->seatNo << endl;
        cout << "Destination: " << temp->destination << endl;
        cout << "-----------------------------\n";

        temp = temp->next;
    }
}

// Search passenger
void searchPassenger(Node* head)
{
    int seat;

    cout << "Enter seat number to search: ";
    cin >> seat;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->seatNo == seat)
        {
            cout << "\nPassenger Found!\n";
            cout << "Name: " << temp->name << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Seat Number: " << temp->seatNo << endl;
            cout << "Destination: " << temp->destination << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "Passenger not found.\n";
}

// Delete passenger
void deletePassenger(Node*& head)
{
    int seat;

    cout << "Enter seat number to cancel: ";
    cin >> seat;

    if (head == NULL)
    {
        cout << "No passengers found.\n";
        return;
    }

    Node* temp = head;

    // Search for passenger
    while (temp != NULL && temp->seatNo != seat)
    {
        temp = temp->next;
    }

    // Passenger not found
    if (temp == NULL)
    {
        cout << "Passenger not found.\n";
        return;
    }

    // If deleting first node
    if (temp == head)
    {
        head = temp->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }
    }
    else
    {
        temp->prev->next = temp->next;

        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
    }

    delete temp;

    cout << "Reservation cancelled successfully!\n";
}

// Main function
int main()
{
    Node* head = NULL;
    int choice;

    do
    {
        cout << "\n===== TRAIN RESERVATION SYSTEM =====\n";
        cout << "1. Add Passenger\n";
        cout << "2. Display Passengers\n";
        cout << "3. Search Passenger\n";
        cout << "4. Cancel Reservation\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addPassenger(head);
                break;

            case 2:
                displayPassengers(head);
                break;

            case 3:
                searchPassenger(head);
                break;

            case 4:
                deletePassenger(head);
                break;

            case 5:
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}

