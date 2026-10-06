#include<iostream>
using namespace std;

#define MAX 5

class Stack{
    private:
    int stack[MAX];
    int top;

    public:
    Stack() {
        top = -1;
    }
    bool isEmpty();
    bool isFull();
    void push(int n);
    void pop();
    void peek();
};

bool Stack :: isEmpty() {
    if(top == -1) return true;
    else return false;
}

bool Stack :: isFull() {
    if(top == MAX-1) return true;
    else return false;
}

void Stack :: push(int n) {
    if(isFull()) {
        cout<<"Stack overflow. "<<endl;
        return;
    }
    top++;
    stack[top] = n;
    cout<<"Pushed value: "<<n<<endl;
}

void Stack :: pop() {
    if(isEmpty()) {
        cout<<"Stack is empty, there is no element to pop. "<<endl;
        return;
    }
    cout<<"Popoed value from stack: "<<stack[top]<<endl;
    top--;
}

void Stack :: peek() {
    if(isEmpty()) {
        cout<<"Stack is empty. "<<endl;
        return;
    }
    cout<<"Peeked value from stack: "<<stack[top]<<endl;
}

int main() {
    Stack s;
    int ch , value;

    do{
        cout<<"Enter 1 to push element:"<<endl;
        cout<<"Enter 2 to pop element:"<<endl;
        cout<<"Enter 3 to peek element:"<<endl;
        cout<<"Enter 4 to check isEmpty:"<<endl;
        cout<<"Enter 5 to check isFull:"<<endl;
        cout<<"Enter 6 to exit:"<<endl;

        cout<<"Enter choice: ";
        cin>>ch;

        switch(ch) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                if(s.isEmpty()) {
                    cout<<"Stack is empty. "<<endl;
                }
                else{
                    cout<<"Stack is not empty. "<<endl;
                }
                break;

            case 5:
                if(s.isFull()) {
                    cout<<"Stack is full. "<<endl;
                }
                else{
                    cout<<"Stack is not full. "<<endl;
                }
                break;

            case 6:
                cout<<"Exiting the program. "<<endl;
                break;

            default:
                cout<<"Invalid choice. "<<endl;
        }
    }while(ch != 6);

    return 0;
}