#include <iostream>
#include <string>
using namespace std;

#define MAX 10

// Stores patient details
class Patient {
public:
    string name;
    int priority;

    // Default constructor
    Patient() {
        name = "";
        priority = 0;
    }

    // Parameterized constructor
    Patient(string n, int p) {
        name = n;
        priority = p;
    }
};

class Hospital {
    Patient queue[MAX];
    int size;

public:
    Hospital() {
        size = 0;
    }

    int getPriority(string level);
    void registerPatient(string name, string level);
    void servePatient();
    void display();
    bool isEmpty();
    bool isFull();
};

// Assigns priority value
int Hospital::getPriority(string level) {
    if (level == "Critical")
        return 3;
    else if (level == "Serious")
        return 2;
    else
        return 1;
}

// Adds patient according to priority
void Hospital::registerPatient(string name, string level) {
    if (isFull()) {
        cout << "Queue is Full" << endl;
        return;
    }

    int p = getPriority(level);

    Patient newPatient(name, p);

    int i = size - 1;

    // Shift lower priority patients
    while (i >= 0 && queue[i].priority < newPatient.priority) {
        queue[i + 1] = queue[i];
        i--;
    }

    queue[i + 1] = newPatient;
    size++;

    cout << "Patient registered successfully" << endl;
}

// Serves highest priority patient
void Hospital::servePatient() {
    if (isEmpty()) {
        cout << "No patients waiting" << endl;
        return;
    }

    cout << "Serving patient: " << queue[0].name << endl;

    // Shift remaining patients
    for (int i = 0; i < size - 1; i++) {
        queue[i] = queue[i + 1];
    }

    size--;
}

// Displays waiting queue
void Hospital::display() {
    if (isEmpty()) {
        cout << "No patients waiting" << endl;
        return;
    }

    cout << "Waiting Queue:" << endl;

    for (int i = 0; i < size; i++) {
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

// Checks if queue is empty
bool Hospital::isEmpty() {
    return size == 0;
}

// Checks if queue is full
bool Hospital::isFull() {
    return size == MAX;
}

int main() {
    Hospital h;

    int choice;
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
            cout << "Enter patient name: ";
            cin >> name;

            cout << "Enter priority (Critical/Serious/Normal): ";
            cin >> level;

            h.registerPatient(name, level);
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


// Output

// 1. Register Patient
// 2. Serve Patient
// 3. Display Queue
// 4. Check if Queue is Empty
// 5. Check if Queue is Full
// 6. Exit
// Enter your choice: 1
// Enter patient name: Riddhi
// Enter priority (Critical/Serious/Normal): Normal
// Patient registered successfully

// 1. Register Patient
// 2. Serve Patient
// 3. Display Queue
// 4. Check if Queue is Empty
// 5. Check if Queue is Full
// 6. Exit
// Enter your choice: 1
// Enter patient name: Sakshi
// Enter priority (Critical/Serious/Normal): Critical
// Patient registered successfully

// 1. Register Patient
// 2. Serve Patient
// 3. Display Queue
// 4. Check if Queue is Empty
// 5. Check if Queue is Full
// 6. Exit
// Enter your choice: 1
// Enter patient name: Sneha
// Enter priority (Critical/Serious/Normal): Serious
// Patient registered successfully

// 1. Register Patient
// 2. Serve Patient
// 3. Display Queue
// 4. Check if Queue is Empty
// 5. Check if Queue is Full
// 6. Exit
// Enter your choice: 1
// Enter patient name: Priya
// Enter priority (Critical/Serious/Normal): Critical
// Patient registered successfully

// 1. Register Patient
// 2. Serve Patient
// 3. Display Queue
// 4. Check if Queue is Empty
// 5. Check if Queue is Full
// 6. Exit
// Enter your choice: 3
// Waiting Queue:
// Sakshi - Critical
// Priya - Critical
// Sneha - Serious
// Riddhi - Normal

// 1. Register Patient
// 2. Serve Patient
// 3. Display Queue
// 4. Check if Queue is Empty
// 5. Check if Queue is Full
// 6. Exit
// Enter your choice: 2
// Serving patient: Sakshi

// 1. Register Patient
// 2. Serve Patient
// 3. Display Queue
// 4. Check if Queue is Empty
// 5. Check if Queue is Full
// 6. Exit
// Enter your choice: 3
// Waiting Queue:
// Priya - Critical
// Sneha - Serious
// Riddhi - Normal

// 1. Register Patient
// 2. Serve Patient
// 3. Display Queue
// 4. Check if Queue is Empty
// 5. Check if Queue is Full
// 6. Exit
// Enter your choice: 4
// Queue is not Empty

// 1. Register Patient
// 2. Serve Patient
// 3. Display Queue
// 4. Check if Queue is Empty
// 5. Check if Queue is Full
// 6. Exit
// Enter your choice: 5
// Queue is not Full

// 1. Register Patient
// 2. Serve Patient
// 3. Display Queue
// 4. Check if Queue is Empty
// 5. Check if Queue is Full
// 6. Exit
// Enter your choice: 6
// Exiting...