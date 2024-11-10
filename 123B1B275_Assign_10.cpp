//Name:SWARNIM SURVASE, PRN:123B1B275, ASSIGNMENT NO 10
//Implement a job scheduling system for a manufacturing plant using a double-ended queue. The system needs to efficiently manage the processing of jobs on various machines 
//throughout the plant. Each job has a Job_priority. The system should support the following operations: a. Add Job b. Remove Job c. Display Job d. Search Job 

#include <iostream>
#define MAX 5
using namespace std;

class DeQueue {
    int arr[MAX];      // Array to store jobs
    int front, rear;   // Pointers to track the front and rear of the deque

public:
    DeQueue() {
        // Constructor initializes front and rear pointers to -1 indicating an empty deque
        front = rear = -1;
    }

    bool isEmpty() {
        // Check if deque is empty
        return (front == -1);
    }

    bool isFull() {
        // Check if deque is full
        return (front == (rear + 1) % MAX);
    }

    void insertAtRear(int val) {
        // Insert job at the rear
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % MAX;   // Increment rear circularly
        arr[rear] = val;           // Add job at rear
        if (front == -1) {
            front = 0;             // If inserting the first element, set front to 0
        }
    }

    void insertAtFront(int val) {
        // Insert job at the front
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) {
            // If inserting the first element
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;  // Wrap around if front is at 0
        } else {
            front = front - 1; // Move front back by one
        }
        arr[front] = val;  // Place the job at the new front
    }

    int deleteFromRear() {
        // Remove job from the rear
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int returnValue = arr[rear]; // Store the job to return
        if (rear == front) {
            // Reset deque if it was the last element
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1; // Wrap around if rear is at 0
        } else {
            rear = rear - 1; // Move rear back by one
        }
        return returnValue; // Return the removed job
    }

    int deleteFromFront() {
        // Remove job from the front
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int returnValue = arr[front]; // Store the job to return
        if (rear == front) {
            // Reset deque if it was the last element
            front = rear = -1;
        } else {
            front = (front + 1) % MAX; // Increment front circularly
        }
        return returnValue; // Return the removed job
    }

    void display() {
        // Display all jobs in the deque
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Jobs in the Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;       // Stop once we've displayed up to the rear
            i = (i + 1) % MAX;          // Move to the next element circularly
        }
        cout << endl;
    }

    int searchJob(int job) {
        // Search for a specific job in the deque
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int i = front;
        int pos = 1;  // Position starts from 1
        while (true) {
            if (arr[i] == job) {         // If job found
                cout << "Job found at position: " << pos << endl;
                return pos;
            }
            if (i == rear) break;        // Stop search at the rear
            i = (i + 1) % MAX;           // Move to the next element circularly
            pos++;
        }
        cout << "Job not found\n";       // Job was not found in the deque
        return -1;
    }
};

int main() {
    DeQueue dq;
    int choice, job;

    //Display the menu options
    do {
        cout << "\nJob Scheduling System Menu\n";
        cout << "1. Add Job at Rear\n";
        cout << "2. Add Job at Front\n";
        cout << "3. Remove Job from Rear\n";
        cout << "4. Remove Job from Front\n";
        cout << "5. Display All Jobs\n";
        cout << "6. Search for a Job\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                
                cout << "Enter job priority to add at rear: ";
                cin >> job;
                dq.insertAtRear(job);
                break;

            case 2:
                
                cout << "Enter job priority to add at front: ";
                cin >> job;
                dq.insertAtFront(job);
                break;

            case 3:
                
                job = dq.deleteFromRear();
                if (job != -1) cout << "Removed job with priority " << job << " from rear.\n";
                break;

            case 4:
                
                job = dq.deleteFromFront();
                if (job != -1) cout << "Removed job with priority " << job << " from front.\n";
                break;

            case 5:
               
                dq.display();
                break;

            case 6:
                
                cout << "Enter job priority to search: ";
                cin >> job;
                dq.searchJob(job);
                break;

            case 7:

                cout << "Exiting Job Scheduling System.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7); 

    return 0;
}
