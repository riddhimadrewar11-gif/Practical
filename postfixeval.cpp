#include<iostream>
using namespace std;

#define MAX 30

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
    int pop();
    int peep();
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
}

int Stack :: pop() {
    if(isEmpty()) {
        cout<<"Stack is empty, there is no element to pop. "<<endl;
        return -1;
    }

    int value = stack[top];
    top--;

    return value;
}

int Stack :: peep() {
    if(isEmpty()) {
        cout<<"Stack is empty. "<<endl;
        return -1;
    }

    return stack[top];
}

int evaluatePostfix(string exp) {
    Stack s;

    for(int i = 0; i < exp.length(); i++) {

        if(isdigit(exp[i])) {
            s.push(exp[i] - '0');
        }

        else {
            int val2 = s.pop();
            int val1 = s.pop();

            int result;

            switch(exp[i]) {
                case '+':
                    result = val1 + val2;
                    break;

                case '-':
                    result = val1 - val2;
                    break;

                case '*':
                    result = val1 * val2;
                    break;

                case '/':
                    result = val1 / val2;
                    break;
            }

            s.push(result);
        }
    }

    return s.peep();
}

int main() {
    string exp;

    cout<<"Enter postfix expression: ";
    cin>>exp;

    cout<<"Result = "<<evaluatePostfix(exp)<<endl;

    return 0;
}