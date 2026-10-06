//Stack using Linked List

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int n){
        data = n;
        next = NULL;
    }
};

class Stack{
    private:
    Node* top;

    public:
    Stack(){
        top = NULL;
    }

    bool isEmpty();
    void push(int n);
    void pop();
    void peep();
};

bool Stack :: isEmpty(){
    if(top == NULL) return true;
    else return false;
}

void Stack :: push(int n){
    Node* p;
    p = new Node(n);

    p->next = top;
    top = p;
    cout<<"Pushed value: "<<n<<endl;
}

void Stack :: pop() {
    if(isEmpty()) {
        cout<<"Stack is empty."<<endl;
    }
    else{
        Node* temp = top;
        cout<<"Popped value: "<<top->data<<endl;
        top = top->next;
        delete temp;
    }
}

void Stack :: peep() {
    if(isEmpty()) {
        cout<<"Stack is empty."<<endl;
    }
    else{
        cout<<"Top value: "<<top->data<<endl;
    }
}

int main() {
    Stack s;
    int ch , value;

    do{
        cout<<"Enter 1 to push element:"<<endl;
        cout<<"Enter 2 to pop element:"<<endl;
        cout<<"Enter 3 to peep element:"<<endl;
        cout<<"Enter 4 to check isEmpty:"<<endl;
        cout<<"Enter 5 to exit:"<<endl;

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
                s.peep();
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
                cout<<"Exiting the program. "<<endl;
                break;

            default:
                cout<<"Invalid choice. "<<endl;
        }
    }while(ch != 5);

    return 0;
}