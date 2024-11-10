//Name:-SWARNIM SURVASE , PRN:-123B1B275 , Batch:- D-3 ,Assignment No 5  
//Implement a navigation system for a delivery service using a circular linked list to represent routes. The navigation system should support the following functionalities: a. Add route b. Remove route c. Display route.

#include <iostream>
using namespace std;

// Class to represent a single Route
class Route {
public:
    string source;
    string destination;
    float distance;
    Route* next;

    // Constructor initializing the next pointer to NULL
    Route() {
        next = NULL;
    }

    // Function to read route data
    void read(string src, string dst, float dist) {
        source = src;
        destination = dst;
        distance = dist;
    }

    // Function to display route data
    void display() {
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Distance: " << distance << " km" << endl;
    }
};

// Class to manage Route Navigation as a circular linked list
class Route_Navigation {
    Route* tail;

public:
    // Constructor initializing tail to NULL
    Route_Navigation() {
        tail = NULL;
    }

    // Function to insert a new route at the end of the list
    void insertAtEnd(string src, string dst, float dist) {
        Route* cn = new Route;
        cn->read(src, dst, dist);
        if (tail == NULL) {
            tail = cn;
            cn->next = cn;
        } else {
            cn->next = tail->next;
            tail->next = cn;
            tail = cn;
        }
    }

    // Function to insert a new route at the head of the list
    void insertAtHead(string src, string dst, float dist) {
        Route* cn = new Route;
        cn->read(src, dst, dist);
        if (tail == NULL) {
            tail = cn;
            cn->next = cn;
        } else {
            cn->next = tail->next;
            tail->next = cn;
        }
    }

    // Function to print all routes in the list
    void printRecords() {
        if (!tail) return;
        Route* t = tail->next;
        do {
            t->display();
            t = t->next;
        } while (t != tail->next);
    }

    // Function to delete a specific route from the list
    void delRecords(string src, string dst) {
        if (!tail) return;
        Route* t = tail->next;
        Route* p = tail;
        do {
            if (t->source == src && t->destination == dst) {
                if (t != tail) {
                    p->next = t->next;
                    delete t;
                    return;
                } else if (tail == tail->next) { // Only one element
                    delete t;
                    tail = NULL;
                    return;
                } else { // Deleting the tail node
                    p->next = t->next;
                    tail = p;
                    delete t;
                    return;
                }
            }
            p = t;
            t = t->next;
        } while (t != tail->next);
    }

    // Function to check for duplicate routes
    void checkDuplicate() {
        if (!tail) return;
        Route* t = tail->next;
        do {
            Route* compare = t->next;
            while (compare != tail->next) {
                if (t->source == compare->source && t->destination == compare->destination) {
                    cout << "Duplicate - Source: " << t->source << ", Destination: " << t->destination << endl;
                }
                compare = compare->next;
            }
            t = t->next;
        } while (t != tail->next);
    }
};

// Function to display the menu and handle user input
int main(){
    Route_Navigation myRoute;
    int choice;
    string src, dst;
    float dist;

    do {
        cout << "\n--- Route Navigation Menu ---\n";
        cout << "1. Insert Route at End\n";
        cout << "2. Insert Route at Head\n";
        cout << "3. Display All Routes\n";
        cout << "4. Delete a Route\n";
        cout << "5. Check for Duplicates\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Source: ";
                cin >> src;
                cout << "Enter Destination: ";
                cin >> dst;
                cout << "Enter Distance: ";
                cin >> dist;
                myRoute.insertAtEnd(src, dst, dist);
                break;

            case 2:
                cout << "Enter Source: ";
                cin >> src;
                cout << "Enter Destination: ";
                cin >> dst;
                cout << "Enter Distance: ";
                cin >> dist;
                myRoute.insertAtHead(src, dst, dist);
                break;

            case 3:
                cout << "All Routes:\n";
                myRoute.printRecords();
                break;

            case 4:
                cout << "Enter Source to Delete: ";
                cin >> src;
                cout << "Enter Destination to Delete: ";
                cin >> dst;
                myRoute.delRecords(src, dst);
                cout << "Route deleted successfully.\n";
                break;

            case 5:
                cout << "Checking for duplicate routes...\n";
                myRoute.checkDuplicate();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);
    return 0;
}