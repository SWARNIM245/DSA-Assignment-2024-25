//Name: SWARNIM SURVASE, PRN:123B1B275 , ASSIGNMENT NO 1B
//b. Arrange list of students alphabetically using shell sort

#include <iostream>
using namespace std;

class Student {
public:
    int roll_no;
    string name;
    float sgpa;

    // Function to read student details
    void read() {
        cout << "Enter student roll_no: " << endl;
        cin >> roll_no;
        cout << "Enter student name: " << endl;
        cin >> name;
        cout << "Enter student sgpa: " << endl;
        cin >> sgpa;
    }

    // Function to display student details
    void display() {
        cout << "Roll_no: " << roll_no << endl;
        cout << "Name: " << name << endl;
        cout << "SGPA: " << sgpa << endl;
    }
};

// Function to sort the students based on roll number using Shell Sort
void shellsort(Student s[], int n) {
    int interval = n / 2;
    while (interval >= 1) {
        for (int i = interval; i < n; i++) {
            Student temp = s[i];
            int j = i - interval;
            for (; j >= 0; j = j - interval) {
                if (s[j].roll_no > temp.roll_no)
                    s[j + interval] = s[j];
                else
                    break;
            }
            s[j + interval] = temp;
        }
        interval /= 2;
    }
}

int main() {
    Student s[10];  // Array to hold student records
    int n, choice;
    
    // Menu-driven system
    do {
        cout << "\nMenu: \n";
        cout << "1. Add student details\n";
        cout << "2. Sort students by roll number\n";
        cout << "3. Display student details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                // Input number of students and their details
                cout << "Enter number of students: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    s[i].read();
                }
                break;
                
            case 2:
                // Sort students based on roll number
                shellsort(s, n);
                cout << "Students sorted by roll number.\n";
                break;
                
            case 3:
                // Display student details
                for (int i = 0; i < n; i++) {
                    s[i].display();
                }
                break;
                
            case 4:
                // Exit the menu
                cout << "Exiting...\n";
                break;
                
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);  // Continue until the user chooses to exit

    return 0;
}
 