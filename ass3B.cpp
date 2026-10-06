#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
    char data;
    Node* next;
    Node(char c){
        data = c;
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
    void push(char c);
    char pop();
    char peep();
};

bool Stack :: isEmpty(){
    if(top == NULL) return true;
    else return false;
}

void Stack :: push(char c){
    Node* p;
    p = new Node(c);

    p->next = top;
    top = p;
    cout<<"Pushed value: "<<c<<endl;
}

 char Stack :: pop() {
    if(isEmpty()) {
        return -1;
    }
    else{
        Node* temp = top;
        char poppedchar = top->data;
        top = top->next;
        delete temp;
        return poppedchar;
    }
}

char Stack :: peep() {
    if(isEmpty()) {
        return -1;
    }
    else{
        return top->data;
    }
}

class conversion{
    private:
    string infix;
    string postfix;
    
    public:
    void input();
    int precedence(char ch);
    int associativity(char y);
    string infixtoPostfix();
};


void conversion :: input() {
    cout<<"Enter infix string: ";
    cin>>infix;
}

int conversion :: precedence(char ch) {
    if(ch=='+' || ch=='-') return 1;
    else if(ch=='*' || ch=='/' || ch=='%') return 2;
    else if(ch=='^') return 3;
    return 0;
}

int conversion :: associativity(char y) {
    if(y=='+' || y=='*' || y=='/' || y=='%' || y=='-') return 1;
    else if(y=='^') return 2;
    return 0;
}

string conversion :: infixtoPostfix() {
    Stack s;
    int l = infix.length();
    int i=0 , k=0;
    char x;

    while(i<l){
        if(isalpha(infix[i])){
            postfix += infix[i];
            i++;
        }
        else if(infix[i]=='(' || infix[i]==')') {
            if(infix[i] == '('){
                s.push(infix[i]);
                i++;
            }
            else{
                while(!s.isEmpty() && s.peep() != '('){
                    x = s.pop();
                    postfix += x;
                }
                x = s.pop();
                i++;
            }
        }
        else{
            char X = infix[i];
            char Y = s.peep();
            if(precedence(Y) < precedence(X) || s.isEmpty()){
                s.push(infix[i]);
                i++;
            }
            else if(precedence(X) == precedence(Y)){
                if(associativity(X) == 1){
                    x = s.pop();
                    postfix += x;
                    s.push(infix[i]);
                    i++;
                }
                else if (associativity(X) == 2){
                    s.push(infix[i]);
                    i++;
                }
            }
            else{
                while(precedence(X)<=precedence(Y) && !s.isEmpty()){
                    x = s.pop();
                    postfix += x;
                }
                s.push(infix[i]);
                i++;
            }
        }
    }

    while(!s.isEmpty()){
        x = s.pop();
        postfix += x;
    }

    return postfix;
}


int main() {
    conversion c;
    c.input();
    string postfix = c.infixtoPostfix();
    cout<<postfix;

    return 0;
}

