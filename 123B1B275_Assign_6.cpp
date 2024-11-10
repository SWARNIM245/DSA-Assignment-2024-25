//Name: Swarnim Survase , PRN:123B1B275, Batch:-D-3, Assignment no 6 
//Consider two polynomial expressions of any degree. Design solution to perform addition of these two polynomials with suitable data structure and display results.

#include <iostream>
using namespace std;

// Node class representing a term of the polynomial
class Node {
    public:
    int coefficient;
    int exponent;
    Node* next;

    Node(int coeff, int exp) {
        coefficient = coeff;
        exponent = exp;
        next = nullptr;
    }
};

// Polynomial class using linked list
class Polynomial {
private:
    Node* head;  // Pointer to the head node of the polynomial linked list

public:
    // Constructor to initialize an empty polynomial
    Polynomial() {
        head = nullptr;
    }

    // Function to insert a term into the polynomial in descending order of exponents
    void insertTerm(int coeff, int exp) {
        Node* newNode = new Node(coeff, exp);  // Create a new node for the term
        // If the list is empty or the new exponent is larger than the head's exponent, insert at head
        if (!head || head->exponent < exp) {
            newNode->next = head;
            head = newNode;
        } else {
            // Traverse to find the correct position in descending order of exponents
            Node* temp = head;
            while (temp->next && temp->next->exponent > exp) {
                temp = temp->next;
            }
            // If a term with the same exponent exists, add the coefficients
            if (temp->exponent == exp) {
                temp->coefficient += coeff;
            } else {
                // Insert the new term at the appropriate position
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    // Function to display the polynomial in standard format
    void display() {
        if (!head) {  // If the polynomial is empty, display "0"
            cout << "0" << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            // Print the coefficient and exponent
            cout << temp->coefficient << "x^" << temp->exponent;
            temp = temp->next;
            if (temp) cout << " + ";  // Print " + " between terms
        }
        cout << endl;  // End the line after printing the polynomial
    }

    // Function to add another polynomial to the current one and return the result
    Polynomial addPolynomial(Polynomial& p2) {
        Polynomial result;  // Result polynomial to store the sum
        Node* ptr1 = head;  // Pointer for the current polynomial
        Node* ptr2 = p2.head;  // Pointer for the second polynomial

        // Traverse both polynomials simultaneously
        while (ptr1 && ptr2) {
            // If ptr1's exponent is higher, add its term to the result
            if (ptr1->exponent > ptr2->exponent) {
                result.insertTerm(ptr1->coefficient, ptr1->exponent);
                ptr1 = ptr1->next;
            }
            // If ptr2's exponent is higher, add its term to the result
            else if (ptr1->exponent < ptr2->exponent) {
                result.insertTerm(ptr2->coefficient, ptr2->exponent);
                ptr2 = ptr2->next;
            }
            // If exponents are the same, add the coefficients and insert the sum
            else {
                int sumCoeff = ptr1->coefficient + ptr2->coefficient;
                if (sumCoeff != 0) {  // Only add if the result coefficient is non-zero
                    result.insertTerm(sumCoeff, ptr1->exponent);
                }
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }

        // Add remaining terms from the first polynomial
        while (ptr1) {
            result.insertTerm(ptr1->coefficient, ptr1->exponent);
            ptr1 = ptr1->next;
        }
        
        // Add remaining terms from the second polynomial
        while (ptr2) {
            result.insertTerm(ptr2->coefficient, ptr2->exponent);
            ptr2 = ptr2->next;
        }

        return result;  // Return the result polynomial
    }
};


// Menu-driven function
int main() 
{
    Polynomial p1, p2, result;
    int choice;

    do {
        cout << "\n***** POLYNOMIAL OPERATIONS MENU *****\n";
        cout << "1. Insert term in Polynomial 1\n";
        cout << "2. Insert term in Polynomial 2\n";
        cout << "3. Display Polynomial 1\n";
        cout << "4. Display Polynomial 2\n";
        cout << "5. Add Polynomials\n";
        cout << "6. Display Resultant Polynomial\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int coeff, exp;
                cout << "Enter coefficient and exponent for Polynomial 1: ";
                cin >> coeff >> exp;
                p1.insertTerm(coeff, exp);
                break;
            }
            case 2: {
                int coeff, exp;
                cout << "Enter coefficient and exponent for Polynomial 2: ";
                cin >> coeff >> exp;
                p2.insertTerm(coeff, exp);
                break;
            }
            case 3: {
                cout << "Polynomial 1: ";
                p1.display();
                break;
            }
            case 4: {
                cout << "Polynomial 2: ";
                p2.display();
                break;
            }
            case 5: {
                result = p1.addPolynomial(p2);
                cout << "Polynomials added successfully!" << endl;
                break;
            }
            case 6: {
                cout << "Resultant Polynomial: ";
                result.display();
                break;
            }
            case 7: {
                cout << "Exiting program!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice! Please try again." << endl;
            }
        }
    } while (choice != 7);
    return 0;
}
