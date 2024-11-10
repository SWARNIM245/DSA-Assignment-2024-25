//Name : SWARNIM SURVASE , PRN : 123B1B275 , ASSIGNMENT NO 2B
//b. Arrange list of Employee alphabetically using Merge Sort

#include<iostream>
using namespace std;

class Employee {
    int iEmployeeID;        
    string sName;       

public:
    // Default constructor
    Employee() {
        iEmployeeID = 0;
        sName = "";
    }

    // Parameterized constructor
    Employee(int id, string name) {
        iEmployeeID = id;
        sName = name;
    }

    // Setter for Employee ID
    void setEmployeeID(int empid) {
        iEmployeeID = empid;
    }

    // Setter for Employee Name
    void setName(string name) {
        sName = name;
    }

    // Getter for Employee ID
    int getEmployeeID() {
        return iEmployeeID;
    }

    // Getter for Employee Name
    string getName() {
        return sName;
    }
};

// Partition function used by QuickSort algorithm
int partition(Employee arr[], int left, int right) {
    int i = left;                                      // Left index
    int j = right;                                     // Right index
    int pivot = arr[left].getEmployeeID();             // Pivot element (first element's ID)

    // Perform partitioning
    while (i < j) {
        while (arr[i].getEmployeeID() <= pivot && i < right) {
            i++;
        }

        while (arr[j].getEmployeeID() > pivot) {
            j--;
        }

        if (i < j) {
            Employee temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    Employee temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;

    return j;  // Return the pivot index
}

// QuickSort algorithm to sort the Employee array based on employee ID
void qs(Employee arr[], int left, int right) {
    if (left < right) {
        int pivotP = partition(arr, left, right);    // Get pivot index after partitioning
        qs(arr, left, pivotP - 1);                   // Recursively sort left side
        qs(arr, pivotP + 1, right);                  // Recursively sort right side
    }
}

// Function to display employee details
void displayEmployees(Employee arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << "Employee ID: " << arr[i].getEmployeeID() 
             << ", Name: " << arr[i].getName() << endl;
    }
}

int main() {
    const int MAX_EMPLOYEES = 100;
    Employee arr[MAX_EMPLOYEES];  // Array to hold employees
    int len = 0;                  // Number of employees

    int choice;
    do {
        cout << "\n--- Employee Management Menu ---\n";
        cout << "1. Add Employees\n";
        cout << "2. Display Employees\n";
        cout << "3. Sort Employees by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int numEmployees;
                cout << "Enter the number of employees to add: ";
                cin >> numEmployees;

                for (int i = 0; i < numEmployees; i++) {
                    if (len >= MAX_EMPLOYEES) {
                        cout << "Maximum number of employees reached.\n";
                        break;
                    }

                    int id;
                    string name;
                    cout << "Enter Employee ID: ";
                    cin >> id;
                    cout << "Enter Employee Name: ";
                    cin.ignore();   // To clear the newline character from the input buffer
                    getline(cin, name);

                    arr[len] = Employee(id, name);  // Add new employee to the array
                    len++;
                    cout << "Employee added successfully!\n";
                }
                break;
            }

            case 2: {
                if (len > 0) {
                    displayEmployees(arr, len);
                } else {
                    cout << "No employees to display.\n";
                }
                break;
            }

            case 3: {
                if (len > 0) {
                    qs(arr, 0, len - 1);
                    cout << "Employees sorted by ID.\n";
                } else {
                    cout << "No employees to sort.\n";
                }
                break;
            }

            case 4: {
                cout << "Exiting the program...\n";
                break;
            }

            default: {
                cout << "Invalid choice! Please try again.\n";
                break;
            }
        }
    } while (choice != 4);

    return 0;
}
