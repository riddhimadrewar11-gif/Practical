#include <iostream>
#include <string>
using namespace std;

#define MAX 10

class Patient {
public:
    int id;
    string name;
    int priority;

    Patient() {
        id = 0;
        name = "";
        priority = 0;
    }

    Patient(int i, string n, int p) {
        id = i;
        name = n;
        priority = p;
    }
};

class Hospital {
    Patient queue[MAX];

    int front;
    int rear;

    public:
    Hospital() {
        front = -1;
        rear = -1;
    }

    int getPriority(string level);
    void registerPatient(int id, string name, string level);
    void servePatient();
    void display();
    bool isEmpty();
    bool isFull();
};

int Hospital::getPriority(string level) {
    if (level == "Critical")
        return 3;
    else if (level == "Serious")
        return 2;
    else
        return 1;
}

void Hospital::registerPatient(int id, string name, string level) {

    if (isFull()) {
        cout << "Queue is Full" << endl;
        return;
    }

    int p = getPriority(level);

    Patient newPatient(id, name, p);

    if (isEmpty()) {
        front = 0;
        rear = 0;
    }
    else {
        rear++;
    }

    queue[rear] = newPatient;

    cout << "Patient registered successfully" << endl;
}

void Hospital::servePatient() {

    if (isEmpty()) {
        cout << "No patients waiting" << endl;
        return;
    }

    int highest = front;

    // Find highest priority patient
    for (int i = front + 1; i <= rear; i++) {

        if (queue[i].priority > queue[highest].priority) {
            highest = i;
        }
    }

    cout << "Serving Patient" << endl;
    cout << "ID: " << queue[highest].id << endl;
    cout << "Name: " << queue[highest].name << endl;
    cout << "Priority: " << queue[highest].priority << endl;

    // Shift remaining patients
    for (int i = highest; i <= rear; i++) {
        queue[i] = queue[i + 1];
    }

    rear--;

    if (rear < front) {
        front = -1;
        rear = -1;
    }
}

void Hospital::display() {

    if (isEmpty()) {
        cout << "No patients waiting" << endl;
        return;
    }

    cout << "Waiting Queue:" << endl;
    cout << "ID" <<"      "<< "Name" <<"      "<<"Priority";
    for (int i = front; i <= rear; i++) {

        cout << queue[i].id << " - ";
        cout << queue[i].name << " - ";

        if (queue[i].priority == 3)
            cout << "Critical";
        else if (queue[i].priority == 2)
            cout << "Serious";
        else
            cout << "Normal";

        cout << endl;
    }
}

bool Hospital::isEmpty() {
    return front == -1;
}

bool Hospital::isFull() {
    return rear == MAX - 1;
}

int main() {

    Hospital h;

    int choice;
    int id;
    string name;
    string level;

    do {

        cout << endl;
        cout << "1. Register Patient" << endl;
        cout << "2. Serve Patient" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Check if Queue is Empty" << endl;
        cout << "5. Check if Queue is Full" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter patient ID: ";
            cin >> id;

            cout << "Enter patient name: ";
            cin >> name;

            cout << "Enter priority (Critical/Serious/Normal): ";
            cin >> level;

            h.registerPatient(id, name, level);
            break;

        case 2:
            h.servePatient();
            break;

        case 3:
            h.display();
            break;

        case 4:
            if (h.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is not Empty" << endl;
            break;

        case 5:
            if (h.isFull())
                cout << "Queue is Full" << endl;
            else
                cout << "Queue is not Full" << endl;
            break;

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 6);

    return 0;
}