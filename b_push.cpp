#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int value;
        Node* next;

        Node(int value){
            this->value = value;
            next = NULL;
        }
};

class Stack{
    private:
        Node* top;
        int height;

    public:
        Stack(int value){
            Node* newNode = new Node(value);
            top = newNode;
            height = 1;
        }

        void getTop(){
            cout << "TOP :" << top->value << endl;
        }

        void getHeight(){
            cout << "HEIGHT : " << height << endl;
        }

        void push(int value){
            Node* newNode = new Node(value);
            // if empty; - no need to create if statements because the top already points to NULL in case of empty stack.
            if(top == NULL){
                top = newNode;
                return;
            // if not empty;
            }else{
                newNode->next = top;
                top = newNode;
            }
            height++;
            return;
        }

        void printStack(){
            Node* temp = top;
            while(temp!=NULL){
                cout << temp->value << " -> ";
                temp = temp->next;
            }
            cout << "END" << endl;
        }
};

int main(){
    Stack* s = new Stack(0);
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->printStack();
}