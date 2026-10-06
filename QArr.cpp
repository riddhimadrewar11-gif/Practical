#include<iostream>
using namespace std;

#define MAX 5

class Queue{
    int arr[MAX];
    int front;
    int rear;

    public:
    Queue() {
        front=rear=-1;
    }

    void enQ(int x);
    void deQ();
    bool isEmpty();
    bool isFull();
    void Front();
    void display();
};

// Checks whether queue is empty
bool Queue :: isEmpty() {
    if((front==-1 && rear==-1) || front>rear) 
        return true;
    else 
        return false; 
}

// Checks whether queue is full
bool Queue :: isFull() {
    if(rear == MAX-1) 
        return true;
    else 
        return false;
}

// Adds element to the queue
void Queue :: enQ(int x) {
    if(isFull()) {
        cout<<"Queue is full"<<endl;
        return;
    }

    // Set front for first element
    if(isEmpty()) 
        front=0;

    arr[++rear] = x;

    cout<<"Enqueued element : "<<x<<endl;
}

// Removes element from the queue
void Queue :: deQ() {
    if(isEmpty()) {
        cout<<"Queue is empty"<<endl;
        return;
    }

    int el = arr[front];
    front++;

    cout<<"Dequeued element : "<<el<<endl;
}

// Displays front element
void Queue :: Front() {
    if (isEmpty()) {
        cout << "Queue is Empty"<<endl;
        return;
    }

    cout << "Front : " << arr[front] << endl;
}

// Displays all queue elements
void Queue :: display() {
    if(isEmpty()) {
    cout << "Queue is empty" << endl;
    return;
    }

    for(int i=front; i<=rear; i++){
        cout<<arr[i]<<" ";
    }
}

int main() {
    Queue q;
    int ch, value;

    do{
        cout<<"Enter 1 to enqueue element"<<endl;
        cout<<"Enter 2 to dequeue element"<<endl;
        cout<<"Enter 3 to check isempty"<<endl;
        cout<<"Enter 4 to check isfull"<<endl;
        cout<<"Enter 5 to display front element"<<endl;
        cout<<"Enter 6 to exit"<<endl;

        cout<<"Enter choice: ";
        cin>>ch;

        switch(ch) {

            // Enqueue operation
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enQ(value);
                break;

            // Dequeue operation
            case 2:
                q.deQ();
                break;

            // Check if queue is empty
            case 3:
                if(q.isEmpty()) {
                    cout<<"Queue is empty. "<<endl;
                }
                else{
                    cout<<"Queue is not empty. "<<endl;
                }
                break;

            // Check if queue is full
            case 4:
                if(q.isFull()) {
                    cout<<"Queue is full. "<<endl;
                }
                else{
                    cout<<"Queue is not full. "<<endl;
                }
                break;
            
            // Display front element
            case 5:
                q.Front();
                break;

            // Exit program
            case 6:
                cout<<"Exiting the program. "<<endl;
                break;

            default:
                cout<<"Invalid choice. "<<endl;
        }

    }while(ch != 6);

    cout<<"Queue : ";
    q.display();

    return 0;
}

// Output

// Enter 1 to enqueue element
// Enter 2 to dequeue element
// Enter 3 to check isempty
// Enter 4 to check isfull
// Enter 5 to display front element
// Enter 6 to exit
// Enter choice: 3
// Queue is empty. 
// Enter 1 to enqueue element
// Enter 2 to dequeue element
// Enter 3 to check isempty
// Enter 4 to check isfull
// Enter 5 to display front element
// Enter 6 to exit
// Enter choice: 1
// Enter value: 10
// Enqueued element : 10
// Enter 1 to enqueue element
// Enter 2 to dequeue element
// Enter 3 to check isempty
// Enter 4 to check isfull
// Enter 5 to display front element
// Enter 6 to exit
// Enter choice: 1
// Enter value: 20
// Enqueued element : 20
// Enter 1 to enqueue element
// Enter 2 to dequeue element
// Enter 3 to check isempty
// Enter 4 to check isfull
// Enter 5 to display front element
// Enter 6 to exit
// Enter choice: 1
// Enter value: 30
// Enqueued element : 30
// Enter 1 to enqueue element
// Enter 2 to dequeue element
// Enter 3 to check isempty
// Enter 4 to check isfull
// Enter 5 to display front element
// Enter 6 to exit
// Enter choice: 5
// Front : 10
// Enter 1 to enqueue element
// Enter 2 to dequeue element
// Enter 3 to check isempty
// Enter 4 to check isfull
// Enter 5 to display front element
// Enter 6 to exit
// Enter choice: 2
// Dequeued element : 10
// Enter 1 to enqueue element
// Enter 2 to dequeue element
// Enter 3 to check isempty
// Enter 4 to check isfull
// Enter 5 to display front element
// Enter 6 to exit
// Enter choice: 5
// Front : 20
// Enter 1 to enqueue element
// Enter 2 to dequeue element
// Enter 3 to check isempty
// Enter 4 to check isfull
// Enter 5 to display front element
// Enter 6 to exit
// Enter choice: 1
// Enter value: 40
// Enqueued element : 40
// Enter 1 to enqueue element
// Enter 2 to dequeue element
// Enter 3 to check isempty
// Enter 4 to check isfull
// Enter 5 to display front element
// Enter 6 to exit
// Enter choice: 1
// Enter value: 50
// Enqueued element : 50
// Enter 1 to enqueue element
// Enter 2 to dequeue element
// Enter 3 to check isempty
// Enter 4 to check isfull
// Enter 5 to display front element
// Enter 6 to exit
// Enter choice: 4
// Queue is full. 
// Enter 1 to enqueue element
// Enter 2 to dequeue element
// Enter 3 to check isempty
// Enter 4 to check isfull
// Enter 5 to display front element
// Enter 6 to exit
// Enter choice: 1
// Enter value: 60
// Queue is full
// Enter 1 to enqueue element
// Enter 2 to dequeue element
// Enter 3 to check isempty
// Enter 4 to check isfull
// Enter 5 to display front element
// Enter 6 to exit
// Enter choice: 2
// Dequeued element : 20
// Enter 1 to enqueue element
// Enter 2 to dequeue element
// Enter 3 to check isempty
// Enter 4 to check isfull
// Enter 5 to display front element
// Enter 6 to exit
// Enter choice: 3
// Queue is not empty. 
// Enter 1 to enqueue element
// Enter 2 to dequeue element
// Enter 3 to check isempty
// Enter 4 to check isfull
// Enter 5 to display front element
// Enter 6 to exit
// Enter choice: 6
// Exiting the program. 
// Queue : 30 40 50