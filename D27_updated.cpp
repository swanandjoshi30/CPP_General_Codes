#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); ++i) {
        char ch = infix[i];
        if (isOperand(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop '('
        } else if (isOperator(ch)) {
            while (!s.empty() && getPrecedence(ch) <= getPrecedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int evaluatePostfix(const string& postfix) {
    stack<int> s;

    for (int i = 0; i < postfix.length(); ++i) {
        char ch = postfix[i];
        if (isOperand(ch)) {
            s.push(ch - '0'); // Convert char to integer
        } else if (isOperator(ch)) {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            switch (ch) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
            }
        }
    }

    return s.top();
}

int main() {
    string infixExpression;
    cout << "Enter Infix Expression: ";
    cin >> infixExpression;

    // Convert infix to postfix
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix Expression: " << postfixExpression << endl;

    // Evaluate postfix expression
    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}

