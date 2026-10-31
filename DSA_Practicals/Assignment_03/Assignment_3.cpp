#include <iostream> 
#include <string> 
using namespace std; 
 
struct Friend 
{ 
    string name; 
    string mobile; 
}; 
 
// Sort friends according to name 
void sortFriends(Friend f[], int n) 
{ 
    for (int i = 0; i < n - 1; i++) 
    { 
        for (int j = 0; j < n - i - 1; j++) 
        { 
            if (f[j].name > f[j + 1].name) 
            { 
                Friend temp = f[j]; 
                f[j] = f[j + 1]; 
                f[j + 1] = temp; 
            } 
        } 
    } 
} 
 
// Sentinel Search 
int sentinelSearch(Friend f[], int n, string key) 
{ 
    Friend last = f[n]; 
 
    f[n].name = key; 
 
    int i = 0; 
 
    while (f[i].name != key) 
    { 
        i++; 
    } 
 
    f[n] = last; 
 
    if (i < n) 
        return i; 
    else 
        return -1; 
} 
 
// Insert friend 
void insertFriend(Friend f[], int &n, string name, string mobile) 
{ 
    int i = n - 1; 
 
    while (i >= 0 && f[i].name > name) 
    { 
        f[i + 1] = f[i]; 
        i--; 
    } 
 
    f[i + 1].name = name; 
    f[i + 1].mobile = mobile; 
 
    n++; 
} 
 
// Display phone book 
void display(Friend f[], int n) 
{ 
    cout << "\nPhone Book:\n"; 
 
    for (int i = 0; i < n; i++) 
    { 
        cout << f[i].name << " - " << f[i].mobile << endl; 
    } 
} 
 
int main() 
{ 
    Friend f[100]; 
    int n; 
 
    cout << "Enter number of friends: "; 
    cin >> n; 
 
    for (int i = 0; i < n; i++) 
    { 
        cout << "\nEnter name: "; 
        cin >> f[i].name; 
 
        cout << "Enter mobile number: "; 
        cin >> f[i].mobile; 
    } 
 
    // Sort names 
    sortFriends(f, n); 
 
    cout << "\nAfter Sorting:"; 
    display(f, n); 
 
    // Search friend 
    string key; 
    cout << "\nEnter friend name to search: "; 
    cin >> key; 
 
    int pos = sentinelSearch(f, n, key); 
 
    if (pos != -1) 
    { 
        cout << "\nFriend found!"; 
        cout << "\nName: " << f[pos].name; 
        cout << "\nMobile: " << f[pos].mobile << endl; 
    } 
    else 
    { 
        cout << "\nFriend not found."; 
 
        string mobile; 
        cout << "\nEnter mobile number to insert: "; 
        cin >> mobile; 
 
        insertFriend(f, n, key, mobile); 
 
cout << "\nFriend inserted successfully."; 
display(f, n); 
} 
return 0; 
}
