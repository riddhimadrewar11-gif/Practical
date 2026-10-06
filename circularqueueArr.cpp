#include<iostream>
using namespace std;
#define size 5

class CircularQ{
    private:
    int arr[size];
    int rear;
    int front;
    int currsize;

    public:
    CircularQ(){
        rear = -1;
        front = -1;
        currsize = 0;
    }
    void enQ(int x);
    void deQ();
    void top();
};


void CircularQ :: enQ(int x) {
    if(currsize == size) {
        cout<<"Queue is full"<<endl;
        return;
    }
    if(currsize == 0) {
        rear = 0;
        front = 0;
    }
    else{
        rear = (rear+1)%size;
    }
    arr[rear] = x;
    currsize++;
}

void CircularQ :: deQ() {
    if(currsize == 0){
        cout<<"Queue is empty"<<endl;
        return;
    }
    int el = arr[front];
    if(currsize == 1){
        front = -1;
        rear = -1;
    }
    else{
        front = (front+1)%size;
    }
    currsize--;
    cout<<"dequeued element:"<<el<<endl;
}

void CircularQ :: top(){
    if(currsize==0){
        cout<<"Queue is empty."<<endl;
    }
    int top =  arr[front];
    cout<<"Top element:"<<top;
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