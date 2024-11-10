//Name : SWARNIM SURVASE , PRN : 123B1B275 , ASSIGNMENT NO 7
//Implement a browser history management system using a stack data structure to track the user's browsing history. The system should support the //following functionalities: a. Add visited page b. Navigate back c. View current page d. Check if history is empty or not Assume no upper bound //on number of pages visited.

#include <iostream>
#include <string>

using namespace std;  

// Node class to represent each page in the history
class Node {
public:
    string page;  // URL of the page
    Node* next;   // Pointer to the next node

    // Constructor for Node
    Node(string p) : page(p), next(nullptr) {}  // Initialize page and set next to nullptr
};

// Class to manage browser history using a stack
class BrowserHistory {
private:
    Node* top;  // Pointer to the top of the stack (most recent page)

public:
    // Constructor for BrowserHistory
    BrowserHistory() : top(nullptr) {}  // Initialize the stack to be empty

    // Destructor to clean up memory
    ~BrowserHistory() {
        // Navigate back to remove all nodes from the stack
        while (!isEmpty()) {
            navigateBack();
        }
    }

    // Add a visited page to the history
    void addPage(string page) {  // Parameter can be modified
        Node* newNode = new Node(page);  // Create a new node with the given page
        newNode->next = top;              // Link new node to the previous top
        top = newNode;                    // Update top to the new node
        cout << "Visited: " << page << endl;  // Display visited page
    }

    // Navigate back to the previous page
    void navigateBack() {
        // Check if history is empty
        if (isEmpty()) {
            cout << "No history available." << endl;  // Notify the user
            return;
        }
        Node* temp = top;      // Store the current top node
        top = top->next;       // Move top to the next node
        cout << "Navigated back to: " << temp->page << endl;  // Display the navigated page
        delete temp;          // Free memory of the previous top node
    }

    // View the current page
    void viewCurrentPage() {
        // Check if history is empty
        if (isEmpty()) {
            cout << "No pages visited yet." << endl;  // Notify the user
        } else {
            cout << "Current page: " << top->page << endl;  // Display the current page
        }
    }

    // Check if history is empty
    bool isEmpty() {
        return top == nullptr;  // Return true if top is nullptr, indicating the stack is empty
    }
};

// Main function to run the browser history management system
int main() {
    BrowserHistory history;  
    int choice;             
    string url;             

    do {
        // Display the menu options
        cout << "\nBrowser History Menu:\n";
        cout << "1. Add Visited Page\n";
        cout << "2. Navigate Back\n";
        cout << "3. View Current Page\n";
        cout << "4. Check if History is Empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;  // Get user choice

        
        switch (choice) {
            case 1:
                cout << "Enter the URL of the page: ";
                cin >> url;  
                history.addPage(url); 
                break;
            case 2:
                history.navigateBack();  
                break;
            case 3:
                history.viewCurrentPage();  
                break;
            case 4:
                // Check if history is empty
                if (history.isEmpty()) {
                    cout << "History is empty." << endl; 
                } else {
                    cout << "History is not empty." << endl;  
                }
                break;
            case 5:
                cout << "Exiting...\n";  
                break;
            default:
                cout << "Invalid choice. Please try again.\n";  
                break;
        }
    } while (choice != 5);  

    return 0;  
}
