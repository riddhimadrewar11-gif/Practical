#include<iostream>
using namespace std;

// Node class for linked list
class Node{
    public:
    int data;
    Node *next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

// Queue using linked list
class Queue{
    private:
    Node *front;
    Node *rear;

    public:
    Queue() {
        front = rear = NULL;
    }

    void enQ(int x);
    void deQ();
    bool isEmpty();
    void Front();
    void display();
};

// Checks if queue is empty
bool Queue :: isEmpty() {
    return front==NULL;
}

// Adds element at rear
void Queue :: enQ(int x) {
    Node *temp = new Node(x);

    // First element
    if(front == NULL){
        front = rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }

    cout<<"Enqueued element : "<<x<<endl;
}

// Removes element from front
void Queue :: deQ() {
    if(isEmpty()) {
        cout<<"Queue is empty"<<endl;
    }
    else{
        Node *temp = front;
        front = front->next;

        // If queue becomes empty
        if (front == NULL)
            rear = NULL;

        cout<<"Dequeued element : "<<temp->data<<endl;

        delete temp;
    }
}

// Displays front element
void Queue :: Front() {
    if(isEmpty()) {
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Front element : "<<front->data<<endl;
    }
}

// Displays all queue elements
void Queue :: display() {
    if (isEmpty()) {
        cout << "Queue is Empty"<<endl;
    }
    else{
        Node* temp = front;

        cout << "Queue: ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
}

int main() {
    Queue q;
    int ch, value;

    do{
        cout<<"Enter 1 to enqueue element:"<<endl;
        cout<<"Enter 2 to dequeue element:"<<endl;
        cout<<"Enter 3 to check isempty:"<<endl;
        cout<<"Enter 4 to display front element:"<<endl;
        cout<<"Enter 5 to exit:"<<endl;

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

            // Display front element
            case 4:
                q.Front();
                break;

            // Exit program
            case 5:
                cout<<"Exiting the program. "<<endl;
                break;

            default:
                cout<<"Invalid choice. "<<endl;
        }

    }while(ch != 5);

    // Display final queue
    q.display();

    return 0;
}

// Output

// Enter 1 to enqueue element:
// Enter 2 to dequeue element:
// Enter 3 to check isempty:
// Enter 4 to display front element:
// Enter 5 to exit:
// Enter choice: 3
// Queue is empty. 
// Enter 1 to enqueue element:
// Enter 2 to dequeue element:
// Enter 3 to check isempty:
// Enter 4 to display front element:
// Enter 5 to exit:
// Enter choice: 1
// Enter value: 10
// Enqueued element : 10
// Enter 1 to enqueue element:
// Enter 2 to dequeue element:
// Enter 3 to check isempty:
// Enter 4 to display front element:
// Enter 5 to exit:
// Enter choice: 1
// Enter value: 20
// Enqueued element : 20
// Enter 1 to enqueue element:
// Enter 2 to dequeue element:
// Enter 3 to check isempty:
// Enter 4 to display front element:
// Enter 5 to exit:
// Enter choice: 1
// Enter value: 30
// Enqueued element : 30
// Enter 1 to enqueue element:
// Enter 2 to dequeue element:
// Enter 3 to check isempty:
// Enter 4 to display front element:
// Enter 5 to exit:
// Enter choice: 4
// Front element : 10
// Enter 1 to enqueue element:
// Enter 2 to dequeue element:
// Enter 3 to check isempty:
// Enter 4 to display front element:
// Enter 5 to exit:
// Enter choice: 2
// Dequeued element : 10
// Enter 1 to enqueue element:
// Enter 2 to dequeue element:
// Enter 3 to check isempty:
// Enter 4 to display front element:
// Enter 5 to exit:
// Enter choice: 4
// Front element : 20
// Enter 1 to enqueue element:
// Enter 2 to dequeue element:
// Enter 3 to check isempty:
// Enter 4 to display front element:
// Enter 5 to exit:
// Enter choice: 1
// Enter value: 40
// Enqueued element : 40
// Enter 1 to enqueue element:
// Enter 2 to dequeue element:
// Enter 3 to check isempty:
// Enter 4 to display front element:
// Enter 5 to exit:
// Enter choice: 2
// Dequeued element : 20
// Enter 1 to enqueue element:
// Enter 2 to dequeue element:
// Enter 3 to check isempty:
// Enter 4 to display front element:
// Enter 5 to exit:
// Enter choice: 3
// Queue is not empty. 
// Enter 1 to enqueue element:
// Enter 2 to dequeue element:
// Enter 3 to check isempty:
// Enter 4 to display front element:
// Enter 5 to exit:
// Enter choice: 2
// Dequeued element : 30
// Enter 1 to enqueue element:
// Enter 2 to dequeue element:
// Enter 3 to check isempty:
// Enter 4 to display front element:
// Enter 5 to exit:
// Enter choice: 3
// Queue is not empty. 
// Enter 1 to enqueue element:
// Enter 2 to dequeue element:
// Enter 3 to check isempty:
// Enter 4 to display front element:
// Enter 5 to exit:
// Enter choice: 2
// Dequeued element : 40
// Enter 1 to enqueue element:
// Enter 2 to dequeue element:
// Enter 3 to check isempty:
// Enter 4 to display front element:
// Enter 5 to exit:
// Enter choice: 5
// Exiting the program. 
// Queue is Empty