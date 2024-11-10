//Name: SWARNIM SURVASE, PRN:123B1B275, ASSIGNMENT NO 11
//Consider an employee database of N employees. Make use of a hash table implementation to quickly look up the employer's id number.

#include <iostream>
using namespace std;
#define SIZE 10 

// Employee class
class emp {
public:
    int id;        
    string name;   
    int flag;      // Flag indicating if the position in the hash table is occupied (1) or not (0)

    // Default constructor initializing variables
    emp() {
        id = 0;    // Set ID to 0 as default
        flag = 0;  // Set flag to 0, meaning unoccupied by default
        name = ""; 
    }

    // Function to read employee data
    void read() {
        cout << "Enter employee ID: ";
        cin >> id;                    
        cout << "Enter employee name: ";
        cin >> name;                   
        flag = 1;                      // Mark the entry as occupied by setting flag to 1
    }

    // Function to display employee data
    void display() {
        cout << "Employee Name: " << name << endl; 
        cout << "Employee ID: " << id << endl;     
    }
};

// Employee management class using a hash table
class empM {
public:
    emp HT[SIZE]; // Hash table array of Employee objects, with fixed size SIZE

    // Hash function to calculate index based on employee ID
    int hashFunction(int id) {
        return id % SIZE; // Use modulo operation to ensure index is within hash table size
    }

    // Function to insert an employee
    void insert() {
        emp newEmp;               // Create a new employee object
        newEmp.read();            // Get employee data from user
        int index = hashFunction(newEmp.id); // Calculate the index using the hash function
        int originalIndex = index;           // Save original index for collision handling

        // Linear probing to handle collisions
        while (HT[index].flag == 1) {        // If position is occupied, look for the next position
            index = (index + 1) % SIZE;      // Move to the next index (wrap around if needed)
            if (index == originalIndex) {    // If we've looped back to the start, table is full
                cout << "Hash table is full. Cannot insert employee." << endl;
                return;
            }
        }

        HT[index] = newEmp;                 // Insert new employee at the calculated position
        cout << "Employee inserted successfully!" << endl;
    }

    // Function to search for an employee by ID
    emp search(int id) {
        int index = hashFunction(id);       // Calculate the starting index using the hash function
        int originalIndex = index;          // Save original index for collision handling

        // Linear probing to find the employee
        while (HT[index].flag == 1) {       // Continue if position is occupied
            if (HT[index].id == id) {       // Check if the ID matches
                return HT[index];           // If found, return the employee
            }
            index = (index + 1) % SIZE;     // Move to the next index (wrap around if needed)
            if (index == originalIndex) {   // If we've looped back to the start, employee not found
                break;
            }
        }
        return emp(); 
    }
};

int main() {
    empM m1; 
    int choice; 
    int searchId; 
    emp foundEmp; 

    
    do {
        cout << "\nEmployee Management System\n";
        cout << "1. Insert a new employee\n";
        cout << "2. Search for an employee by ID\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
               
                m1.insert();
                break;
            case 2:
                
                cout << "Enter employee ID to search: ";
                cin >> searchId;

                foundEmp = m1.search(searchId); 
                if (foundEmp.flag == 1) {       
                    cout << "Employee found:\n";
                    foundEmp.display();
                } else {
                    cout << "Employee not found." << endl; 
                }
                break;
            case 0:
            
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl; // Handle invalid input
                break;
        }
    } while (choice != 0);

    return 0;
}
