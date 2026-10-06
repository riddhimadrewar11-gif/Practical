#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int x){
        data = x;
    }
};

class CircularQ{
    Node* front;
    Node* rear;
    int size;

    public:
    CircularQ(){
        front = NULL;
        rear = NULL;
        size = 0;
    }

    void enQ(int val);
    void deQ();
    void top();
};


void CircularQ :: enQ(int val){
    Node* temp = new Node(val);
    if(front == NULL){
        front = rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
    size++;
}

void CircularQ :: deQ(){
    if(front == NULL){
        cout<<"Queue is empty."<<endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    int pop = temp->data;
    delete temp;
    cout<<"Pop value:"<<pop<<endl;
    size--;
}

void CircularQ :: top(){
    if(front == NULL){
        cout<<"Queue is empty."<<endl;
        return;
    }
    int top = front->data;
    cout<<"Top value:"<<top<<endl;
}

int main() {
    CircularQ c;
    int choice;
    int x;

    do{
        cout<<"Enter 1 for enqueue"<<endl;
        cout<<"Enter 2 for dequeue"<<endl;
        cout<<"Enter 3 for top element"<<endl;
        cout<<"Enter choice:"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter value for enqueue:"<<endl;
                cin>>x;
                c.enQ(x);
            break;
            case 2: c.deQ();
            break;
            case 3 :c.top();
            break;
            case 4: cout<<"Exit";
            default: cout<<"Invalid choice";
        }
    }while(choice!=4);
    return 0;
}
