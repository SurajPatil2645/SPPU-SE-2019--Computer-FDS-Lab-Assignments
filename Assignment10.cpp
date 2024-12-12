/* Implement C++ program for expression conversion as infix to postfix and its evaluation
using stack based on given conditions:
1. Operands and operator, both must be single character.
2. Input Postfix expression must be in a desired format. 3. Only '+', '-', '*' and
'/ ' operators are expected.
*/
#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
#define N 10

using namespace std;

class Stack {
public:
    char arr[N];
    int top;

    Stack() : top(-1) {}

    void push(char c) {
        if (top == (N - 1)) {
            cout << "Stack overflow" << endl;
        } else {
            arr[++top] = c;
        }
    }

    char pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return '\0'; // Return null character on underflow
        }
        return arr[top--];
    }

    char peek() {
        return (top == -1) ? '\0' : arr[top];
    }

    int precedence(char opr) {
        if (opr == '*' || opr == '/') return 2;
        if (opr == '+' || opr == '-') return 1;
        return 0; // For '(' and any invalid character
    }

    string infixToPostfix(const string &ex) {
        string postfix;
        for (char ch : ex) {
            if (isalnum(ch)) { // If the character is an operand
                postfix += ch;
            } else if (ch == '(') {
                push(ch);
            } else if (ch == ')') {
                while (top != -1 && peek() != '(') {
                    postfix += pop();
                }
                pop(); // Remove the '(' from the stack
            } else { // Operator
                while (top != -1 && precedence(ch) <= precedence(peek())) {
                    postfix += pop();
                }
                push(ch);
            }
        }
        while (top != -1) {
            postfix += pop();
        }
        return postfix;
    }
};

class OperandStack {
public:
    float stk[N];
    int top;

    OperandStack() : top(-1) {}

    void push(float c) {
        if (top == (N - 1)) {
            cout << "Stack overflow" << endl;
        } else {
            stk[++top] = c;
        }
    }

    float pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return 0.0; // Return 0 on underflow
        }
        return stk[top--];
    }

    float evaluate(const string &op) {
        float op1, op2;
        for (char ch : op) {
            if (isalnum(ch)) { // If the character is an operand
                cout << "Enter value for operand " << ch << ": ";
                float value;
                cin >> value;
                push(value);
            } else { // Operator
                op1 = pop();
                op2 = pop();
                switch (ch) {
                    case '+': push(op2 + op1); break;
                    case '-': push(op2 - op1); break;
                    case '*': push(op2 * op1); break;
                    case '/':
                        if (op1 != 0)
                            push(op2 / op1);
                        else {
                            cout << "Division by zero error" << endl;
                            return 0.0;
                        }
                        break;
                }
            }
        }
        return pop();
    }
};

int main() {
    Stack s;
    OperandStack s1;
    string ex;

    cout << "Enter an expression: ";
    cin >> ex;

    string postfix = s.infixToPostfix(ex);
    cout << "Postfix Expression: " << postfix << endl;

    float result = s1.evaluate(postfix);
    cout << "Result of Evaluation: " << result << endl;

    return 0;
}
