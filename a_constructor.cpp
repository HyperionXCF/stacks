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

        void getHeight(){
            cout << "HEIGHT : " << height << endl;
        }

        void getTop(){
            cout << "TOP : " << top->value << endl;
        }
};

int main(){
    Stack* s = new Stack(0);
    s->getHeight();
    s->getTop();
}