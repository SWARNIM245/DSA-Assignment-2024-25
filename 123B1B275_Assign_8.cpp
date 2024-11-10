//Name:Swarnim Survase , PRN:123B1B275 , ASSIGNMENT N0 8
////Write a program to convert infix expression to postfix, infix expression to prefix and evaluation of postfix and prefix expression.

#include <iostream>
#include <string> 
using namespace std;

class Stack {
private:
    char a[100]; // Array to store stack elements
    int top;     // Index of the top element

public:
    // Constructor
    Stack() {
        top = -1; // Initialize stack as empty
    }

    // Push operation
    void push(char x) {
        if (top >= 99) {
            cout << "Stack Overflow\n";
            return;
        }
        a[++top] = x; // Increment top and push the element
    }

    // Pop operation
    char pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return '\0';
        }
        return a[top--];
    }

    // Peek operation
    char peek() {
        if (top == -1) {
            return '\0';
        }
        return a[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Operator precedence
    int prec(char c) {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

    // Function to return associativity of operators
    char associativity(char c) {
        if (c == '^')
            return 'R'; // Right associative
        return 'L'; // Left associative
    }
};

// Helper function to reverse a string 
void reverseString(string &s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        swap(s[i], s[n - i - 1]);
    }
}

// Function to convert infix to postfix
void infixToPostfix(string s) {
    Stack st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the character is an operand, add it to the result
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        }
        else if (c == '(') {
            st.push('(');
        }
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                result += st.pop();
            }
            st.pop();
        }
        else {
            while (!st.isEmpty() && (st.peek() != '(' && (st.prec(c) < st.prec(st.peek()) ||
                   (st.prec(c) == st.prec(st.peek()) && st.associativity(c) == 'L')))) {
                result += st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty()) {
        result += st.pop();
    }

    cout << "Postfix: " << result << endl;
}

// Function to convert infix to prefix
void infixToPrefix(string s) {
    reverseString(s);

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        } else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    Stack st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        } else if (c == '(') {
            st.push('(');
        } else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                result += st.pop();
            }
            st.pop();
        } else {
            while (!st.isEmpty() && (st.peek() != '(' && (st.prec(c) < st.prec(st.peek()) ||
                   (st.prec(c) == st.prec(st.peek()) && st.associativity(c) == 'L')))) {
                result += st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty()) {
        result += st.pop();
    }

    reverseString(result);
    cout << "Prefix: " << result << endl;
}

// Function to evaluate postfix expressions
int evaluatePostfix(const string& exp) {
    int results[100];
    int index = -1;

    for (char c : exp) {
        if (c >= '0' && c <= '9') {
            results[++index] = c - '0';
        } else {
            int operand2 = results[index--];
            int operand1 = results[index--];

            switch (c) {
                case '+': results[++index] = operand1 + operand2; break;
                case '-': results[++index] = operand1 - operand2; break;
                case '*': results[++index] = operand1 * operand2; break;
                case '/': results[++index] = operand1 / operand2; break;
                case '^': results[++index] = 1; // Placeholder for power, can be implemented if needed
            }
        }
    }
    return results[index];
}

// Function to evaluate prefix expressions
int evaluatePrefix(const string& exp) {
    int results[100];
    int index = -1;

    for (int i = exp.length() - 1; i >= 0; i--) {
        char c = exp[i];
        if (c >= '0' && c <= '9') {
            results[++index] = c - '0';
        } else {
            int operand1 = results[index--];
            int operand2 = results[index--];

            switch (c) {
                case '+': results[++index] = operand1 + operand2; break;
                case '-': results[++index] = operand1 - operand2; break;
                case '*': results[++index] = operand1 * operand2; break;
                case '/': results[++index] = operand1 / operand2; break;
                case '^': results[++index] = 1; // Placeholder for power, can be implemented if needed
            }
        }
    }
    return results[index];
}

int main() {
    int choice;
    string exp;

    do {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Convert Infix to Postfix\n";
        cout << "2. Convert Infix to Prefix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Evaluate Prefix Expression\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter an infix expression: ";
                cin >> exp;
                infixToPostfix(exp);
                break;

            case 2:
                cout << "Enter an infix expression: ";
                cin >> exp;
                infixToPrefix(exp);
                break;

            case 3:
                cout << "Enter a postfix expression: ";
                cin >> exp;
                cout << "Postfix evaluation result: " << evaluatePostfix(exp) << endl;
                break;

            case 4:
                cout << "Enter a prefix expression: ";
                cin >> exp;
                cout << "Prefix evaluation result: " << evaluatePrefix(exp) << endl;
                break;

            case 5:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

