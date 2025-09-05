// this is a dynamic stack using linkedlist 
// therefore there is no isFull or isEmpty methods on this stack

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = NULL;
    }
};

class Stack
{
private:
    Node *top;
    int height;

public:
    Stack(int value)
    {
        Node *newNode = new Node(value);
        top = newNode;
        height = 1;
    }

    void getTop()
    {
        cout << "TOP :" << top->value << endl;
    }

    void getHeight()
    {
        cout << "HEIGHT : " << height << endl;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        // if empty; - no need to create if statements because the top already points to NULL in case of empty stack.
        if (top == NULL)
        {
            top = newNode;
            return;
            // if not empty;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
        height++;
        return;
    }

    void printStack()
    {
        if (height == 0)
        {
            cout << "empty stack" << endl;
            return;
        }

        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "END" << endl;
    }

    int pop()
    {
        // same as delete first
        // if empty
        if (top == NULL)
        {
            return INT_MIN;
        }

        // if not empty
        Node *temp = top;
        int popped_value = top->value;
        top = top->next;
        delete temp;
        height--;

        return popped_value;
    }

    int count()
    {
        // basically no of items in stack == height
        // but programmatically
        int count_ = 0;
        Node *temp = top;
        while (temp != NULL)
        {
            count_++;
            temp = temp->next;
        }

        return count_;
    }

    void peek()
    {
        cout << top->value << endl;
    }

    void change(int index, int new_value)
    {
        if (index < 0 || index >= height)
        {
            cout << "invalid index" << endl;
            return;
        }

        if (index == 0)
        {
            top->value = new_value;
        }
        else
        {
            Node *temp = top;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            temp->value = new_value;
        }
    }
};

int main()
{
    Stack *s = new Stack(0);
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->printStack();
    cout << s->count() << endl;
    s->peek();
    s->change(0, 100);
    s->printStack();
}