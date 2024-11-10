//Name : SWARNIM SURVASE , PRN : 123B1B275 , ASSIGNMENT NO 1A
//Consider a student database of SY COMP class (at least 15 records). Database contains different fields of every student like Roll No, Name and SGPA.
//a. Design a roll call list, arrange list of students according to roll numbers in ascending order using Insertion Sort

#include <iostream> 
using namespace std; 

// Student class definition
class Student{ 
public: 
    int roll_no;    // Roll number of the student
    string name;    // Name of the student
    float sgpa;     // SGPA of the student

    // Function to read student details
    void read(){ 
        cout << "Enter student roll number: " << endl; 
        cin >> roll_no; 
        cout << "Enter student name: " << endl; 
        cin >> name; 
        cout << "Enter student SGPA: " << endl; 
        cin >> sgpa; 
    } 

    // Function to display student details
    void display(){ 
        cout << "Roll Number: " << roll_no << endl; 
        cout << "Name: " << name << endl; 
        cout << "SGPA: " << sgpa << endl; 
    } 
}; 

// Function to perform insertion sort on the array of students based on roll number
void insertionsort(Student s[], int n){ 
    for(int i = 1; i < n; i++){ 
        Student x = s[i]; // Store the current student 
        int j = i - 1; 
        // Shift elements greater than current student's roll number to the right
        while(j >= 0 && s[j].roll_no > x.roll_no){ 
            s[j+1] = s[j]; 
            j--; 
        } 
        s[j+1] = x; // Place the current student in the correct position
    } 
} 

int main() { 
    Student s[10];  // Array to store student data
    int n;          // Number of students

    // Menu-driven system
    int choice; 
    do { 
        cout << "\nMenu: \n"; 
        cout << "1. Input Student Details\n"; 
        cout << "2. Sort Students by Roll Number\n"; 
        cout << "3. Display All Students\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 

        switch(choice){ 
            case 1: 
                cout << "Enter the number of students: " << endl; 
                cin >> n; 
                for(int i = 0; i < n; i++){ 
                    s[i].read();  // Input details for each student
                } 
                break; 

            case 2: 
                insertionsort(s, n);  // Sort students by roll number
                cout << "Students have been sorted by Roll Number.\n"; 
                break; 

            case 3: 
                for(int i = 0; i < n; i++){ 
                    s[i].display();  // Display details of all students
                } 
                break; 

            case 4: 
                cout << "Exiting the program.\n"; 
                break; 

            default: 
                cout << "Invalid choice! Please try again.\n"; 
        } 
    } while(choice != 4); 

    return 0; 
}
