#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int capacity;

    Stack(int size)
    {
        top = -1;
        capacity = size;
        arr = new int[size];
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int x)
    {
        if (isFull())
            return;
        arr[++top] = x;
    }

    int pop()
    {
        if (isEmpty())
            return INT_MIN;
        return arr[top--];
    }

    int peek()
    {
        if (isEmpty())
            return INT_MIN;
        return arr[top];
    }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == capacity - 1; }
};

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infix_to_postfix(string infix)
{
    Stack st(infix.size());
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.isEmpty() && st.peek() != '(')
            {
                postfix += (char)st.pop();
            }
            st.pop();
        }
        else if (isOperator(c))
        {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c))
            {
                postfix += (char)st.pop();
            }
            st.push(c);
        }
    }

    while (!st.isEmpty())
    {
        postfix += (char)st.pop();
    }

    return postfix;
}

string infix_to_prefix(string infix)
{
    // Step 1: reverse infix & swap brackets
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Step 2: convert reversed infix to postfix
    string postfix = infix_to_postfix(infix);

    // Step 3: reverse postfix → prefix
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main()
{
    string infix;
    cout << "enter the infix expression : ";
    cin >> infix;

    string prefix = infix_to_prefix(infix);
    cout << "PREFIX : " << prefix << endl;
    return 0;
}
