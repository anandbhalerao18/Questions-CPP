// 6.	Implement stack as an abstract data type using singly linked list and use this ADT for conversion of infix expression to postfix, prefix and evaluation of postfix and prefix expression 

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Define a structure for stack node using singly linked list
struct Node {
    char data;
    Node* next;
};

// Stack class definition using singly linked list
class Stack {
public:
    Node* top;
    
    Stack() {
        top = nullptr;
    }
    
    // Push function to add element to stack
    void push(char value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Pop function to remove element from stack
    char pop() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        char value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    // Peek function to return the top element without removing it
    char peek() {
        if (top == nullptr) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";
    
    for (char& ch : infix) {
        if (isalnum(ch)) {  // If the character is an operand, add it to the result
            postfix += ch;
        }
        else if (ch == '(') {  // If the character is '(', push it to the stack
            s.push(ch);
        }
        else if (ch == ')') {  // If the character is ')', pop until '('
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop();  // Discard the '('
        }
        else {  // If the character is an operator
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }

    // Pop any remaining operators from the stack
    while (!s.isEmpty()) {
        postfix += s.pop();
    }
    
    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(string postfix) {
    Stack s;
    
    for (char& ch : postfix) {
        if (isdigit(ch)) {  // If the character is a digit, push it onto the stack
            s.push(ch - '0');
        }
        else {  // If the character is an operator
            int operand2 = s.pop();
            int operand1 = s.pop();
            
            switch (ch) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
            }
        }
    }
    
    return s.pop();
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Evaluation of postfix expression: " << result << endl;

    return 0;
}
