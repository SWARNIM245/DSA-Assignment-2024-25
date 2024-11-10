//Name: SWARNIM SURVASE, PRN: 123B1B275 , ASSIGNMENT NO 1C
//c. Arrange list of students to find out first ten toppers from a class using Radix sort 

#include <iostream>
using namespace std;

// Class to represent a student with roll number, name, and SGPA
class student {
public:
    int rno;       // Roll number
    string name;   // Student name
    float sgpa;    // SGPA (Semester Grade Point Average)

    // Function to read student data from user input
    void read() {
        cout << "Enter roll no: ";
        cin >> rno;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter SGPA: ";
        cin >> sgpa;
    }

    // Function to display student data
    void display() {
        cout << "Roll no: " << rno << endl;
        cout << "Name: " << name << endl;
        cout << "SGPA: " << sgpa << endl;
    }
};

// Function to get the student with the maximum roll number
student getMax(student s[], int n) {
    student mx = s[0];  // Assume the first student has the largest roll number
    for (int i = 1; i < n; i++) {
        if (s[i].rno > mx.rno) {
            mx = s[i];
        }
    }
    return mx;
}

// Function to perform count sort based on digit at a specific place (exp)
void countsort(student s[], int n, int exp) {
    student output[n];   // Output array to store sorted students
    int count[10] = {0}; // Count array to store digit frequencies

    // Store the count of occurrences of each digit
    for (int i = 0; i < n; i++) {
        count[(s[i].rno / exp) % 10]++;
    }

    // Modify count array to store actual positions of digits in output
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array using the count array
    for (int i = n - 1; i >= 0; i--) {
        int index = (s[i].rno / exp) % 10;
        output[count[index] - 1] = s[i];
        count[index]--;
    }

    // Copy the sorted output array to the original array
    for (int i = 0; i < n; i++) {
        s[i] = output[i];
    }
}

// Function to perform radix sort on students based on roll numbers
void radixsort(student s[], int n) {
    student mx = getMax(s, n);  // Find the student with the maximum roll number
    int m = mx.rno;             // Get the maximum roll number

    // Perform count sort for each digit (ones, tens, hundreds, etc.)
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countsort(s, n, exp);
    }
}

int main() {
    int n, choice;
    student s[10];  // Array to store up to 10 students

    do {
        // Display menu options
        cout << "\nMenu:\n";
        cout << "1. Enter student data\n";
        cout << "2. Sort students by roll number (Radix Sort)\n";
        cout << "3. Display students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Read number of students and their details
                cout << "Enter number of students (max 10): ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    s[i].read();
                }
                break;

            case 2:
                // Sort students by roll number using radix sort
                radixsort(s, n);
                cout << "Students sorted by roll number.\n";
                break;

            case 3:
                // Display student details
                cout << "\nStudent details:\n";
                for (int i = 0; i < n; i++) {
                    s[i].display();
                }
                break;

            case 4:
                // Exit the program
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);  // Loop until the user chooses to exit

    return 0;
}
