//Name:SWARNIM SURVASE , PRN:123B1B275 , ASSIGNMENT NO 9B
//b] Implement a checkout system for a supermarket to efficiently manage customer queues during peak hours. The system should support the following operations using a circular queue datastructure:
//a. Customer arrival
//b. Customer checkout
//c. Close Checkout Counter
//d. View customer 

#include <iostream>
using namespace std;

#define SIZE 5 // Define the size of the circular queue

// Class representing a Customer with a name attribute
class Customer {
public:
    string name;
    Customer() {} // Default constructor
    Customer(string n) { // Parameterized constructor
        name = n;
    }
};

// Class representing the Circular Queue
class CircularQueue {
private:
    Customer queue[SIZE]; // Array to store customers in the queue
    int front, rear; // Variables to track the front and rear of the queue
    
public:
    // Constructor initializes front and rear to -1, indicating an empty queue
    CircularQueue() {
        front = rear = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % SIZE == front; // If true, the queue is full
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1; // Queue is empty when front is -1
    }

    // Function to add a customer to the queue
    void enqueue(Customer customer) {
        if (isFull()) { // Check if the queue is full
            cout << "Queue is full! Cannot add customer: " << customer.name << endl;
            return;
        }
        if (isEmpty()) { // If the queue is empty, initialize front and rear
            front = rear = 0;
        } else {
            // Move rear to the next position, wrapping around if necessary
            rear = (rear + 1) % SIZE;
        }
        queue[rear] = customer; // Add the customer to the queue
        cout << "Customer " << customer.name << " added to the queue." << endl;
    }

    // Function to remove a customer from the queue
    Customer dequeue() {
        if (isEmpty()) { // Check if the queue is empty
            cout << "Queue is empty! No customers to checkout." << endl;
            return Customer(); // Return an empty customer object
        }
        Customer customer = queue[front]; // Get the customer at the front
        if (front == rear) { // If only one customer in the queue, reset it
            front = rear = -1;
        } else {
            // Move front to the next position, wrapping around if necessary
            front = (front + 1) % SIZE;
        }
        cout << "Customer " << customer.name << " has checked out." << endl;
        return customer;
    }

    // Function to close the checkout, resetting the queue
    void closeCheckout() {
        front = rear = -1; // Reset front and rear
        cout << "Checkout counter closed." << endl;
    }

    // Function to view the current customer at the front of the queue
    void viewCustomers() {
        if (isEmpty()) { // Check if the queue is empty
            cout << "No customers in the queue." << endl;
            return;
        }
        // Display the current customer at the front
        cout << "Current customer at the front of the queue: " << peek().name << endl;
        cout << endl;
    }

    // Function to get the customer at the front of the queue without removing them
    Customer peek() {
        if (isEmpty()) { // Check if the queue is empty
            cout << "Queue is empty! No customers at the front." << endl;
            return Customer(); // Return an empty customer object
        }
        return queue[front]; // Return the customer at the front
    }
};


int main() {
    CircularQueue queue; // Create a circular queue
    int choice; // Variable to store user choice
    string name; // Variable to store customer names

    // Display the menu options
    cout << "\nCheckout System Menu:\n";
    cout << "1. Customer Arrival\n";
    cout << "2. Customer Checkout\n";
    cout << "3. Close Checkout Counter\n";
    cout << "4. View Customers\n";
    cout << "5. Exit\n";
    
    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: 
                cout << "Enter customer name: ";
                cin >> ws; 
                cin >> name;
                queue.enqueue(Customer(name)); 
                break;
            case 2: 
                queue.dequeue(); 
                break;
            case 3: 
                queue.closeCheckout(); 
                break;
            case 4: 
                queue.viewCustomers();
                break;
            case 5: 
                cout << "Exiting the system." << endl;
                break;
            default: 
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);
    
    return 0;
}
