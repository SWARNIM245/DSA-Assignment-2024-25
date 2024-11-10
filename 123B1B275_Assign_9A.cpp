//Name:SWARNIM SURVASE,PRN:123B1B275,ASSIGNMENT NO 9A
//a. Implement a restaurant waitlist system using the queue data structure. Restaurant waitlist provide following facility:
//a. Add Party to Waitlist
//b. Seat Party
//c. Display Waitlist

#include <iostream>
#include <string>
using namespace std;

#define SIZE 10 // Maximum size of the waitlist

// Class to represent a Party
class Party {
public:
    string name; // Party's name
    int size;    // Size of the party

    // Default constructor
    Party() {}

    // Parameterized constructor
    Party(string n, int s) {
        name = n;
        size = s;
    }
};

// Class to represent the Waitlist (Queue)
class Queue {
private:
    Party waitlist[SIZE]; // Array to hold the parties in the queue
    int front, rear;      // Front and rear pointers for the circular queue

public:
    // Constructor to initialize the front and rear of the queue
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % SIZE == front; // If rear is just behind front in circular arrangement, it's full
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1; // Queue is empty if front is -1
    }

    // Function to add a party to the waitlist
    void addParty(Party party) {
        if (isFull()) { // Check if the queue is full before adding
            cout << "Waitlist is full! Cannot add party: " << party.name << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0; // If adding the first party, set both front and rear to 0
        } else {
            rear = (rear + 1) % SIZE; // Circular increment of rear
        }
        waitlist[rear] = party; // Add the party to the queue
        cout << "Party " << party.name << " (Size: " << party.size << ") added to the waitlist." << endl;
    }

    // Function to seat a party from the waitlist (remove from the queue)
    Party seatParty() {
        if (isEmpty()) { // Check if the queue is empty before seating
            cout << "Waitlist is empty! No parties to seat." << endl;
            return Party(); // Return an empty party object
        }
        Party party = waitlist[front]; // Get the party at the front of the queue
        if (front == rear) { // If there's only one party in the queue
            front = rear = -1; // Reset the queue to empty
        } else {
            front = (front + 1) % SIZE; // Circular increment of front
        }
        cout << "Party " << party.name << " has been seated." << endl;
        return party; // Return the seated party
    }

    // Function to display the current waitlist
    void displayWaitlist() {
        if (isEmpty()) { // Check if the queue is empty before displaying
            cout << "No parties in the waitlist." << endl;
            return;
        }
        cout << "Current waitlist: " << endl;
        int i = front; // Start from the front
        while (true) {
            // Print the details of each party in the queue
            cout << "Party Name: " << waitlist[i].name << ", Size: " << waitlist[i].size << endl;
            if (i == rear) break; // Stop when we reach the rear
            i = (i + 1) % SIZE; // Circular increment of i
        }
    }
};

int main() {
    Queue waitlist; // Create a Queue object to manage the waitlist
    int choice;     // Variable to store the user's menu choice
    string name;    // Variable to store the party name
    int size;       // Variable to store the party size

    
    do {
        // Display the menu
        cout << "\nRestaurant Waitlist System Menu:\n";
        cout << "1. Add Party to Waitlist\n";
        cout << "2. Seat Party\n";
        cout << "3. Display Waitlist\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; 
        cin.ignore();  

        switch (choice) {
            case 1:
                
                cout << "Enter party name: ";
                getline(cin, name); 
                cout << "Enter party size: ";
                cin >> size;        
                waitlist.addParty(Party(name, size)); 
                break;

            case 2:
                
                waitlist.seatParty();
                break;

            case 3:
                
                waitlist.displayWaitlist();
                break;

            case 4:
                
                cout << "Exiting the system." << endl;
                break;

            default:
                
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4); 

    return 0;
}
