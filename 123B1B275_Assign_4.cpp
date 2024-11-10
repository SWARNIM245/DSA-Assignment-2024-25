//Name:-SWARNIM SURVASE , PRN:123B1B275 , Batch:- D-3, Assignment no 4
//Implement a simple text editor application using a doubly linked list to manage the text buffer. Text editor should support the following functionalities: 
//a. Insert text
//b. Delete text
//c. Display text
//d. Search text
//e. Print text in reverse

#include<iostream>
using namespace std;

class text {
public:
    string s;     // Holds the text
    text* next;   // Pointer to the next text node
    text* prev;   // Pointer to the previous text node

    // Constructor to initialize pointers
    text() {
        next = NULL;
        prev = NULL;
    }

    // Function to read the text input from user
    void read() {
        cout << "Enter text: ";
        cin >> s;
    }

    // Function to display the text
    void display() {
        cout << s;
    }
};

class TextEditor {

public:
    text* head;  // Pointer to the first node (beginning of the text)
    text* tail;  // Pointer to the last node (end of the text)

    // Constructor to initialize the head and tail
    TextEditor() {
        head = NULL;
        tail = NULL;
    }

    // Function to insert text at the beginning
    void insertAtBeg() {
        text* nn = new text;
        nn->read();

        if (head == NULL) {  // If the list is empty
            head = nn;
            tail = nn;
        } else {             // Insert at the beginning
            nn->next = head;
            head->prev = nn;
            head = nn;
        }
    }

    // Function to insert text at the end
    void insert_end() {
        text* nn = new text;
        nn->read();

        if (head == NULL) {  // If the list is empty
            head = nn;
            tail = nn;
        } else {             // Insert at the end
            tail->next = nn;
            nn->prev = tail;
            tail = nn;
        }
    }

    // Function to display text in forward direction
    void displayF() {
        cout << "Display in forward:" << endl;
        text* cn;
        for (cn = head; cn != NULL; cn = cn->next) {
            cn->display();
            cout << " ";
        }
        cout << endl;
    }

    // Function to delete text from the beginning
    void delete_beg() {
        if (head == NULL) {  // If the list is empty
            cout << "List is empty" << endl;
            return;
        }

        text* temp = head;

        if (head->next == NULL) {  // If there's only one element
            head = NULL;
            tail = NULL;
        } else {                   // Remove from the beginning
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }

    // Function to display text in reverse order
    void reverse() {
        if (head == NULL) {  // If the list is empty
            cout << "List is empty" << endl;
            return;
        }

        cout << "Display in reverse:" << endl;
        text* cn = tail;
        while (cn != NULL) {
            cn->display();
            cout << " ";
            cn = cn->prev;
        }
        cout << endl;
    }

    // Function to delete text at a specific position
    void deletePos() {
        if (head == NULL) {  // If the list is empty
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        int pos;
        cout << "Enter Position: ";
        cin >> pos;

        text* temp = head;
        int currentPos = 1;

        // Traverse to the position
        while (temp != NULL && currentPos < pos) {
            temp = temp->next;
            currentPos++;
        }

        if (temp == NULL) {  // If the position is out of range
            cout << "Position out of range" << endl;
            return;
        }

        // Adjust pointers to delete the node
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }

        delete temp;
    }

    // Function to search for a specific text
    void search() {
        string key;
        cout << "Enter text to be searched: ";
        cin >> key;

        text* cn = head;
        int position = 1;

        // Traverse the list to search for the key
        while (cn != NULL) {
            if (cn->s == key) {
                cout << "The text is found at position " << position << endl;
                return;
            }
            cn = cn->next;
            position++;
        }

        cout << "Text not found" << endl;
    }
};

// Main function to drive the text editor functionality
int main() {
    TextEditor t;
    int c;

    // Menu-driven interface
    cout << "Enter 1 for insert at beginning\n"
         << "Enter 2 for inserting at end\n"
         << "Enter 3 for deleting from beginning\n"
         << "Enter 4 for deleting at any position\n"
         << "Enter 5 for forward printing\n"
         << "Enter 6 for reverse printing\n"
         << "Enter 7 to search\n"
         << "Enter 8 to exit\n";

    do {
        cout << "Enter choice: ";
        cin >> c;

        switch (c) {
            case 1:
                t.insertAtBeg();
                break;
            case 2:
                t.insert_end();
                break;
            case 3:
                t.delete_beg();
                break;
            case 4:
                t.deletePos();
                break;
            case 5:
                t.displayF();
                break;
            case 6:
                t.reverse();
                break;
            case 7:
                t.search();
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please enter again." << endl;
        }
    } while (c != 8);

    return 0;
}
