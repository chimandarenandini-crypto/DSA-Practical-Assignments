#include <iostream> 
using namespace std; 
 
int main() 
{ 
    int seats[10] = {0};   // 0 = Available, 1 = Booked 
    int choice, seatNumber; 
 
    do 
    { 
        cout << "\n--- Movie Ticket Booking System ---"; 
        cout << "\n1. Display Seats"; 
        cout << "\n2. Book Ticket"; 
        cout << "\n3. Cancel Ticket"; 
        cout << "\n4. Exit"; 
        cout << "\nEnter your choice: "; 
        cin >> choice; 
 
        switch (choice) 
        { 
            case 1: 
                cout << "\nSeat Status:\n"; 
 
                for (int i = 0; i < 10; i++) 
                { 
                    cout << "Seat " << i + 1 << ": "; 
 
                    if (seats[i] == 0) 
                        cout << "Available\n"; 
                    else 
                        cout << "Booked\n"; 
                } 
                break; 
 
            case 2: 
                cout << "Enter seat number (1-10): "; 
                cin >> seatNumber; 
 
                if (seatNumber < 1 || seatNumber > 10) 
                { 
                    cout << "Invalid seat number!"; 
                } 
                else if (seats[seatNumber - 1] == 1) 
                { 
                    cout << "Seat is already booked!"; 
                } 
                else 
                { 
                    seats[seatNumber - 1] = 1; 
                    cout << "Ticket booked successfully!"; 
                } 
                break; 
 
            case 3: 
                cout << "Enter seat number to cancel: "; 
                cin >> seatNumber; 
 
                if (seatNumber < 1 || seatNumber > 10) 
                { 
                    cout << "Invalid seat number!"; 
                } 
                else if (seats[seatNumber - 1] == 0) 
                { 
                    cout << "Seat is already available!"; 
                } 
                else 
                { 
                    seats[seatNumber - 1] = 0; 
                    cout << "Ticket cancelled successfully!"; 
                } 
                break; 
 
            case 4: 
                cout << "Thank you!"; 
                break; 
 
            default: 
                cout << "Invalid choice!"; 
        } 
 
    } while (choice != 4); 
 
    return 0; 
}
