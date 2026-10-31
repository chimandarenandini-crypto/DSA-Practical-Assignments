#include <iostream> 
using namespace std; 
 
int main() { 
    int size; 
 
    cout << "Enter hash table size: "; 
    cin >> size; 
 
    int hashTable[size]; 
 
    // Initialize hash table with -1 
    for (int i = 0; i < size; i++) { 
        hashTable[i] = -1; 
    } 
 
    int n; 
    cout << "Enter number of students: "; 
    cin >> n; 
 
    // Insert student IDs 
    for (int i = 0; i < n; i++) { 
        int studentID; 
 
        cout << "Enter Student ID: "; 
        cin >> studentID; 
 
        // Hash function 
        int index = studentID % size; 
 
        // Linear Probing 
        while (hashTable[index] != -1) { 
            cout << "Collision occurred at index " << index << endl; 
 
            index = (index + 1) % size; 
        } 
 
        hashTable[index] = studentID; 
 
        cout << "Student ID " << studentID 
             << " stored at index " << index << endl; 
    } 
 
    // Display hash table 
    cout << "\nHash Table:\n"; 
 
    for (int i = 0; i < size; i++) { 
        if (hashTable[i] == -1) { 
            cout << "Index " << i << ": Empty" << endl; 
        } 
        else { 
            cout << "Index " << i << ": " 
                 << hashTable[i] << endl; 
        } 
    } 
return 0; 
}
