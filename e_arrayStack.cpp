#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int *arr;
        int top;
        int capacity;

    // taking int capacity 
    Stack(int size){
        top = -1;
        capacity = size;
        arr = new int[size];
    }

    ~Stack(){
        delete[] arr;
    }

    // push fn
    void push(int x){
        if(isFull()){
            cout << "stack is full" << endl;
            return;
        }
        top++;
        arr[top] = x; 
    }

    // pop fn
    int pop(){
        if(isEmpty()){
            cout << "stack empty" << endl;
            return INT_MIN;
        }

        int temp = arr[top];
        top--;
        return temp;
    }

    // With an array-based stack, the memory for the array is allocated once (say new int[capacity]). That block stays put until you delete[] arr in the destructor.

    // When you pop(), you don’t delete that slot — you just move the top pointer down. The next push() will overwrite the old value.

    // peek 
    void peek(){
        if(isEmpty()){
            cout << "stack empty" << endl;
        }else{
            cout << arr[top] << endl;
        }
    }

    // isEmpty
    bool isEmpty(){
        // if(top == -1){
        //     cout << "empty stack" << endl;
        //     return true;
        // }
        // cout << "stack not empty" << endl;
        // return false;

        return top==-1;
    }

    // isFull
    bool isFull(){
        // if(top == capacity-1){
        //     cout << "stack is full" << endl;
        //     return true;
        // }
        // cout << "stack not full" << endl;
        // return false;

        return top == capacity-1;
    }

    // get capacity
    void getCapacity(){
        cout << capacity << endl;
    }

    void getSize(){
        cout << "no of element : " << top+1 << endl;
    }

    void printStack(){
        if(!isEmpty()){
            for(int i=0;i<=top;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }else{
            cout << "empty stack" << endl;
        }
    }

};

int main(){
    int size;
    cout << "enter capacity of stack : ";
    cin >> size;

    Stack s(size);

    while(true){
        cout << endl;
        cout << "***************" << endl;
        cout << "Stack Program" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Print Stack" << endl;
        cout << "5. Size / no of elements" << endl;
        cout << "6. Exit" << endl;
        cout << "***************" << endl;
        cout << endl;

        int choice;
        cout << "enter choice : ";
        cin >> choice;

        switch(choice){
            case 1: {
                int x;
                cout << "enter value to push : ";
                cin >> x;
                s.push(x);
                break;
            }
            case 2: {
                int popped = s.pop();
                if(popped != INT_MIN){
                    cout << "Popped Value : " << popped << endl;
                }else{
                    cout << "empty stack" << endl;
                }
                break;
            }
            case 3: {
                s.peek();
                break;
            }
            case 4: {
                s.printStack();
                break;
            }
            case 5: {
                s.getSize();
                break;
            }
            case 6: {
                cout << "Exiting..." << endl;
                return 0;
            }
            default :
                cout << "invalid choice !!" << endl;
        }
    }
}
