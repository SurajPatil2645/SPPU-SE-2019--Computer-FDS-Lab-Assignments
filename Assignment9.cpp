/* In any language program mostly syntax error occurs due to unbalancing delimiter such
as (),{},[]. Write C++ program using stack to check whether given expression is well
parenthesized or not.
*/
#include <iostream>
#define n 15
using namespace std;

class stack {
    char stk[n];
public:
    int top;
    stack() {
        top = -1;
    }
    void push(char x);
    void pop();
    bool isfull();
    bool isempty();
    char peek();
};

void stack::push(char x) {
    if (top == n - 1) {
        cout << "Stack overflow" << endl;
    } else {
        top += 1;
        stk[top] = x;
    }
}

void stack::pop() {
    if (top == -1) {
        cout << "Stack underflow" << endl;
    } else {
        top--;
    }
}

bool stack::isempty() {
    return top == -1;
}

char stack::peek() {
    if (!isempty()) {
        return stk[top];
    }
    return '\0';
}

int main() {
    string exp;
    cout << "Enter the expression:" << endl;
    cin >> exp;
    int l = exp.length();
    stack s;

    for (int i = 0; i < l; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            s.push(exp[i]);
        }
        if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (s.isempty()) {
                cout << "Not well parenthesized" << endl;
                return 0;
            }
            char ch = s.peek();
            if ((ch == '(' && exp[i] == ')') ||
                (ch == '[' && exp[i] == ']') ||
                (ch == '{' && exp[i] == '}')) {
                s.pop();
            } else {
                cout << "Not well parenthesized" << endl;
                return 0;
            }
        }
    }

    if (s.isempty()) {
        cout << "Well parenthesized" << endl;
    } else {
        cout << "Not well parenthesized" << endl;
    }

    return 0;
}
s