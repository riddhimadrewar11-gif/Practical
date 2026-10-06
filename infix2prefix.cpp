#include<iostream>
using namespace std;

class Node{
    public:
    char data;
    Node* next;
    Node(char ch){
        data = ch;
        next = NULL;
    }
};

class Stack{
    private:
    Node* top ;
    
    public:
    Stack() {
        top = NULL;
    }
    bool isEmpty();
    void push(char c);
    char pop();
    char peep();
};

bool Stack :: isEmpty() {
    if(top == NULL) return true;
    return false;
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
    string prefix;
    
    public:
    void input();
    int precedence(char ch);
    int associativity(char y);
    string infixtoPrefix();
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

string conversion :: infixtoPrefix() {
    Stack s;
    int l = infix.length();
    prefix.resize(l);
    int i=l-1 , k=l-1;
    char x;

    while(i>=0){
        if(isalpha(infix[i])){
            prefix[k] = infix[i];
            i--;
            k--;
        }
        else if(infix[i]=='(' || infix[i]==')') {
            if(infix[i] == ')'){
                s.push(infix[i]);
                i--;
            }
            else{
                while(!s.isEmpty() && s.peep() != ')'){
                    x = s.pop();
                    prefix[k] = x;
                    k--;
                }
                x = s.pop();
                i--;
                k--;
            }
        }
        else{
            char X = infix[i];
            char Y = s.peep();
            if(precedence(Y) < precedence(X) || s.isEmpty()){
                s.push(infix[i]);
                i--;
            }
            else if(precedence(X) == precedence(Y)){
                if(associativity(X) == 1){
                    x = s.pop();
                    prefix[k] = x;
                    k--;
                    s.push(infix[i]);
                    i--;
                }
                else if (associativity(X) == 2){
                    s.push(infix[i]);
                    i--;
                }
            }
            else{
                while(precedence(X)<=precedence(Y) && !s.isEmpty()){
                    x = s.pop();
                    prefix[k] = x;
                    k--;
                }
                s.push(infix[i]);
                i--;
            }
        }
    }

    while(!s.isEmpty()){
        x = s.pop();
        prefix[k] = x;
        k--;
    }

    return prefix;
}


int main() {
    conversion c;
    c.input();
    string Prefix = c.infixtoPrefix();
    cout<<Prefix<<endl;

    return 0;
}
