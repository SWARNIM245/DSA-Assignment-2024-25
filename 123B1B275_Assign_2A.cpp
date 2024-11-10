//Name : SWARNIM SURVASE , PRN : 123B1B275 , ASSIGNMENT NO 2A 
//Consider Employee database of PCCOE (at least 20 records). Database contains different fields of every employee like EMP-ID, EMP-Name and EMP-Salary. 
//a. Arrange list of employees according to EMP-ID in ascending order using Quick Sort

#include<iostream> 
using namespace std; 

// Employee class definition
class employee { 
    string name;   // Employee's name
    int id;        // Employee's ID
    float salary;  // Employee's salary

public:
    // Function to read employee details from input
    void read() { 
        cout << "Name of employee: "; 
        cin >> name; 
        cout << "ID of employee: "; 
        cin >> id; 
        cout << "Salary of employee: "; 
        cin >> salary; 
    }

    // Function to display employee details
    void display() { 
        cout << "Name: " << name << endl; 
        cout << "ID: " << id << endl; 
        cout << "Salary: " << salary << endl; 
    }

    // Friend functions for merge and merge sort
    friend void merge(employee e[], int l, int mid, int r); 
    friend void mergesort(employee e[], int l, int r);
}; 

// Function to merge two halves of the employee array
void merge(employee e[], int l, int mid, int r) { 
    int n1 = mid - l + 1;  // Size of left half
    int n2 = r - mid;      // Size of right half

    // Temporary arrays to store the two halves
    employee a[n1]; 
    employee b[n2]; 

    // Copy data to temporary arrays a[] and b[]
    for (int i = 0; i < n1; i++) { 
        a[i] = e[l + i]; 
    } 
    for (int j = 0; j < n2; j++) { 
        b[j] = e[mid + 1 + j]; 
    } 

    int i = 0;  // Initial index of first half
    int j = 0;  // Initial index of second half
    int k = l;  // Initial index of merged array

    // Merge the two halves back into e[]
    while (i < n1 && j < n2) { 
        if (a[i].name < b[j].name) {  // Comparing based on employee name
            e[k++] = a[i++]; 
        } else { 
            e[k++] = b[j++]; 
        } 
    } 

    // Copy remaining elements of a[], if any
    while (i < n1) { 
        e[k++] = a[i++]; 
    } 

    // Copy remaining elements of b[], if any
    while (j < n2) { 
        e[k++] = b[j++]; 
    } 
}

// Function to implement merge sort on employee array
void mergesort(employee e[], int l, int r) { 
    if (l >= r) { 
        return;  // Base case: when only one element is left
    } 
    int mid = l + (r - l) / 2;  // Finding the middle of the array

    // Recursively sort the two halves
    mergesort(e, l, mid); 
    mergesort(e, mid + 1, r);

    // Merge the sorted halves
    merge(e, l, mid, r); 
}

int main() { 
    employee e[10];  // Array of employee objects
    int n = 0;       // Number of employees
    int choice;

    do {
        // Display menu
        cout << "\nMenu: \n";
        cout << "1. Add Employee(s)\n";
        cout << "2. Display Employees\n";
        cout << "3. Sort Employees by Name\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add multiple employees
                int m;
                cout << "How many employees do you want to add? ";
                cin >> m;
                if (n + m <= 10) {
                    for (int i = 0; i < m; i++) {
                        cout << "Enter details for employee " << (n + 1) << ":\n";
                        e[n].read();
                        n++;
                    }
                } else {
                    cout << "Not enough space to add " << m << " employees. Maximum is 10.\n";
                }
                break;
            }
            case 2: {
                // Display employees
                for (int i = 0; i < n; i++) {
                    e[i].display();
                    cout << endl;
                }
                break;
            }
            case 3: {
                // Sort employees by name
                mergesort(e, 0, n - 1);
                cout << "Employees sorted by name.\n";
                break;
            }
            case 4: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice! Please try again.\n";
            }
        }
    } while (choice != 4);  // Continue until user selects exit

    return 0; 
}
